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

//menu elements	
StatusElement Panel::status_e(0,63,0,10);
MainElement Panel::main_e(0,63,10,53);
TimeElement Panel::time_e(0,63,53,63);

//paint element
PaintElement Panel::paint_e(0,63,0,63);

ThreadSafeQ<std::string>* server_commands_queue;

SceneState Panel::scene = SCENE_MENU;
bool on_scene_switch = true;


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
		
		FrameCanvas* canvas= matrix->CreateFrameCanvas();
		

		while (true){
			
			usleep(50000);
			
			switch (scene){
				case SCENE_MENU:
					if (on_scene_switch){
						canvas->Clear();
						
						//status_e.drawBorders(canvas);
						main_e.drawBorders(canvas);
						time_e.drawBorders(canvas);
						
						//reset back buffer as well
						canvas = matrix -> SwapOnVSync(canvas);
						canvas->Clear();
						main_e.drawBorders(canvas);
						time_e.drawBorders(canvas);
						
						on_scene_switch = false;
						
					}
					status_e.drawBorders(canvas);
					status_e.scrollText(canvas);
					
					time_e.drawTime(canvas);
				 
					main_e.drawOptions(canvas);
					
					break;
				case SCENE_PAINT:
					if (on_scene_switch){
						canvas->Clear();
						paint_e.drawBorders(canvas);
						
						//reset back buffer as well
						canvas = matrix -> SwapOnVSync(canvas);
						canvas->Clear();
						paint_e.drawBorders(canvas);
						
						on_scene_switch = false;
					}
					break;
				default:
					break;
			}

			canvas = matrix -> SwapOnVSync(canvas);
			
			//remove from qyeye, do stuff here
			auto usr_inp = led_cmds_queue.nonBlockPop();
			if (usr_inp){
				std::string usr_inp_str;
				usr_inp_str = usr_inp.value();
				process_input(usr_inp_str,canvas);
			}
		}
		
		std::cout << "Matrix cleared, Exiting," << std::endl;
		
		
		sleep(50);
		delete matrix;
		return 0;
	}
	
	void Panel::process_input(std::string input,rgb_matrix::FrameCanvas* canvas){
		
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
						 scene = SCENE_PAINT;
						 on_scene_switch = true;
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
		}else if (type == "setpixel-paint"){
			std::string colour = input_data["colour"];
			
			std::string r_hex = colour.substr(1,2);
			std::string g_hex = colour.substr(3,2);
			std::string b_hex = colour.substr(5,2);
			
			int r = std::stoi(r_hex,0,16);
			int g = std::stoi(g_hex,0,16);
			int b = std::stoi(b_hex,0,16);
			
			int x = ((int)input_data["x"])+1;
			int y = ((int)input_data["y"])+1;
			//rgb_matrix::Color colour = rgb_matrix::Color();
			paint_e.setPixel(x,y,rgb_matrix::Color(r,g,b),canvas);
			//insert code for extracting coordincated and colour, then sert pixel
		}else if (type == "clearpixel-paint"){
			//insert code for getting coordinates then clear pixel
		}
	}
}
