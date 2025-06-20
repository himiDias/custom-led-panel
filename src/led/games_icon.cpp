#include "led-matrix.h"
#include "graphics.h"

#include "games_icon.h"


namespace desk_led{
	IconGames::IconGames(int x_lower, int x_upper, int y_lower, int y_upper)
	:IconElement(x_lower,x_upper,y_lower,y_upper)
	{
		
	}
	
	void IconGames::drawIcon(rgb_matrix::FrameCanvas* canvas){
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
		
		//butons
		DrawCircle(canvas,x_pos+6,y_pos-4,1,*currentColor);
		DrawCircle(canvas,x_pos+6,y_pos+2,1,*currentColor);
		DrawCircle(canvas,x_pos+9,y_pos-1,1,*currentColor);
		DrawCircle(canvas,x_pos+3,y_pos-1,1,*currentColor);
		
		//d pad
		canvas->SetPixel(x_pos-7,y_pos,r,g,b);
		canvas->SetPixel(x_pos-7,y_pos-2,r,g,b);
		canvas->SetPixel(x_pos-8,y_pos,r,g,b);
		canvas->SetPixel(x_pos-8,y_pos-2,r,g,b);
		canvas->SetPixel(x_pos-9,y_pos,r,g,b);
		canvas->SetPixel(x_pos-9,y_pos-1,r,g,b);
		canvas->SetPixel(x_pos-9,y_pos-2,r,g,b);
		
		canvas->SetPixel(x_pos-1,y_pos,r,g,b);
		canvas->SetPixel(x_pos-1,y_pos-1,r,g,b);
		canvas->SetPixel(x_pos-1,y_pos-2,r,g,b);
		canvas->SetPixel(x_pos-2,y_pos,r,g,b);
		canvas->SetPixel(x_pos-2,y_pos-2,r,g,b);
		canvas->SetPixel(x_pos-3,y_pos,r,g,b);
		canvas->SetPixel(x_pos-3,y_pos-2,r,g,b);
		
		canvas->SetPixel(x_pos-4,y_pos+1,r,g,b);
		canvas->SetPixel(x_pos-6,y_pos+1,r,g,b);
		canvas->SetPixel(x_pos-4,y_pos+2,r,g,b);
		canvas->SetPixel(x_pos-6,y_pos+2,r,g,b);
		canvas->SetPixel(x_pos-4,y_pos+3,r,g,b);
		canvas->SetPixel(x_pos-5,y_pos+3,r,g,b);
		canvas->SetPixel(x_pos-6,y_pos+3,r,g,b);
		
		canvas->SetPixel(x_pos-4,y_pos-3,r,g,b);
		canvas->SetPixel(x_pos-6,y_pos-3,r,g,b);
		canvas->SetPixel(x_pos-4,y_pos-4,r,g,b);
		canvas->SetPixel(x_pos-6,y_pos-4,r,g,b);
		canvas->SetPixel(x_pos-4,y_pos-5,r,g,b);
		canvas->SetPixel(x_pos-5,y_pos-5,r,g,b);
		canvas->SetPixel(x_pos-6,y_pos-5,r,g,b);
		
		canvas->SetPixel(x_pos-6,y_pos-2,r,g,b);
		canvas->SetPixel(x_pos-6,y_pos,r,g,b);
		canvas->SetPixel(x_pos-4,y_pos-2,r,g,b);
		canvas->SetPixel(x_pos-4,y_pos,r,g,b);
		
		//body
		for (int x = x_pos-9; x < x_pos + 11;x++){
			canvas->SetPixel(x,y_pos-7,r,g,b);
		}
		canvas->SetPixel(x_pos-10,y_pos-6,r,g,b);
		canvas->SetPixel(x_pos+11,y_pos-6,r,g,b);
		canvas->SetPixel(x_pos-10,y_pos-5,r,g,b);
		canvas->SetPixel(x_pos+11,y_pos-5,r,g,b);
		
		canvas->SetPixel(x_pos-11,y_pos-4,r,g,b);
		canvas->SetPixel(x_pos+12,y_pos-4,r,g,b);
		canvas->SetPixel(x_pos-11,y_pos-3,r,g,b);
		canvas->SetPixel(x_pos+12,y_pos-3,r,g,b);
		
		canvas->SetPixel(x_pos-12,y_pos-2,r,g,b);
		canvas->SetPixel(x_pos+13,y_pos-2,r,g,b);
		canvas->SetPixel(x_pos-12,y_pos-1,r,g,b);
		canvas->SetPixel(x_pos+13,y_pos-1,r,g,b);
		canvas->SetPixel(x_pos-12,y_pos,r,g,b);
		canvas->SetPixel(x_pos+13,y_pos,r,g,b);
		canvas->SetPixel(x_pos-12,y_pos+1,r,g,b);
		canvas->SetPixel(x_pos+13,y_pos+1,r,g,b);
		
		canvas->SetPixel(x_pos-13,y_pos+2,r,g,b);
		canvas->SetPixel(x_pos+14,y_pos+2,r,g,b);
		canvas->SetPixel(x_pos-13,y_pos+3,r,g,b);
		canvas->SetPixel(x_pos+14,y_pos+3,r,g,b);
		canvas->SetPixel(x_pos-13,y_pos+4,r,g,b);
		canvas->SetPixel(x_pos+14,y_pos+4,r,g,b);
		canvas->SetPixel(x_pos-13,y_pos+5,r,g,b);
		canvas->SetPixel(x_pos+14,y_pos+5,r,g,b);
		canvas->SetPixel(x_pos-13,y_pos+6,r,g,b);
		canvas->SetPixel(x_pos+14,y_pos+6,r,g,b);
		
		canvas->SetPixel(x_pos-12,y_pos+7,r,g,b);
		canvas->SetPixel(x_pos+13,y_pos+7,r,g,b);
		
		canvas->SetPixel(x_pos-11,y_pos+8,r,g,b);
		canvas->SetPixel(x_pos+12,y_pos+8,r,g,b);
		canvas->SetPixel(x_pos-10,y_pos+8,r,g,b);
		canvas->SetPixel(x_pos+11,y_pos+8,r,g,b);
		canvas->SetPixel(x_pos-9,y_pos+8,r,g,b);
		canvas->SetPixel(x_pos+10,y_pos+8,r,g,b);
		canvas->SetPixel(x_pos-8,y_pos+8,r,g,b);
		canvas->SetPixel(x_pos+9,y_pos+8,r,g,b);
		
		canvas->SetPixel(x_pos-7,y_pos+7,r,g,b);
		canvas->SetPixel(x_pos+8,y_pos+7,r,g,b);
		canvas->SetPixel(x_pos-6,y_pos+6,r,g,b);
		canvas->SetPixel(x_pos+7,y_pos+6,r,g,b);
		
		for (int x = x_pos-5;x<x_pos+7;x++){
			canvas->SetPixel(x,y_pos+5,r,g,b);
		}
		
		 
	}
	
}
