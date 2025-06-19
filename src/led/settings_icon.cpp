#include "led-matrix.h"
#include "graphics.h"

#include "settings_icon.h"

#include <iostream>

namespace desk_led{
	IconSettings::IconSettings(int x_lower, int x_upper, int y_lower, int y_upper)
	:IconElement(x_lower,x_upper,y_lower,y_upper)
	{
		
	}
	
	void IconSettings::drawIcon(rgb_matrix::FrameCanvas* canvas) const{
		check_canvas_null(canvas);
		drawBorders(canvas);
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
		
		int x_pos = x_l + (x_u-x_l)/2;
		int y_pos = y_l + (y_u-y_l)/2;
		//std::cout<<"x,y:"<<x_pos<<y_pos<<std::endl;
		//draw icon
		DrawCircle(canvas,x_pos,y_pos,3,rgb_matrix::Color(255,255,255));
		DrawCircle(canvas,x_pos,y_pos,5,rgb_matrix::Color(255,255,255));
		

		
		
		//draw cogs
		//cog left
		canvas->SetPixel(x_pos-5,y_pos,0,0,0);
		
		canvas->SetPixel(x_pos-6,y_pos-1,255,255,255);
		canvas->SetPixel(x_pos-7,y_pos-1,255,255,255);
		
		canvas->SetPixel(x_pos-6,y_pos+1,255,255,255);
		canvas->SetPixel(x_pos-7,y_pos+1,255,255,255);
		
		canvas->SetPixel(x_pos-7,y_pos,255,255,255);
		
		//cog left down
		canvas->SetPixel(x_pos-4,y_pos+3,0,0,0);
		canvas->SetPixel(x_pos-3,y_pos+4,0,0,0);
		
		canvas->SetPixel(x_pos-5,y_pos+3,255,255,255);
		canvas->SetPixel(x_pos-6,y_pos+4,255,255,255);
		
		canvas->SetPixel(x_pos-3,y_pos+5,255,255,255);
		canvas->SetPixel(x_pos-4,y_pos+6,255,255,255);
		
		canvas->SetPixel(x_pos-5,y_pos+5,255,255,255);
		
		//cog down
		canvas->SetPixel(x_pos,y_pos+5,0,0,0);
		
		canvas->SetPixel(x_pos-1,y_pos+6,255,255,255);
		canvas->SetPixel(x_pos-1,y_pos+7,255,255,255);
		
		canvas->SetPixel(x_pos+1,y_pos+6,255,255,255);
		canvas->SetPixel(x_pos+1,y_pos+7,255,255,255);
		
		canvas->SetPixel(x_pos,y_pos+7,255,255,255);
		
		//cog right down
		canvas->SetPixel(x_pos+4,y_pos+3,0,0,0);
		canvas->SetPixel(x_pos+3,y_pos+4,0,0,0);
		
		canvas->SetPixel(x_pos+5,y_pos+3,255,255,255);
		canvas->SetPixel(x_pos+6,y_pos+4,255,255,255);
		
		canvas->SetPixel(x_pos+3,y_pos+5,255,255,255);
		canvas->SetPixel(x_pos+4,y_pos+6,255,255,255);
		
		canvas->SetPixel(x_pos+5,y_pos+5,255,255,255);
		
		//cog right
		canvas->SetPixel(x_pos+5,y_pos,0,0,0);
		
		canvas->SetPixel(x_pos+6,y_pos-1,255,255,255);
		canvas->SetPixel(x_pos+7,y_pos-1,255,255,255);
		
		canvas->SetPixel(x_pos+6,y_pos+1,255,255,255);
		canvas->SetPixel(x_pos+7,y_pos+1,255,255,255);
		
		canvas->SetPixel(x_pos+7,y_pos,255,255,255);
		
		//cog right up
		canvas->SetPixel(x_pos+4,y_pos-3,0,0,0);
		canvas->SetPixel(x_pos+3,y_pos-4,0,0,0);
		
		canvas->SetPixel(x_pos+5,y_pos-3,255,255,255);
		canvas->SetPixel(x_pos+6,y_pos-4,255,255,255);
		
		canvas->SetPixel(x_pos+3,y_pos-5,255,255,255);
		canvas->SetPixel(x_pos+4,y_pos-6,255,255,255);
		
		canvas->SetPixel(x_pos+5,y_pos-5,255,255,255);
		
		//cog up
		canvas->SetPixel(x_pos,y_pos-5,0,0,0);
		
		canvas->SetPixel(x_pos-1,y_pos-6,255,255,255);
		canvas->SetPixel(x_pos-1,y_pos-7,255,255,255);
		
		canvas->SetPixel(x_pos+1,y_pos-6,255,255,255);
		canvas->SetPixel(x_pos+1,y_pos-7,255,255,255);
		
		canvas->SetPixel(x_pos,y_pos-7,255,255,255);
		
		//cog left up
		canvas->SetPixel(x_pos-4,y_pos-3,0,0,0);
		canvas->SetPixel(x_pos-3,y_pos-4,0,0,0);
		
		canvas->SetPixel(x_pos-5,y_pos-3,255,255,255);
		canvas->SetPixel(x_pos-6,y_pos-4,255,255,255);
		
		canvas->SetPixel(x_pos-3,y_pos-5,255,255,255);
		canvas->SetPixel(x_pos-4,y_pos-6,255,255,255);
		
		canvas->SetPixel(x_pos-5,y_pos-5,255,255,255);
	}
}
