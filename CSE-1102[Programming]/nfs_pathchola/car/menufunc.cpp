#include "graphics.h"
void menu(int x,int y)
{
	readimagefile("Poth.jpg",0,0,1200,600);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,20);
	outtextxy(x,y,"Welcome to NFS Pothchola\n");
	outtextxy(x,y + 50,"Press S to start New game\n");
	outtextxy(x,y + 100,"Press E to exit the game\n");
}