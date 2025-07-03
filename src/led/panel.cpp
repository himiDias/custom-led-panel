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

	int Panel::run_panel(ThreadSafeQ<std::string>& shared_queue){
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
			auto usr_inp = shared_queue.nonBlockPop();
			if (usr_inp){
				std::string usr_inp_str;
				usr_inp_str = usr_inp.value();
				process_input(usr_inp_str);
			}
		}
		
		std::cout << "Matrix cleared, Exiting," << std::endl;
		
		
		sleep(50);
		delete matrix;
		return 0;
	}
	
	void Panel::process_input(std::string input){
		if(input.substr(0,4) == "dpad") {
			//char* comm = (input.substr(5,6)).c_str()
			main_e.changeSelected(input[5]);
		}
	}
}
