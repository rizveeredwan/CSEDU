#include "graphics.h"
#include "background.h"
void make_person(int x,int y, int mode) 
{
	setcolor(BLACK);
	if(!mode)	setfillstyle(SOLID_FILL, YELLOW);
	else if(mode==1) setfillstyle(SOLID_FILL, COLOR(247, 52, 52));
	else if(mode==2) setfillstyle(SOLID_FILL, COLOR(0, 0, 255));
	fillellipse(x, y, 8, 8);
	circle(x+3, y-2, 1);
	circle(x-3, y-2, 1);
	line(x-4, y+1, x+4, y+1);
	ellipse(x, y+1, 180, 360, 4, 4);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(x, y+3, BLACK);
}
void erase_person(int x,int y) 
{
	if(x<=500 || x>=700){
		if((y<=200 || y>=400)){
			setcolor(DARKGRAY);
			setfillstyle(SOLID_FILL, DARKGRAY);
		}
		else{
			setcolor(BLACK);
			setfillstyle(SOLID_FILL, BLACK);
		}
	
	}
	else{
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
	}
	circle(x, y, 8);
	fillellipse(x, y, 8, 8);
	background(0);
}
