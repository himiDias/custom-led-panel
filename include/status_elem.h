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
		
		void drawBorders(rgb_matrix::FrameCanvas* canvas) const override;
		
		void scrollText(rgb_matrix::FrameCanvas* canvas) const;
		
		void clearContents(rgb_matrix::FrameCanvas* canvas) const;
		
		private:
		mutable std::string message;
		mutable rgb_matrix::Color message_color;
		rgb_matrix::Font message_font;
		mutable int x_offset;
		mutable int message_width;
		
	};
	
}
		
		
		
#endif
