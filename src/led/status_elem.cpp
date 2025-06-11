#include "graphics.h"
#include "led-matrix.h"

#include "status_elem.h"

#include "iostream"

namespace desk_led{
	StatusElement::StatusElement(int x_lower, int x_upper, int y_lower, int y_upper)
	:PanelElement(x_lower,x_upper,y_lower,y_upper)
	{
		StatusElement::message = "Set Status Message";
		StatusElement::message_color = rgb_matrix::Color(255,255,255);
		StatusElement::x_offset = 0;
		
		const char* font_path = "lib/rpi-rgb-led-matrix/fonts/6x10.bdf";
		
		if (!StatusElement::message_font.LoadFont(font_path)){
			std::cerr << "Error, could not load font\n";
			return;
		}
		
		//replace with message_font.CharacterWidth, uses arbitraty '6'
		StatusElement::message_width = 6 * message.length();
	}
	
	void StatusElement::clearContents(rgb_matrix::FrameCanvas* canvas) const{
		if (check_canvas_null(canvas)){
			return;
		}
		
		for (int x=x_l+1;x<x_u;++x){
			for (int y=y_l+1;y<y_u;++y){
				canvas->SetPixel(x,y,0,0,0);
			}
		}
	}
		
		
		
	
	void StatusElement::drawBorders(rgb_matrix::FrameCanvas* canvas) const{
		if (PanelElement::check_canvas_null(canvas)){
			return;
		}
		
		//draw border
		for (int x=x_l;x<=x_u;++x){
			canvas->SetPixel(x,y_l,255,255,255);
			canvas->SetPixel(x,y_u,255,255,255);
		}
		
		for (int y=y_l;y<y_u;++y){
			canvas->SetPixel(x_l,y,255,255,255);
			canvas->SetPixel(x_u,y,255,255,255);
		}
		
		
		
	}
	
	void StatusElement::scrollText(rgb_matrix::FrameCanvas* canvas) const{
		StatusElement::clearContents(canvas);
		// gen formular for centering
		int y_pos = y_u-(y_u-y_l)/4;
		rgb_matrix::DrawText(canvas,message_font,x_l+1 - x_offset,y_pos,message_color,nullptr,message.c_str());
		if(x_offset == message_width){
			x_offset = -x_u;
		}
		else{
			x_offset++;
		}
		
	}
		
		
		
		 
	
}
	
	
