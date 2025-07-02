#ifndef STATUS_ELEMENT_H
#define STATUS_ELEMENT_H

#include "led-matrix.h"
#include "graphics.h"

#include "panel_element.h"

#include <string>

namespace desk_led{
	
	class StatusElement : public PanelElement {
		public:
		
		StatusElement(int x_lower, int x_upper, int y_lower, int y_upper);
		
		// Method to draw text onto panel, also scrolls by incrementing/resetting an offset each time method is called
		void scrollText(rgb_matrix::FrameCanvas* canvas);
		
		// Change status message
		void setMessage(std::string newMessage);
		//CHange font colour
		void setMessageColour(rgb_matrix::Color newColour);
		
		private:
		std::string message = "Set Status Message";
		
		rgb_matrix::Color message_colour = rgb_matrix::Color(255,255,255);
		rgb_matrix::Font message_font;
		
		const char* font_path = "lib/rpi-rgb-led-matrix/fonts/6x10.bdf";
		int x_offset =0;
		int message_width = 6 * message.length();;
		
	};
	
}
		
		
		
#endif
