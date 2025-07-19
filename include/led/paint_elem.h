#ifndef PAINT_ELEM_H
#define PAINT_ELEM_H

#include "led-matrix.h"
#include "graphics.h"

#include "panel_element.h"

namespace desk_led{
	
	class PaintElement : public PanelElement{
		
		public:
		
		PaintElement(int x_lower, int x_upper, int y_lower, int y_upper);
		
		void setPixel(int x_pos, int y_pos, rgb_matrix::Color colour, rgb_matrix::FrameCanvas* canvas);
		
		void clearPixel(int x_pos, int y_pos, rgb_matrix::FrameCanvas* canvas);
		
	};
	
	
}


#endif
