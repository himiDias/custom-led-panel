#include "panel_element.h"

#include "iostream"

namespace desk-led {
	PanelElement::PanelElement(int x_lower, int x_upper, int y_lower, int y_upper):
	x_l(x_lower),
	x_u(x_upper),
	y_l(y_lower),
	y_u(y_upper)
	{}
	
	
	void PanelElement::clear(rgb_matrix::FrameCanvas* canvas) const{
		if (canvas == nullptr){
			std::cerr << "No canvas passed in\n";
			return;
		}
		
		for (int x=x_l;x<x_u;++x){
			for (int y=y_l;y<y_u;++y){
				canvas->SetPixel(x,y,0,0,0);
			}
		}
	}
}
	
	
