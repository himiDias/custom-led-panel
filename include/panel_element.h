#ifndef PANEL_ELEMENT_H
#define PANEL_ELEMENT_H

#include "led-matrix.h"
#include "graphics.h"


// Class for elements displayed onto panel, each object is bounded by artificial boundaries within the dimensions of the panel

namespace desk_led{
	
	class PanelElement{
		public:
		
		
		//takes in upper and lower bounds for x and y directions 
		PanelElement(int x_lower, int x_upper, int y_lower, int y_upper);
		
		virtual ~PanelElement() = default;
		
		// Draws in artificial boundary for element (NOTE to slef, WHY IS THIS VIRTUAL, is gonna be same for all)
		virtual void drawBorders(rgb_matrix::FrameCanvas* canvas) const = 0;
		
		//Clears all area including borders
		void clear(rgb_matrix::FrameCanvas* canvas) const;
		
		//Clears only content within borders (NOTE to sletf, WHY IS THIS VIRTUAL, is gonna be same for all)
		virtual void clearContents(rgb_matrix::FrameCanvas* canvas) const = 0;
		
		
		
		
		protected:
		int x_l;
		int x_u;
		int y_l;
		int y_u;
		
		
		bool check_canvas_null(rgb_matrix::FrameCanvas* canvas) const;
	};
	
}

#endif
