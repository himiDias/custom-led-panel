#include "led-matrix.h"
#include "graphics.h"

#include "settings_icon.h"

#include <iostream>

namespace desk_led{
	IconSettings::IconSettings(int x_lower, int x_upper, int y_lower, int y_upper)
	:IconElement(x_lower,x_upper,y_lower,y_upper)
	{
		
	}
	
	void IconSettings::drawIcon(rgb_matrix::FrameCanvas* canvas){
		check_canvas_null(canvas);
		drawBorders(canvas);
		int r,g,b;
		// draw selection border
		if (selected){
			currentColor = &selectedColor;
			r = currentColor->r;
			g = currentColor->g;
			b = currentColor->b;
			for (int x=x_l+2;x<=x_u-2;++x){
				canvas->SetPixel(x,y_l+2,r,g,b);
				canvas->SetPixel(x,y_u-2,r,g,b);
			}
			
			for (int y=y_l+2;y<y_u-2;++y){
				canvas->SetPixel(x_l+2,y,r,g,b);
				canvas->SetPixel(x_u-2,y,r,g,b);
			}	
		}else{
			currentColor = &standardColor;
			for (int x=x_l+2;x<=x_u-2;++x){
				canvas->SetPixel(x,y_l+2,0,0,0);
				canvas->SetPixel(x,y_u-2,0,0,0);
			}
			
			for (int y=y_l+2;y<y_u-2;++y){
				canvas->SetPixel(x_l+2,y,0,0,0);
				canvas->SetPixel(x_u-2,y,0,0,0);
			}
		}
		r = currentColor->r;
		g = currentColor->g;
		b = currentColor->b;
		
		int x_pos = x_l + (x_u-x_l)/2;
		int y_pos = y_l + (y_u-y_l)/2;
		//std::cout<<"x,y:"<<x_pos<<y_pos<<std::endl;
		//draw icon
		DrawCircle(canvas,x_pos,y_pos,3,*currentColor);
		DrawCircle(canvas,x_pos,y_pos,5,*currentColor);
		

		
		
		//draw cogs
		//cog left
		canvas->SetPixel(x_pos-5,y_pos,0,0,0);
		
		canvas->SetPixel(x_pos-6,y_pos-1,r,g,b);
		canvas->SetPixel(x_pos-7,y_pos-1,r,g,b);
		
		canvas->SetPixel(x_pos-6,y_pos+1,r,g,b);
		canvas->SetPixel(x_pos-7,y_pos+1,r,g,b);
		
		canvas->SetPixel(x_pos-7,y_pos,r,g,b);
		
		//cog left down
		canvas->SetPixel(x_pos-4,y_pos+3,0,0,0);
		canvas->SetPixel(x_pos-3,y_pos+4,0,0,0);
		
		canvas->SetPixel(x_pos-5,y_pos+3,r,g,b);
		canvas->SetPixel(x_pos-6,y_pos+4,r,g,b);
		
		canvas->SetPixel(x_pos-3,y_pos+5,r,g,b);
		canvas->SetPixel(x_pos-4,y_pos+6,r,g,b);
		
		canvas->SetPixel(x_pos-5,y_pos+5,r,g,b);
		
		//cog down
		canvas->SetPixel(x_pos,y_pos+5,0,0,0);
		
		canvas->SetPixel(x_pos-1,y_pos+6,r,g,b);
		canvas->SetPixel(x_pos-1,y_pos+7,r,g,b);
		
		canvas->SetPixel(x_pos+1,y_pos+6,r,g,b);
		canvas->SetPixel(x_pos+1,y_pos+7,r,g,b);
		
		canvas->SetPixel(x_pos,y_pos+7,r,g,b);
		
		//cog right down
		canvas->SetPixel(x_pos+4,y_pos+3,0,0,0);
		canvas->SetPixel(x_pos+3,y_pos+4,0,0,0);
		
		canvas->SetPixel(x_pos+5,y_pos+3,r,g,b);
		canvas->SetPixel(x_pos+6,y_pos+4,r,g,b);
		
		canvas->SetPixel(x_pos+3,y_pos+5,r,g,b);
		canvas->SetPixel(x_pos+4,y_pos+6,r,g,b);
		
		canvas->SetPixel(x_pos+5,y_pos+5,r,g,b);
		
		//cog right
		canvas->SetPixel(x_pos+5,y_pos,0,0,0);
		
		canvas->SetPixel(x_pos+6,y_pos-1,r,g,b);
		canvas->SetPixel(x_pos+7,y_pos-1,r,g,b);
		
		canvas->SetPixel(x_pos+6,y_pos+1,r,g,b);
		canvas->SetPixel(x_pos+7,y_pos+1,r,g,b);
		
		canvas->SetPixel(x_pos+7,y_pos,r,g,b);
		
		//cog right up
		canvas->SetPixel(x_pos+4,y_pos-3,0,0,0);
		canvas->SetPixel(x_pos+3,y_pos-4,0,0,0);
		
		canvas->SetPixel(x_pos+5,y_pos-3,r,g,b);
		canvas->SetPixel(x_pos+6,y_pos-4,r,g,b);
		
		canvas->SetPixel(x_pos+3,y_pos-5,r,g,b);
		canvas->SetPixel(x_pos+4,y_pos-6,r,g,b);
		
		canvas->SetPixel(x_pos+5,y_pos-5,r,g,b);
		
		//cog up
		canvas->SetPixel(x_pos,y_pos-5,0,0,0);
		
		canvas->SetPixel(x_pos-1,y_pos-6,r,g,b);
		canvas->SetPixel(x_pos-1,y_pos-7,r,g,b);
		
		canvas->SetPixel(x_pos+1,y_pos-6,r,g,b);
		canvas->SetPixel(x_pos+1,y_pos-7,r,g,b);
		
		canvas->SetPixel(x_pos,y_pos-7,r,g,b);
		
		//cog left up
		canvas->SetPixel(x_pos-4,y_pos-3,0,0,0);
		canvas->SetPixel(x_pos-3,y_pos-4,0,0,0);
		
		canvas->SetPixel(x_pos-5,y_pos-3,r,g,b);
		canvas->SetPixel(x_pos-6,y_pos-4,r,g,b);
		
		canvas->SetPixel(x_pos-3,y_pos-5,r,g,b);
		canvas->SetPixel(x_pos-4,y_pos-6,r,g,b);
		
		canvas->SetPixel(x_pos-5,y_pos-5,r,g,b);
	}
}
