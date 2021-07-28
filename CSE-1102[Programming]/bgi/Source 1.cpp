#include "graphics.h"
int main()
{
	initwindow(1000,500,"A");
	int r = 80;
	int c = 0;
	while(1) {
	if(c == 0) {
		setcolor(GREEN);
		setfillstyle(SOLID_FILL,GREEN);
		circle(50,250,50);
		floodfill(50,250,GREEN);
		c++;
		delay(500);
		//setcolor(BLACK);
		setfillstyle(SOLID_FILL,BLACK);
		floodfill(50,250,BLACK);
		
		continue;
	}
	else if(c == 1) {
		setcolor(GREEN);
		setfillstyle(SOLID_FILL,GREEN);
		circle(500,450,50);
		floodfill(500,450,GREEN);
		c++;
		delay(500);
		//setcolor(0);
		setfillstyle(SOLID_FILL,BLACK);
		floodfill(500,450,BLACK);
		
		continue;
	}
	else if(c == 2) {
		   setcolor(GREEN);
		   setfillstyle(SOLID_FILL,GREEN);
           circle(940,250,50);
		   floodfill(940,250,GREEN);
		   c = 0;
		   delay(500);
		   //setcolor(0);
		   setfillstyle(SOLID_FILL,BLACK);
		   floodfill(940,250,BLACK);
		   
		   continue;
	}
	}

	while(1);
	return 0;
}