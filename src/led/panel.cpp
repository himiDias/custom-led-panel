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
		
		//arbitrary values for x,y boudns
		StatusElement test(0,63,0,10);
		 
		
		MainElement test_main(0,63,10,53);
		 
		
		TimeElement test_time(0,63,53,63);
		 
		//canvas = matrix -> SwapOnVSync(canvas);
		
		
		// NOTE: FLICKERING IS DUE TO BUFFER FRAMES, FIX BY REDRAWING BORDERS ON BOTH FRAMES, OR REDRAW BORDERS EACH ITERATION (2nd is integrated, not as efficient, change later)
		
		
		//int counter = 0;
		while (true){
			
			usleep(50000);
			//counter++;
			test.drawBorders(canvas);
			test.scrollText(canvas);
			
			test_time.drawBorders(canvas);
			test_time.drawTime(canvas);
			
			test_main.drawBorders(canvas);
			test_main.drawOptions(canvas);
			
			canvas = matrix -> SwapOnVSync(canvas);
			
			//remove from qyeye, do stuff here
			auto usr_inp = shared_queue.nonBlockPop();
			
			/*
			if (counter == 1000){
				test_time.showDate(true);
				std::cout << "Deleted option\n";
				test_main.deleteOptions();
				break;
			}*/
		}
		
		std::cout << "Matrix cleared, Exiting," << std::endl;
		
		
		sleep(50);
		delete matrix;
		return 0;
	}
}
