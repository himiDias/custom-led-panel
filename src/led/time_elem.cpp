#include "graphics.h"
#include "led-matrix.h"

#include "time_elem.h"

#include <iostream>
#include <ctime>
#include <string>

namespace desk_led{
	TimeElement::TimeElement(int x_lower, int x_upper, int y_lower, int y_upper)
	:PanelElement(x_lower,x_upper,y_lower,y_upper)
	{
			
		if (!message_font.LoadFont(s_font_path)){
			std::cerr << "Error, could not load font\n";
			return;
		}
		
	}
	
	//
	void TimeElement::updateTime(){
		current_time = time(nullptr);
		local_time = localtime(&current_time);
		
		
		time_message = std::to_string(local_time->tm_hour) + ":" + (local_time->tm_min < 10 ? "0" + std::to_string(local_time->tm_min) : std::to_string(local_time->tm_min));
		date_message = std::to_string(local_time->tm_mday) + "/" + std::to_string(local_time->tm_mon + 1) + "/" + std::to_string(1900 + local_time->tm_year);
	}
	
	void TimeElement::drawTime(rgb_matrix::FrameCanvas* canvas){
		clearContents(canvas);
		updateTime();
		int width;
		if (display_time && display_date){
			if (!message_font.LoadFont(s_font_path)){
				std::cerr << "Error, could not load font\n";
				return;
			}
			display_message = time_message + " " + date_message;
			width = display_message.length() * 4;
		}else{
			if (!message_font.LoadFont(l_font_path)){
				std::cerr << "Error, could not load font\n";
				return;
			}
			if(display_time){
				display_message = time_message;
			}else{
				display_message = date_message;
			}
			width = display_message.length() * 6;
		}
		
		//centering y and x direction
		int y_pos = y_u-(y_u-y_l)/4;
		
		//centetrs using message widtrh
		int x_pos = (x_u-x_l)/2 - (width/2)+1;
		
		rgb_matrix::DrawText(canvas,message_font,x_pos,y_pos,message_colour,nullptr,display_message.c_str());
	}
	
	void TimeElement::showTime(bool value){
		display_time = value;
	}
	
	void TimeElement::showDate(bool value){
		display_date = value;
	}
	
	void TimeElement::setTimeColour(rgb_matrix::Color newColour){
		message_colour = newColour;
	}
}
