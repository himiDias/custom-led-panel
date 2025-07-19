// rpi-rgb-led-matrix headers
#include "led-matrix.h"
#include "graphics.h"

//json
#include "json.hpp"

// custom
#include "panel.h"
#include "status_elem.h"
#include "time_elem.h"
#include "main_elem.h"

#include "paint_elem.h"

#include "thread_safe_queue.h"

// standard
#include <unistd.h>
#include <iostream>
#include <string>

using namespace rgb_matrix;
using json = nlohmann::json;

namespace desk_led{
	
StatusElement Panel::status_e(0,63,0,10);
MainElement Panel::main_e(0,63,10,53);
TimeElement Panel::time_e(0,63,53,63);

ThreadSafeQ<std::string>* server_commands_queue;

FrameCanvas* canvas_main;
FrameCanvas* canvas_paint;


	int Panel::run_panel(ThreadSafeQ<std::string>& led_cmds_queue,ThreadSafeQ<std::string>& server_cmds_queue){
		
		server_commands_queue = &server_cmds_queue;
		
		RGBMatrix::Options options;
		options.rows = 64;
		options.cols = 64;
		options.chain_length = 1;
		options.parallel = 1;
		options.hardware_mapping = "adafruit-hat";
		
		//Debugging options, comment/disable before finish
		options.show_refresh_rate = true;
		options.brightness = 50;
		
		RuntimeOptions runtime_options;
		RGBMatrix *matrix = CreateMatrixFromOptions(options,runtime_options);
		
		canvas_main = matrix->CreateFrameCanvas();
		canvas_paint = matrix->CreateFrameCanvas();
		
		
		FrameCanvas **current_canvas = &canvas_main;
		
		//setting up main canvas
		status_e.drawBorders(canvas_main);
		status_e.scrollText(canvas_main);
			
		time_e.drawBorders(canvas_main);
		time_e.drawTime(canvas_main);
			
		main_e.drawBorders(canvas_main);
		main_e.drawOptions(canvas_main);
		
		/*
		StatusElement status_e(0,63,0,10);
		 
		
		MainElement main_e(0,63,10,53);
		 
		
		TimeElement time_e(0,63,53,63);*/
	
		//canvas = matrix -> SwapOnVSync(canvas);
		
		
		// NOTE: FLICKERING IS DUE TO BUFFER FRAMES, FIX BY REDRAWING BORDERS ON BOTH FRAMES, OR REDRAW BORDERS EACH ITERATION (2nd is integrated, not as efficient, change later)
		
		PaintElement paint_e(0,63,0,63);
		
		//int counter = 0;
		while (true){
			
			usleep(50000);
			
			//check which screen/canvas is currently being displayed
			if (*current_canvas == canvas_main){
				status_e.drawBorders(canvas_main);
				status_e.scrollText(canvas_main);
				
				time_e.drawBorders(canvas_main);
				time_e.drawTime(canvas_main);
				
				main_e.drawBorders(canvas_main);
				main_e.drawOptions(canvas_main);
			}else if (*current_canvas == canvas_paint){
				paint_e.drawBorders(canvas_paint);
				paint_e.clearContents(canvas_paint);
			}
			*current_canvas = matrix -> SwapOnVSync(*current_canvas);
			
			//remove from qyeye, do stuff here
			auto usr_inp = led_cmds_queue.nonBlockPop();
			if (usr_inp){
				std::string usr_inp_str;
				usr_inp_str = usr_inp.value();
				process_input(usr_inp_str,current_canvas);
			}
		}
		
		std::cout << "Matrix cleared, Exiting," << std::endl;
		
		
		sleep(50);
		delete matrix;
		return 0;
	}
	
	void Panel::process_input(std::string input,rgb_matrix::FrameCanvas**& canvas_ptr){
		
		json input_data = json::parse(input);
		
		std::string type = input_data["type"];
		if (type == "action"){
			std::string cmd = input_data["id"];
			int sep_val = cmd.find('-');
			if(cmd.substr(0,sep_val) == "dpad") {
				main_e.changeSelected(cmd[sep_val+1]);
			}
			else if(cmd.substr(sep_val+1,1) == "a"){
				std::string ret_cmd = main_e.getSelected();
				if (ret_cmd != ""){
					server_commands_queue->push(ret_cmd);
					if (ret_cmd == "{'switch_screen':'paint'}"){
						 canvas_ptr = &canvas_paint;
					}
				}
			}
		}else if (type == "submit-settings"){
			status_e.setMessage(input_data["status"]);
			time_e.showTime(input_data["time"]);
			time_e.showDate(input_data["date"]);
			server_commands_queue->push("{'switch_screen':'main'}");
			
		}else if (type == "cancel-settings"){
			server_commands_queue->push("{'switch_screen':'main'}");
		}
	}
}
