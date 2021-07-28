#include "graphics.h"
void draw_bomb(int x, int y)
{
	setcolor(WHITE);
	ellipse(x, y, 0, 360, 5, 10);
	setfillstyle(SOLID_FILL, BLACK);
	fillellipse(x, y, 5, 10);
	rectangle(x-1, y-7, x+1, y-12);
}
void erase_bomb(int x, int y)
{
	setcolor(DARKGRAY);
	ellipse(x, y, 0, 360, 5, 10);
	setfillstyle(SOLID_FILL, DARKGRAY);
	fillellipse(x, y, 5, 10);
	rectangle(x-1, y-7, x+1, y-12);
}
void explode(int x, int y)
{
	int r;
	int up=x;
	if(up<y) up=y;
	if(up<(600-y)) up=600-y;
	if(up<(1200-x)) up=1200-x;
	for(r=15; r<=up; r+=15){
		if((r/15)%2) setfillstyle(SOLID_FILL,YELLOW);
		else setfillstyle(SOLID_FILL,RED);
		fillellipse(x, y, r, r);
		delay(50);
	}
}