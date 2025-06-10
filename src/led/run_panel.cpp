// rpi-rgb-led-matrix headers
#include "led-matrix.h"
#include "graphics.h"

// custom
#include "status_elem.h"

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
	
	StatusElement test(0,43,0,15);
	test.draw(canvas);
	
	//canvas->SetPixel(5,5,255,0,0);
	canvas = matrix -> SwapOnVSync(canvas);
	std::cout << "Matrix cleared, Exiting," << std::endl;
	
	
	sleep(2);
	delete matrix;
	return 0;
}
