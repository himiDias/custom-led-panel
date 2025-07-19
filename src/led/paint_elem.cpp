#include "led-matrix.h"
#include "graphics.h"

#include "panel_element.h"
#include "paint_elem.h"


namespace desk_led{
	PaintElement::PaintElement(int x_lower, int x_upper, int y_lower, int y_upper)
	:PanelElement(x_lower,x_upper,y_lower,y_upper)
	{
		
	}
	
	void PaintElement::setPixel(int x_pos, int y_pos, rgb_matrix::Color colour, rgb_matrix::FrameCanvas* canvas){
		canvas->SetPixel(x_pos,y_pos,colour.r,colour.g,colour.b);
	}
	
	void PaintElement::clearPixel(int x_pos, int y_pos, rgb_matrix::FrameCanvas* canvas){
		canvas->SetPixel(x_pos,y_pos,0,0,0);
		
	}
	
	
	
}
