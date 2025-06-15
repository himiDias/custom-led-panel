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
		std::string message;
		rgb_matrix::Color message_colour;
		rgb_matrix::Font message_font;
		int x_offset;
		int message_width;
		
	};
	
}
		
		
		
#endif
