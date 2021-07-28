#include "graphics.h"

int main()
{
	initwindow(1000,500, "Rizvee");
	int radius = 10,x = 50,y = 50;
	
	for(x = 0; x <= 1000;x++)
	{
		setcolor(100);
		circle(x,y,50);
		delay(5);
		setcolor(0);
		circle(x,y,50);
		
		
		
	}






	return 0;
}
