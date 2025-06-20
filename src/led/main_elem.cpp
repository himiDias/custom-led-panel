#include "led-matrix.h"
#include "graphics.h"

#include "main_elem.h"
#include "settings_icon.h"
#include "display_icon.h"
#include "games_icon.h"
#include "screensaver_icon.h"

#include <vector>

namespace desk_led{
	MainElement::MainElement(int x_lower, int x_upper, int y_lower, int y_upper)
	:PanelElement(x_lower,x_upper,y_lower,y_upper)
	{
		//test with 4 of the same
		options.push_back(new IconSettings(x_lower,x_upper/2,y_lower,y_lower + (y_upper-y_lower)/2));
		options.push_back(new IconGames(x_lower,x_upper/2,y_lower + (y_upper-y_lower)/2,y_upper));
		options.push_back(new IconDisplay(x_upper/2,x_upper,y_lower,y_lower + (y_upper-y_lower)/2));
		options.push_back(new IconSS(x_upper/2,x_upper,y_lower + (y_upper-y_lower)/2,y_upper));
	}
	
	void MainElement::drawOptions(rgb_matrix::FrameCanvas* canvas) const{
		for (IconElement* i : options){
			i->drawIcon(canvas);
		}
	}
	
	void MainElement::deleteOptions(){
		for (IconElement* i : options){
			delete i;
		}
	}
	
	void MainElement::drawSelected(rgb_matrix::FrameCanvas* canvas) const{
		
	}
	
}
