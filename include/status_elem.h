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
		// REMINER, remove and use default in parents
		void drawBorders(rgb_matrix::FrameCanvas* canvas) const override;
		
		// Method to draw text onto panel, also scrolls by incrementing/resetting an offset each time method is called
		void scrollText(rgb_matrix::FrameCanvas* canvas);
		// Clear content within the bounds of the element (NOTE, Could be removed and set as default in parent)
		void clearContents(rgb_matrix::FrameCanvas* canvas) const;
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
