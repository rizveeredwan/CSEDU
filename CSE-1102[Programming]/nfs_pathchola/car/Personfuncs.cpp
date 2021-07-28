#include "graphics.h"
void make_person(int x,int y) {
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,WHITE);
	rectangle(x,y,x+20,y+20);//chest
	floodfill(x+5,y+5,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	circle(x+10,y - 10,10);//head
	floodfill(x+10,y - 10,YELLOW);
	rectangle(x,y+20,x+5,y+25);//leg 1
	rectangle(x+15,y+20,x+20,y+25);//leg 2
	rectangle(x-5,y,x,y+5);//LEFT HAND
	rectangle(x+20,y,x+25,y+5);//RIGHT HAND

}

void erase_person(int x,int y) {
    setcolor(WHITE);
	setfillstyle(SOLID_FILL,BLACK);
	rectangle(x,y,x+20,y+20);//chest
	floodfill(x+5,y+5,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	circle(x+10,y - 10,10);//head
	floodfill(x+10,y - 10,BLACK);
	setcolor(BLACK);
	rectangle(x,y+20,x+5,y+25);//leg 1
	rectangle(x+15,y+20,x+20,y+25);//leg 2
	rectangle(x-5,y,x,y+5);//LEFT HAND
	rectangle(x+20,y,x+25,y+5);//RIGHT HAND

}
