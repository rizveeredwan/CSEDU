#include "graphics.h"
void background(int i)
{
	setcolor(WHITE);
	line (0,200,500,200); // line No 1
	line (0,400,500,400); // line no 2
	line (500,0,500, 200);
	line(500,400,500,600);
	line(700,400,700,600);
	line(700,200,1200,200);
	line(700,400,1200,400);
	line(700,0,700,200);
	line(0,298,500,298); // Divider line 1;
	line(0,302,500,302); //Divider line 1;
	line(598,0,598,200); //Divider line 2;
	line(602,0,602,200);//Divider line 2;
	line (598,400,598,600);//Divider line 3;
	line (602,400,602,600); //Divider line 3;
	line(700,298, 1200,298); //Divide line 4;
	line(700,302, 1200,302); //Divide line 4;
	/// lane preparation
    int x,y;
	for(y = 250; (y + 100) <= 450; y = (y + 100)) 
	{
		for(x = 0; (x + 10) <= 1200; x = (x + 20)) 
		{
			if(x > 500 && x < 700) continue; 
			setcolor(WHITE);
            rectangle(x,y - 2, x + 10, y + 2);
			setfillstyle(SOLID_FILL, WHITE);
			floodfill(x + 5,y, WHITE);
		}
	}
 
	for(x = 550; (x + 100) <= 750; x = (x + 100)) 
	{
		for(y = 0; (y + 10) <= 600; y = (y + 20)) 
		{
			if(y > 200 && y < 400) continue; 
			setcolor(WHITE);
            rectangle(x - 2,y, x + 2, y + 10);
			setfillstyle(SOLID_FILL, WHITE);
			floodfill(x,y+5,WHITE);
 
		}
	}
 
	//FOOTPATH
	setfillstyle(SOLID_FILL,DARKGRAY); //FOOTHPATH 1
	floodfill(715,415,WHITE);
	line(730,430,730,600);
	line(730,430,1200,430);
	/*setcolor(WHITE);
	line(705,405,705,600);
	line(705,405,1200,405);
	line(725,600,725,425);
	line(725,425,1200,425);
	setfillstyle(SOLID_FILL,RED);
	floodfill(703,403,WHITE);
	floodfill(728,428,WHITE);*/ 
 
 
	setfillstyle(SOLID_FILL,DARKGRAY); //FOOTHPATH 2
	floodfill(715,185,WHITE);
	line(730,0,730,170);
	line(730,170,1200,170);
	/*setcolor(WHITE);
	line(705,0,705,195);
	line(705,195,1200,195);
	line(725,0,725,175);
	line(725,175,1200,175);
	setfillstyle(SOLID_FILL,RED);
	floodfill(703,198,WHITE);
	floodfill(728,173,WHITE); */
 
 
	setfillstyle(SOLID_FILL,DARKGRAY); //FOOTHPATH 3
	floodfill(485,415,WHITE);
	line(470,430,470,600);
	line(0,430,470,430);
	/*setcolor(WHITE);
	line(495,405,495,600);
	line(0,405,495,405);
	line(475,600,475,425);
	line(0,425,475,425);
	setfillstyle(SOLID_FILL,RED);
	floodfill(498,403,WHITE);
	floodfill(473,428,WHITE); */
 
	setfillstyle(SOLID_FILL,DARKGRAY); //FOOTHPATH 4
	floodfill(485,185,WHITE);
	line(470,0,470,170);
	line(0,170,470,170);
	/*setcolor(WHITE);
	line(475,175,475,0);
	line(475,175,0,175);
	line(495,0,495,195);
	line(495,195,0,195);
	setfillstyle(SOLID_FILL,RED);
	floodfill(473,173,WHITE);
	floodfill(498,198,WHITE);*/ 
    //BACKGROUND
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(250,100,WHITE);
	floodfill(950,100,WHITE);
    floodfill(250,500,WHITE);
    floodfill(950,500,WHITE);
	//Different parts
	if(i){
		readimagefile("image 1.jpg",0,0,470,168);//LEFT 1
		readimagefile("image 2.jpg",730,0,1200,168);// RIGHT 1
		readimagefile("image 3.jpg",0,430,470,600);//LEFT 2
		readimagefile("image 5.jpg",730,430,1200,600); //RIGHT 2
	}

	
 

} 

