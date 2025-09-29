#include "panel_element.h"

#include "iostream"

namespace desk_led {
	PanelElement::PanelElement(int x_lower, int x_upper, int y_lower, int y_upper)
	:x_l(x_lower),
	x_u(x_upper),
	y_l(y_lower),
	y_u(y_upper)
	{}
	
	
	bool PanelElement::check_canvas_null(rgb_matrix::FrameCanvas* canvas) const{
		if (canvas == nullptr){
			std::cerr << "No canvas passed in\n";
			return true;
		}
		return false;
	}
	
	void PanelElement::clear(rgb_matrix::FrameCanvas* canvas) const{
		if (check_canvas_null(canvas)){
			return;
		}
		
		for (int x=x_l;x<=x_u;++x){
			for (int y=y_l;y<=y_u;++y){
				canvas->SetPixel(x,y,0,0,0);
			}
		}
	}
	
	void PanelElement::drawBorders(rgb_matrix::FrameCanvas* canvas) const{
		if (PanelElement::check_canvas_null(canvas)){
			return;
		}
		
		//draw border
		for (int x=x_l;x<=x_u;++x){
			canvas->SetPixel(x,y_l,255,255,255);
			canvas->SetPixel(x,y_u,255,255,255);
		}
		
		for (int y=y_l;y<y_u;++y){
			canvas->SetPixel(x_l,y,255,255,255);
			canvas->SetPixel(x_u,y,255,255,255);
		}
		
		
		
	}
	
	void PanelElement::clearContents(rgb_matrix::FrameCanvas* canvas) const{
		if (check_canvas_null(canvas)){
			return;
		}
		
		for (int x=x_l+1;x<x_u;++x){
			for (int y=y_l+1;y<y_u;++y){
				canvas->SetPixel(x,y,0,0,0);
			}
		}
	}
}
	
	
