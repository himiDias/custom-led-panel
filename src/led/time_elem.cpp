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
			
		if (!time_font.LoadFont(font_path)){
			std::cerr << "Error, could not load font\n";
			return;
		}
		
	}
	
	// Date_message not used currently, no space with current plan to display ( add later, allow to set in settings)
	void TimeElement::updateTime(){
		current_time = time(nullptr);
		local_time = localtime(&current_time);
		
		
		time_message = std::to_string(local_time->tm_hour) + ":" + std::to_string(local_time->tm_min);
		date_message = std::to_string(local_time->tm_mday) + "/" + std::to_string(local_time->tm_mon + 1) + "/" + std::to_string(1900 + local_time->tm_year);
	}
	
	void TimeElement::drawTime(rgb_matrix::FrameCanvas* canvas){
		clearContents(canvas);
		updateTime();
		
		if (display_time && display_date){
			display_message = time_message + " " + date_message;
		}else if(display_time){
			display_message = time_message;
		}else{
			display_message = date_message;
		}
		
		int y_pos = y_u-(y_u-y_l)/4;
		rgb_matrix::DrawText(canvas,time_font,x_l+1,y_pos,time_colour,nullptr,display_message.c_str());
	}
	
	void TimeElement::showTime(bool value){
		display_time = value;
	}
	
	void TimeElement::showDate(bool value){
		display_date = value;
	}
	
	void TimeElement::setTimeColour(rgb_matrix::Color newColour){
		time_colour = newColour;
	}
}
