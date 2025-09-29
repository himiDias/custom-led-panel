#include "led-matrix.h"
#include "graphics.h"

#include "screensaver_icon.h"

namespace desk_led{
	IconSS::IconSS(int x_lower, int x_upper, int y_lower, int y_upper)
	:IconElement(x_lower,x_upper,y_lower,y_upper)
	{
		
	}
	
	void IconSS::drawIcon(rgb_matrix::FrameCanvas* canvas){
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
		
		int x_pos = (x_l + (x_u-x_l)/2);
		int y_pos = (y_l + (y_u-y_l)/2);
		
		//panel
		for (int x = x_pos - 10;x<x_pos+11;x++){
				canvas->SetPixel(x,y_pos-6,r,g,b);
				canvas->SetPixel(x,y_pos+6,r,g,b);
		}
		
		for (int y = y_pos -5;y < y_pos+6;y++){
			canvas->SetPixel(x_pos-10,y,r,g,b);
			canvas->SetPixel(x_pos+10,y,r,g,b);
		}
		
		//sprite
		canvas->SetPixel(x_pos,y_pos-4,r,g,b);
		canvas->SetPixel(x_pos-1,y_pos-3,r,g,b);
		canvas->SetPixel(x_pos+1,y_pos-3,r,g,b);
		canvas->SetPixel(x_pos-1,y_pos-2,r,g,b);
		canvas->SetPixel(x_pos+1,y_pos-2,r,g,b);
		canvas->SetPixel(x_pos-1,y_pos-1,r,g,b);
		canvas->SetPixel(x_pos+1,y_pos-1,r,g,b);
		
		canvas->SetPixel(x_pos-2,y_pos-1,r,g,b);
		canvas->SetPixel(x_pos+2,y_pos-1,r,g,b);
		canvas->SetPixel(x_pos-3,y_pos-2,r,g,b);
		canvas->SetPixel(x_pos+3,y_pos-2,r,g,b);
		canvas->SetPixel(x_pos-4,y_pos-2,r,g,b);
		canvas->SetPixel(x_pos+4,y_pos-2,r,g,b);
		canvas->SetPixel(x_pos-4,y_pos-1,r,g,b);
		canvas->SetPixel(x_pos+4,y_pos-1,r,g,b);
		canvas->SetPixel(x_pos-3,y_pos,r,g,b);
		canvas->SetPixel(x_pos+3,y_pos,r,g,b);
		
		canvas->SetPixel(x_pos-2,y_pos+1,r,g,b);
		canvas->SetPixel(x_pos+2,y_pos+1,r,g,b);
		canvas->SetPixel(x_pos-3,y_pos+2,r,g,b);
		canvas->SetPixel(x_pos+3,y_pos+2,r,g,b);
		canvas->SetPixel(x_pos-4,y_pos+3,r,g,b);
		canvas->SetPixel(x_pos+4,y_pos+3,r,g,b);
		canvas->SetPixel(x_pos-3,y_pos+4,r,g,b);
		canvas->SetPixel(x_pos+3,y_pos+4,r,g,b);
		
		canvas->SetPixel(x_pos-2,y_pos+4,r,g,b);
		canvas->SetPixel(x_pos+2,y_pos+4,r,g,b);
		canvas->SetPixel(x_pos-1,y_pos+3,r,g,b);
		canvas->SetPixel(x_pos+1,y_pos+3,r,g,b);
		
		canvas->SetPixel(x_pos,y_pos+2,r,g,b);
	}
}
