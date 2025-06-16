#include "graphics.h"
#include "led-matrix.h"

#include "status_elem.h"

#include "iostream"

namespace desk_led{
	StatusElement::StatusElement(int x_lower, int x_upper, int y_lower, int y_upper)
	:PanelElement(x_lower,x_upper,y_lower,y_upper)
	{
		if (!message_font.LoadFont(font_path)){
			std::cerr << "Error, could not load font\n";
			return;
		}
	}
	
	void StatusElement::scrollText(rgb_matrix::FrameCanvas* canvas){
		clearContents(canvas);
		// gen formular for centering
		int y_pos = y_u-(y_u-y_l)/4;
		
		rgb_matrix::DrawText(canvas,message_font,x_l+1 - x_offset,y_pos,message_colour,nullptr,message.c_str());
		if(x_offset == message_width){
			x_offset = -x_u;
		}
		else{
			x_offset++;
		}
		
	}
	
	void StatusElement::setMessage(std::string newMessage){
		message = newMessage;
		message_width = 6 * message.length();
		x_offset = 0;
	}
	
	void StatusElement::setMessageColour(rgb_matrix::Color newColour){
		message_colour = newColour;
	}
		
		
		
		 
	
}
	
	
