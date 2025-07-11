// rpi-rgb-led-matrix headers
#include "led-matrix.h"
#include "graphics.h"

// custom
#include "panel.h"
#include "status_elem.h"
#include "time_elem.h"
#include "main_elem.h"

#include "thread_safe_queue.h"

// standard
#include <unistd.h>
#include <iostream>
#include <string>

using namespace rgb_matrix;

namespace desk_led{
	
StatusElement Panel::status_e(0,63,0,10);
MainElement Panel::main_e(0,63,10,53);
TimeElement Panel::time_e(0,63,53,63);

ThreadSafeQ<std::string>* server_commands_queue;


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
		
		FrameCanvas *canvas = matrix->CreateFrameCanvas();
		
		
		/*
		StatusElement status_e(0,63,0,10);
		 
		
		MainElement main_e(0,63,10,53);
		 
		
		TimeElement time_e(0,63,53,63);*/
	
		//canvas = matrix -> SwapOnVSync(canvas);
		
		
		// NOTE: FLICKERING IS DUE TO BUFFER FRAMES, FIX BY REDRAWING BORDERS ON BOTH FRAMES, OR REDRAW BORDERS EACH ITERATION (2nd is integrated, not as efficient, change later)
		
		
		//int counter = 0;
		while (true){
			
			usleep(50000);
			//counter++;
			status_e.drawBorders(canvas);
			status_e.scrollText(canvas);
			
			time_e.drawBorders(canvas);
			time_e.drawTime(canvas);
			
			main_e.drawBorders(canvas);
			main_e.drawOptions(canvas);
			
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
		int sep_key = input.find(':') +2;
		int sep_val = input.find('-');
		if(input.substr(sep_key,sep_val-sep_key) == "dpad") {
			main_e.changeSelected(input[sep_val+1]);
		}
		else if(input.substr(sep_val+1,1) == "a"){
			main_e.drawSelected(canvas);
		}
	}
}
