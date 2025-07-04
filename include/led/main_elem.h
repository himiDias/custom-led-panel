#ifndef MAIN_ELEMENT_H
#define MAIN_ELEMENT_H

#include "led-matrix.h"
#include "graphics.h"

#include "panel_element.h"
#include "icon_elem.h"

#include <string>
#include <vector>

namespace desk_led{
	class MainElement : public PanelElement {
		public:
		
		MainElement(int x_lower, int x_upper, int y_lower, int y_upper);
		
		void drawOptions(rgb_matrix::FrameCanvas* canvas) const;
		
		void drawSelected(rgb_matrix::FrameCanvas* canvas) const;
		
		//currently using this to free memory, CONSIDER smart pointers
		void deleteOptions();
		
		void changeSelected(char inp);
		
		
		private:

		std::vector<IconElement*> options;
		IconElement* selected = nullptr;
		int indexSelected = 0;
		
	};
	
}

#endif
