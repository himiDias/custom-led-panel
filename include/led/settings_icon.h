#ifndef ICON_SETTINGS_H
#define ICON_SETTINGS_H

#include "led-matrix.h"
#include "graphics.h"

#include "icon_elem.h"

#include <string>

namespace desk_led{
	class IconSettings : public IconElement{
		public:
		
		IconSettings(int x_lower, int x_upper, int y_lower, int y_upper);
		
		void drawIcon(rgb_matrix::FrameCanvas* canvas) override;
		
		
	};
}

#endif
