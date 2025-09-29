#ifndef ICON_ELEMENT_H
#define ICON_ELEMENT_H

#include "led-matrix.h"
#include "graphics.h"

#include "panel_element.h"

#include <string>

namespace desk_led{
	class IconElement : public PanelElement{
		public:
		
		IconElement(int x_lower, int x_upper, int y_lower, int y_upper);
		
		virtual void drawIcon(rgb_matrix::FrameCanvas* canvas);
		
		void setSelected();
		
		void setDeselected();
		
		
		protected:
		bool selected = false;
		
		rgb_matrix::Color standardColor = rgb_matrix::Color(255,255,255);
		rgb_matrix::Color selectedColor = rgb_matrix::Color(73,227,212);
		rgb_matrix::Color* currentColor;
		
		
	};
}

#endif
