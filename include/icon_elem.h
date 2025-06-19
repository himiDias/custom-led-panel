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
		
		virtual void drawIcon(rgb_matrix::FrameCanvas* canvas) const;
		
		void setSelected();
		
		void setDeselected();
		
		protected:
		bool selected = false;
		
		
	};
}

#endif
