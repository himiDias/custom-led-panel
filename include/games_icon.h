#ifndef ICON_GAMES_H
#define ICON_GAMES_H

#include "led-matrix.h"
#include "graphics.h"

#include "icon_elem.h"

#include <string>

namespace desk_led{
	class IconGames : public IconElement{
		public:
		
		IconGames(int x_lower, int x_upper, int y_lower, int y_upper);
		
		void drawIcon(rgb_matrix::FrameCanvas* canvas) override;
		
		
	};
}

#endif
