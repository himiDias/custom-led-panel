#include "status_elem.h"

#include "iostream"

namespace desk_led{
	StatusElement::StatusElement(int x_lower, int x_upper, int y_lower, int y_upper)
	:PanelElement(x_lower,x_upper,y_lower,y_upper)
	{}
	
	void StatusElement::draw(rgb_matrix::FrameCanvas* canvas) const{
		if (PanelElement::check_canvas_null(canvas)){
			return;
		}
		
		//draw border
		for (int x=x_l;x<=x_u;++x){
			canvas->SetPixel(x,y_l,255,255,255);
			canvas->SetPixel(x,y_u,255,255,255);
		}
	}
}
	
	
