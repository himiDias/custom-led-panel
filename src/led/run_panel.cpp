// rpi-rgb-led-matrix headers
#include "led-matrix.h"
#include "graphics.h"

// custom
#include "status_elem.h"
#include "time_elem.h"

// standard
#include <unistd.h>
#include <iostream>

using namespace rgb_matrix;
using namespace desk_led;

int main(){
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
	StatusElement test(0,43,0,10);
	test.drawBorders(canvas);
	test.scrollText(canvas);
	
	TimeElement test_time(43,63,0,10);
	test_time.drawBorders(canvas);
	test_time.drawTime(canvas);
	
	//canvas->SetPixel(5,5,255,0,0);
	canvas = matrix -> SwapOnVSync(canvas);
	
	
	// NOTE: FLICKERING IS DUE TO BUFFER FRAMES, FIX BY REDRAWING BORDERS ON BOTH FRAMES, OR REDRAW BORDERS EACH ITERATION
	
	
	int counter = 0;
	while (true){
		
		usleep(50000);
		counter++;
		test_time.drawTime(canvas);
		//test.scrollText(canvas);
		//test.drawBorders(canvas);
		canvas = matrix -> SwapOnVSync(canvas);
		if (counter == 200){
			//std::string nm= "Testing changing text";
			rgb_matrix::Color newC= rgb_matrix::Color(255,0,0); 
			//test.setMessage(nm);
			//test.setMessageColour(newC);
			test_time.showDate();
		}
	}
	
	std::cout << "Matrix cleared, Exiting," << std::endl;
	
	
	sleep(50);
	delete matrix;
	return 0;
}
