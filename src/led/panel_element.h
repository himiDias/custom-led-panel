#ifndef PANEL_ELEMENT_H
#define PANEL_ELEMENT_H

#include "led-matrix.h"
#include "graphics.h"

namespace desk_led{
	
	class PanelElement{
		public:
		
		
		
		PanelElement(int x_lower, int x_upper, int y_lower, int y_upper);
		
		virtual ~PanelElement() = default;
		
		virtual void draw(rgb_matrix::FrameCanvas* canvas) const = 0;
		
		void clear(rgb_matrix::FrameCanvas* canvas) const;
		
		
		private:
		int x_l;
		int x_u;
		int y_l;
		int y_u;
	};
	
}

#endif
