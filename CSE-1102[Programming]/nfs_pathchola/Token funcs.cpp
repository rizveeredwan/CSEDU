#include "graphics.h"
void coin(int x, int y)
{
	//setcolor(COLOR(204, 102, 0));
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, COLOR(204, 102, 0));
	circle(x, y, 8);
	//floodfill(x, y, COLOR(204, 102, 0));
	floodfill(x, y, WHITE);
	setcolor(BLACK);
	line(x-4, y+3, x-4, y-3);
	ellipse(x, y, 0, 360, 2, 3);
	ellipse(x+3, y, 0, 360, 2, 3);
}

void erase_coin(int x, int y)
{
	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL, DARKGRAY);
	floodfill(x, y, WHITE);
	circle(x, y, 8);
}

void king(int x, int y)
{
	//setcolor(COLOR(0, 0, 102));
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, COLOR(0, 0, 102));
	circle(x, y, 8);
	//floodfill(x, y, COLOR(0, 0, 102));
	floodfill(x, y, WHITE);
	int poly[]={x-8, y+8, x-4, y-4, x-2, y, x, y-8, x+2, y, x+4, y-4, x+8, y+8};
	setfillstyle(SOLID_FILL, YELLOW);
	fillpoly(7, poly);
}

void flash(int x, int y)
{
	//setcolor(COLOR(255, 51, 51));
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, COLOR(255, 51, 51));
	circle(x, y, 8);
	//floodfill(x, y, COLOR(255, 51, 51));
	floodfill(x, y, WHITE);
	int poly[]={x+4, y-8, x+8, y-8, x+6, y-4, x+8, y, x, y+8, x+4, y, x, y-4};
	setfillstyle(SOLID_FILL, YELLOW);
	fillpoly(7, poly);
}

void erase_flash(int x, int y)
{
	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL, DARKGRAY);
	circle(x, y, 8);
	floodfill(x, y, DARKGRAY);
	int poly[]={x+4, y-8, x+8, y-8, x+6, y-4, x+8, y, x, y+8, x+4, y, x, y-4};
	setfillstyle(SOLID_FILL, DARKGRAY);
	drawpoly(7, poly);
	fillpoly(7, poly);
}

void erase_king(int x, int y)
{
	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL, DARKGRAY);
	circle(x, y, 8);
	floodfill(x, y, DARKGRAY);
	int poly[]={x-8, y+8, x-4, y-4, x-2, y, x, y-8, x+2, y, x+4, y-4, x+8, y+8};
	setfillstyle(SOLID_FILL, DARKGRAY);
	drawpoly(7, poly);
	fillpoly(7, poly);
}