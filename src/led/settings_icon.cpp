#include "led-matrix.h"
#include "graphics.h"

#include "settings_icon.h"
#include "panel_element.h"

namespace desk_led{
	IconSettings::IconSettings(int x_lower, int x_upper, int y_lower, int y_upper)
	:IconElement(x_lower,x_upper,y_lower,y_upper)
	{
		
	}
	
	void drawSettingsIcon(rgb_matrix::FrameCanvas* canvas){
		//PanelElement::check_canvas_null(canvas);
		// draw selection border
		if (selected){
			for (int x=x_l+2;x<=x_u-2;++x){
				canvas->SetPixel(x,y_l,255,255,255);
				canvas->SetPixel(x,y_u,255,255,255);
			}
			
			for (int y=y_l+2;y<y_u-2;++y){
				canvas->SetPixel(x_l,y,255,255,255);
				canvas->SetPixel(x_u,y,255,255,255);
			}	
		}
		
		int x_pos = (x_u-x_l)/2;
		int y_pos = (y_u-y_l)/2;
		//draw icon
		DrawCircle(canvas,x_pos,y_pos,3,rgb_matrix::Color(255,255,255));
		
			
	}
}
