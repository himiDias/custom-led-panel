
#include "led-matrix.h"

#include "icon_elem.h"

namespace desk_led{
	IconElement::IconElement(int x_lower, int x_upper, int y_lower, int y_upper)
	:PanelElement(x_lower,x_upper,y_lower,y_upper)
	{
		
	}
	
	void IconElement::drawIcon(rgb_matrix::FrameCanvas* canvas)const{
		
	}
	
	void IconElement::setSelected(){
		selected = true;
	}
	
	void IconElement::setDeselected(){
		selected = false;
	}
}

