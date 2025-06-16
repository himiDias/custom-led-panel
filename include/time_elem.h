#ifndef TIME_ELEMENT_H
#define TIME_ELEMENT_H

#include "led-matrix.h"
#include "graphics.h"

#include "panel_element.h"

#include <string>
#include <ctime>

//Should use the RTC embedded into HAT, no cell battery so for now USING C LIB INSTEAD, CHANGE LATER WHEN CELL ACQUIRED
namespace desk_led{
	
	class TimeElement : public PanelElement {
		public:
		
		TimeElement(int x_lower, int x_upper, int y_lower, int y_upper);
		
		// updates time/date messages
		void updateTime();
		
		// method to draw time, also updates and draws
		void drawTime(rgb_matrix::FrameCanvas* canvas);
		
		// Used to set whether to show time or not
		void showTime(bool value);
		
		//used to set whether to show date or not
		void showDate(bool value);
		
		// set font colour
		void setTimeColour(rgb_matrix::Color newColour);
		
		
		private:
		rgb_matrix::Font time_font;
		rgb_matrix::Color time_colour = rgb_matrix::Color(255,255,255);
	
		std::time_t current_time;
		std::tm* local_time;
		std::string time_message = "Set time";
		std::string date_message = "Set date";
		std::string display_message = time_message + date_message;
		
		const char* s_font_path = "lib/rpi-rgb-led-matrix/fonts/4x6.bdf";
		const char* l_font_path = "lib/rpi-rgb-led-matrix/fonts/6x10.bdf";
		bool display_time = true;
		bool display_date = true;
		
	};
	
}
		
		
		
#endif
