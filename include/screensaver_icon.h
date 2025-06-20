#ifndef ICON_SS_H
#define ICON_SS_H

#include "led-matrix.h"
#include "graphics.h"

#include "icon_elem.h"

#include <string>

namespace desk_led{
	class IconSS : public IconElement{
		public:
		
		IconSS(int x_lower, int x_upper, int y_lower, int y_upper);
		
		void drawIcon(rgb_matrix::FrameCanvas* canvas) override;
		
		
	};
}

#endif
