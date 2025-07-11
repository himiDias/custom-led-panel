#include "led-matrix.h"
#include "graphics.h"

#include "main_elem.h"
#include "settings_icon.h"
#include "display_icon.h"
#include "games_icon.h"
#include "screensaver_icon.h"

#include <vector>
#include <iostream>
#include <string>
#include <typeinfo>

namespace desk_led{
	MainElement::MainElement(int x_lower, int x_upper, int y_lower, int y_upper)
	:PanelElement(x_lower,x_upper,y_lower,y_upper)
	{
		options.push_back(new IconSettings(x_lower,x_upper/2,y_lower,y_lower + (y_upper-y_lower)/2));
		options.push_back(new IconDisplay(x_upper/2,x_upper,y_lower,y_lower + (y_upper-y_lower)/2));
		options.push_back(new IconGames(x_lower,x_upper/2,y_lower + (y_upper-y_lower)/2,y_upper));
		options.push_back(new IconSS(x_upper/2,x_upper,y_lower + (y_upper-y_lower)/2,y_upper));
		
		selected = options[indexSelected];
		selected->setSelected();
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
	
	void MainElement::changeSelected(char inp){
		//some event is passed in, current none 
		selected->setDeselected();
		switch (inp){
			case 'r':
				indexSelected++;
				if (indexSelected == (int)options.size()/2) indexSelected = 0;
				if (indexSelected == (int)options.size()) indexSelected = options.size()/2;
				break;
			case 'l':
				indexSelected--;
				if (indexSelected == (int)options.size()/2 - 1) indexSelected = options.size() - 1;
				if (indexSelected < 0) indexSelected = options.size()/2 -1;
				break;
			case 'u':
				indexSelected += 2;
				if (indexSelected >= (int)options.size()) indexSelected = 0 + (indexSelected - options.size());
				break;
			case 'd':
				indexSelected -= 2;
				if (indexSelected < 0) indexSelected = options.size() + indexSelected;
				break;
			default:
				break;
		}
			
		//check event, change indexSelected
		//i.e is left arrow pressed, do -1, right +1, up etc
		
		selected = options[indexSelected];
		selected->setSelected();
		
	}
	
	std::string MainElement::drawSelected(rgb_matrix::FrameCanvas* canvas) const{
		// CHANGE DECLARATION
		// WOULD EITHER, return nullptr or return std::string command, this would be pushed onto the server_cmds_queue
		
		if (typeid(*selected) == typeid(IconSettings)){
			return "{'switch_screen':'settings'}";
		}
		
		return "";
	}
	
}
