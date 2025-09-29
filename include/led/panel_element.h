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
		
		// Draws in artificial boundary for element 
		void drawBorders(rgb_matrix::FrameCanvas* canvas) const;
		
		// Clear content within the bounds of the element  
		void clearContents(rgb_matrix::FrameCanvas* canvas) const;
		
		//Clears all area including borders
		void clear(rgb_matrix::FrameCanvas* canvas) const;
		
		// Checks canvas
		bool check_canvas_null(rgb_matrix::FrameCanvas* canvas) const;
		
		
		
		
		protected:
		int x_l;
		int x_u;
		int y_l;
		int y_u;
		
		
	};
	
}

#endif
