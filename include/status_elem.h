#ifndef PANEL_ELEMENT_H
#define PANEL_ELEMENT_H

#include "led-matrix.h"
#include "graphics.h"
#include "panel_element.h"

namespace desk_led{
	
	class StatusElement : public PanelElement {
		public:
		
		StatusElement(int x_lower, int x_upper, int y_lower, int y_upper);
		
		void draw(rgb_matrix::FrameCanvas* canvas) const override;
		
		
		
