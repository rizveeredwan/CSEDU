#include "graphics.h"
#include "stdio.h"

void background()
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
	/*setcolor(RED);
	setfillstyle(SOLID_FILL,YELLOW);
	circle(600,300,25); // POLICE STATION
	floodfill(600,300,RED);
	setcolor(RED);
	line(600,275,600,325); // police station border
	line(575,300,625,300);// police station border
 
   	line(580,285,620,315); //police station border
 
	line(620,285,580,315); // police station border
	*/// lane preparation
    int x,y,i;
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
	setcolor(WHITE);
	line(705,405,705,600);
	line(705,405,1200,405);
	line(725,600,725,425);
	line(725,425,1200,425);
	setfillstyle(SOLID_FILL,RED);
	floodfill(703,403,WHITE);
	floodfill(728,428,WHITE); 
 
 
	setfillstyle(SOLID_FILL,DARKGRAY); //FOOTHPATH 2
	floodfill(715,185,WHITE);
	line(730,0,730,170);
	line(730,170,1200,170);
	setcolor(WHITE);
	line(705,0,705,195);
	line(705,195,1200,195);
	line(725,0,725,175);
	line(725,175,1200,175);
	setfillstyle(SOLID_FILL,RED);
	floodfill(703,198,WHITE);
	floodfill(728,173,WHITE); 
 
 
	setfillstyle(SOLID_FILL,DARKGRAY); //FOOTHPATH 3
	floodfill(485,415,WHITE);
	line(470,430,470,600);
	line(0,430,470,430);
	setcolor(WHITE);
	line(495,405,495,600);
	line(0,405,495,405);
	line(475,600,475,425);
	line(0,425,475,425);
	setfillstyle(SOLID_FILL,RED);
	floodfill(498,403,WHITE);
	floodfill(473,428,WHITE); 
 
	setfillstyle(SOLID_FILL,DARKGRAY); //FOOTHPATH 4
	floodfill(485,185,WHITE);
	line(470,0,470,170);
	line(0,170,470,170);
	setcolor(WHITE);
	line(475,175,475,0);
	line(475,175,0,175);
	line(495,0,495,195);
	line(495,195,0,195);
	setfillstyle(SOLID_FILL,RED);
	floodfill(473,173,WHITE);
	floodfill(498,198,WHITE); 
    //BACKGROUND
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(250,100,WHITE);
	floodfill(950,100,WHITE);
    floodfill(250,500,WHITE);
    floodfill(950,500,WHITE);
	//Different parts
	readimagefile("image 1.jpg",0,0,470,168);//LEFT 1
	readimagefile("image 2.jpg",730,0,1200,168);// RIGHT 1
	readimagefile("image 3.jpg",0,430,470,600);//LEFT 2
	readimagefile("image 5.jpg",730,430,1200,600); //RIGHT 2
	

	
 

} 

void draw_car(int startx, int starty, int road, int lane)
{
	int width=30;
	int length=65;
	setcolor(COLOR(255, 4, 4));
	if((road==1) && (lane==3 || lane==4)){
		line(startx+5, starty, startx+width-5, starty);                           //Main Body
		line(startx+5, starty+length, startx+width-5, starty+length);
		line(startx, starty+length-5, startx, starty+5);
		line(startx+width, starty+length-5, startx+width, starty+5);
		line(startx+5, starty, startx, starty+5);
		line(startx+width-5, starty, startx+width, starty+5);
		line(startx, starty+length-5, startx+5, starty+length);
		line(startx+width, starty+length-5, startx+width-5, starty+length);
		setfillstyle(SOLID_FILL, COLOR(255, 4, 4));
		floodfill(startx+width/2, starty+length/2, COLOR(255, 4, 4));
		setcolor(BLACK);
		line(startx, starty+length-5, startx+width, starty+length-5);            //Headlights
		line(startx+7, starty+length, startx+7, starty+length-5);
		line(startx+width-7, starty+length, startx+width-7, starty+length-5);
		setfillstyle(SOLID_FILL, WHITE);
		floodfill(startx+4, starty+length-4, BLACK);
		floodfill(startx+width-4, starty+length-4, BLACK);
		line(startx+5, starty+length-20, startx+width/2-4, starty+length-7);      //Engine Marks
		line(startx+width-5, starty+length-20, startx+width/2+4, starty+length-7);   
		line(startx+2, starty+length-23, startx+width-2, starty+length-23);       //Windshield
		line(startx+10, starty+length-33, startx+width-10,starty+length-33);
		line(startx+2, starty+length-23, startx+10, starty+length-33);
		line(startx+width-2, starty+length-23, startx+width-10, starty+length-33);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(startx+width/2, starty+length-28, BLACK); 
		line(startx+2, starty+length-27, startx+10, starty+length-37);           //Windows
		line(startx+width-2, starty+length-27, startx+width-10, starty+length-37);
	 	line(startx+10, starty+length-37,startx+10, starty+length-45);
		line(startx+width-10, starty+length-37,startx+width-10, starty+length-45);
		line(startx+10, starty+length-45, startx+2,starty+length-50);
		line(startx+width-10, starty+length-45, startx+width-2,starty+length-50);
		line(startx+width-2, starty+length-27, startx+width-2,starty+length-50);
		line(startx+2, starty+length-27,  startx+2,starty+length-50);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(startx+5, starty+length-37, BLACK);                           
		floodfill(startx+width-5, starty+length-37, BLACK);                         
		line(startx+2, starty+length-52, startx+width-2, starty+length-52);     //Rear window
		line(startx+10, starty+length-49, startx+width-10, starty+length-49);
		line(startx+2, starty+length-52, startx+10, starty+length-49);
		line(startx+width-10, starty+length-49, startx+width-2, starty+length-52);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(startx+width/2-8, starty+length-51, BLACK);
		line(startx+8, starty, startx+8, starty+5);                            //Tail lights
		line(startx, starty+5, startx+8, starty+5);
		setfillstyle(SOLID_FILL, LIGHTRED);
		floodfill(startx+3, starty+3, BLACK);
		line(startx+width-8, starty, startx+width-8, starty+5);
		line(startx+width, starty+5, startx+width-8, starty+5);
		setfillstyle(SOLID_FILL, LIGHTRED);
		floodfill(startx+width-3, starty+3, BLACK);
	}


	else if(road==1 && (lane==1 || lane==2)){
		line(startx+5, starty, startx+width-5, starty);                 //Main Body
		line(startx+5, starty+length, startx+width-5, starty+length);
		line(startx, starty+length-5, startx, starty+5);
		line(startx+width, starty+length-5, startx+width, starty+5);
		line(startx+5, starty, startx, starty+5);
		line(startx+width-5, starty, startx+width, starty+5);
		line(startx, starty+length-5, startx+5, starty+length);
		line(startx+width, starty+length-5, startx+width-5, starty+length);
		setfillstyle(SOLID_FILL, COLOR(255, 4, 4));
		floodfill(startx+width/2, starty+length/2, COLOR(255, 4, 4));
		setcolor(BLACK);                                               //Headlights
		line(startx, starty+5, startx+width, starty+5);
		line(startx+7, starty, startx+7, starty+5);
		line(startx+width-7, starty, startx+width-7, starty+5);
		setfillstyle(SOLID_FILL, WHITE);
		floodfill(startx+4, starty+4, BLACK);
		floodfill(startx+width-4, starty+4, BLACK);                   
		line(startx+5, starty+20, startx+width/2-4, starty+7);         //Engine Marks
		line(startx+width-5, starty+20, startx+width/2+4, starty+7);
		line(startx+2, starty+23, startx+width-2, starty+23);          //Windshield
		line(startx+10, starty+33, startx+width-10,starty+33);
		line(startx+2, starty+23, startx+10, starty+33);
		line(startx+width-2, starty+23, startx+width-10, starty+33);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(startx+width/2, starty+28, BLACK);
		line(startx+2, starty+27, startx+10, starty+37);             //Windows
		line(startx+width-2, starty+27, startx+width-10, starty+37);
		line(startx+10, starty+37,startx+10, starty+45);
		line(startx+width-10, starty+37,startx+width-10, starty+45);
		line(startx+10, starty+45, startx+2,starty+50);
		line(startx+width-10, starty+45, startx+width-2,starty+50);
		line(startx+width-2, starty+27, startx+width-2,starty+50);
		line(startx+2, starty+27,  startx+2,starty+50);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(startx+5, starty+37, BLACK);
		floodfill(startx+width-5, starty+37, BLACK);
		line(startx+2, starty+52, startx+width-2, starty+52);         //Rear Window
		line(startx+10, starty+49, startx+width-10, starty+49);
		line(startx+2, starty+52, startx+10, starty+49);
		line(startx+width-10, starty+49, startx+width-2, starty+52);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(startx+width/2-8, starty+51, BLACK);
		line(startx+8, starty+length, startx+8, starty+length-5);     //Tail Lights
		line(startx, starty+length-5, startx+8, starty+length-5);
		setfillstyle(SOLID_FILL, LIGHTRED);
		floodfill(startx+3, starty+length-3, BLACK);
		line(startx+width-8, starty+length, startx+width-8, starty+length-5);
		line(startx+width, starty+length-5, startx+width-8, starty+length-5);
		setfillstyle(SOLID_FILL, LIGHTRED);
		floodfill(startx+width-3, starty+length-3, BLACK);
	}
	else if((road==2) && (lane==1 || lane==2)){
		
		line(startx, starty+5, startx, starty+width-5);                               //Main Body
		line(startx+length, starty+5, startx+length, starty+width-5);
		line(startx+length-5, starty, startx+5, starty);
		line(startx+length-5, starty+width, startx+5, starty+width);
		line(startx, starty+5, startx+5, starty);
		line(startx, starty+width-5, startx+5, starty+width);
		line(startx+length-5, starty, startx+length, starty+5);
		line(startx+length-5, starty+width,  startx+length, starty+width-5);
		setfillstyle(SOLID_FILL, COLOR(255, 4, 4));
		floodfill(startx+length/2, starty+width/2, COLOR(255, 4, 4));
		setcolor(BLACK);                                                            //Headlights
		line(startx+length-5, starty+width, startx+length-5, starty);
		line(startx+length, starty+7, startx+length-5, starty+7);
		line(startx+length, starty+width-7, startx+length-5,starty+width-7);
		setfillstyle(SOLID_FILL, WHITE);
		floodfill(startx+length-4, starty+4, BLACK);
		floodfill(startx+length-4, starty+width-4, BLACK);
		line(startx+length-20, starty+5, startx+length-7, starty+width/2-4);       //Engine Marks
		line(startx+length-20, starty+width-5, startx+length-7, starty+width/2+4);
		line(startx+length-23,starty+2, startx+length-23,starty+width-2);          //Windshield
		line(startx+length-33, starty+10 ,startx+length-33, starty+width-10);
		line(startx+length-23, starty+2,  startx+length-33, starty+10);
		line(startx+length-23,starty+width-2,startx+length-33,starty+width-10);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(startx+length-28, starty+width/2, BLACK); 
		line(startx+length-27, starty+2, startx+length-37,starty+10);                             //Windows
		line(startx+length-27, starty+width-2, startx+length-37, starty+width-10);
		line(startx+length-37, starty+10, startx+length-45, starty+10);
		line(startx+length-37, starty+width-10, startx+length-45, starty+width-10);
		line(startx+length-45, starty+10, startx+length-50, starty+2);
	    line(startx+length-45,starty+width-10,startx+length-50,starty+width-2);
		line(startx+length-27,starty+width-2,startx+length-50, starty+width-2);
		line(startx+length-27, starty+2,startx+length-50,starty+2);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(startx+length-37, starty+5, BLACK);
		floodfill(startx+length-37, starty+width-5, BLACK);
		line(startx+length-52, starty+2, startx+length-52, starty+width-2);                  //Rear Window
		line(startx+length-49,starty+10, startx+length-49, starty+width-10);
		line(startx+length-52, starty+2,startx+length-49, starty+10);
		line(startx+length-49, starty+width-10, startx+length-52, starty+width-2);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(startx+length-51, starty+width/2-8, BLACK);
		line(startx, starty+8, startx+5, starty+8);                                         //Tail Lights
		line(startx+5, starty,startx+5, starty+8);
		setfillstyle(SOLID_FILL, LIGHTRED);
		floodfill(startx+3, starty+3, BLACK);
		line(startx, starty+width-8, startx+5, starty+width-8);
		line(startx+5, starty+width, startx+5, starty+width-8);
		setfillstyle(SOLID_FILL, LIGHTRED);
		floodfill(startx+3, starty+width-3, BLACK);
	}
	else if(road==2 && (lane==3 || lane==4)){
		line(startx, starty+5, startx, starty+width-5);                               //Main Body
		line(startx+length, starty+5, startx+length, starty+width-5);
		line(startx+length-5, starty, startx+5, starty);
		line(startx+length-5, starty+width, startx+5, starty+width);
		line(startx, starty+5, startx+5, starty);
		line(startx, starty+width-5, startx+5, starty+width);
		line(startx+length-5, starty, startx+length, starty+5);
		line(startx+length-5, starty+width,  startx+length, starty+width-5);
		setfillstyle(SOLID_FILL, COLOR(255, 4, 4));
		floodfill(startx+length/2, starty+width/2, COLOR(255, 4, 4));
		setcolor(BLACK);                                                            //Headlights
		line(startx+5, starty+width, startx+5, starty);
		line(startx, starty+7, startx+5, starty+7);
		line(startx, starty+width-7, startx+5,starty+width-7);
		setfillstyle(SOLID_FILL, WHITE);
		floodfill(startx+4, starty+4, BLACK);
		floodfill(startx+4, starty+width-4, BLACK);
		line(startx+20, starty+5, startx+7, starty+width/2-4);       //Engine Marks
		line(startx+20, starty+width-5, startx+7, starty+width/2+4);
		line(startx+23,starty+2, startx+23,starty+width-2);          //Windshield
		line(startx+33, starty+10 ,startx+33, starty+width-10);
		line(startx+23, starty+2,  startx+33, starty+10);
		line(startx+23,starty+width-2,startx+33,starty+width-10);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(startx+28, starty+width/2, BLACK); 
		line(startx+27, starty+2, startx+37,starty+10);                         //Windows
		line(startx+27, starty+width-2, startx+37, starty+width-10);
		line(startx+37, starty+10, startx+45, starty+10);
		line(startx+37, starty+width-10, startx+45, starty+width-10);
		line(startx+45, starty+10, startx+50, starty+2);
	    line(startx+45,starty+width-10,startx+50,starty+width-2);
		line(startx+27,starty+width-2,startx+50, starty+width-2);
		line(startx+27, starty+2,startx+50,starty+2);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(startx+37, starty+5, BLACK);
		floodfill(startx+37, starty+width-5, BLACK);
		line(startx+52, starty+2, startx+52, starty+width-2);                  //Rear Window
		line(startx+49,starty+10, startx+49, starty+width-10);
		line(startx+52, starty+2,startx+49, starty+10);
		line(startx+49, starty+width-10, startx+52, starty+width-2);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(startx+51, starty+width/2-8, BLACK);
		line(startx+length, starty+8, startx+length-5, starty+8);            //Tail Lights
		line(startx+length-5, starty,startx+length-5, starty+8);
		setfillstyle(SOLID_FILL, LIGHTRED);
		floodfill(startx+length-3, starty+3, BLACK);
		line(startx+length, starty+width-8, startx+length-5, starty+width-8);
		line(startx+length-5, starty+width, startx+length-5, starty+width-8);
		setfillstyle(SOLID_FILL, LIGHTRED);
		floodfill(startx+length-3, starty+width-3, BLACK);
	}

}


void erase_car(int startx, int starty, int road, int lane)
{
	setfillstyle(SOLID_FILL, BLACK);
	int width=30;
	int length=65;
	setfillstyle(SOLID_FILL, BLACK);
	if(road==2){
		if(lane==1 || lane==2){
			floodfill(startx+length-39, starty+width/2, BLACK); //Erasing Main body
			floodfill(startx+length-2, starty+width/2, BLACK);  //Erasing Radiator
			floodfill(startx+length-4, starty+4, BLACK);        //Erasing Headlights
			floodfill(startx+length-4, starty+width-4, BLACK);
			floodfill(startx+4, starty+4, BLACK);               //Erasing Taillights
			floodfill(startx+4, starty+width-4, BLACK);
		}
		else{
			floodfill(startx+39, starty+width/2, BLACK);        //Erasing Main body
			floodfill(startx+2, starty+width/2, BLACK);         //Erasing Radiator
			floodfill(startx+4, starty+4, BLACK);               //Erasing Headlights
			floodfill(startx+4, starty+width-4, BLACK);        
			floodfill(startx+length-4, starty+4, BLACK);               //Erasing Taillights
			floodfill(startx+length-4, starty+width-4, BLACK);
		}
	}
	else{
		if(lane==3 || lane==4){
			floodfill(startx+width/2, starty+length-39,BLACK); //Erasing Main body
			floodfill(startx+width/2, starty+length-2, BLACK); //Erasing Radiator 
			floodfill(startx+4, starty+length-4, BLACK);       //Erasing Headlights
			floodfill(startx+width-4, starty+length-4, BLACK);
			floodfill(startx+4, starty+4, BLACK);               //Erasing Taillights
			floodfill(startx+width-4, starty+4, BLACK);
		}
		else{
			floodfill(startx+width/2, starty+39,BLACK); //Erasing Main body
			floodfill(startx+width/2, starty+2, BLACK); //Erasing Radiator 
			floodfill(startx+4, starty+4, BLACK);       //Erasing Headlights
			floodfill(startx+width-4, starty+4, BLACK);
			floodfill(startx+4, starty+length-4, BLACK);               //Erasing Taillights
			floodfill(startx+width-4, starty+length-4, BLACK);
		}
	}
}

int lane_formatter(int road, int lane)
{
	if (road==1){
		if(lane== 4) return 700-37;
		else if(lane==3) return 600+13;
		else if(lane==1) return 500+13;
		else if(lane==2) return 550+13;
	}
	else{
		if(lane==1) return 213;
		else if(lane==2) return 263;
		else if(lane==3) return 313;
		else if(lane==4) return 363;
	}
}

void tilt_car(int croad, int clane)
{
	setcolor(COLOR(255, 4, 4));
	if(croad==2 && clane==1){
		int midx=500;
		int midy=200;
		line(485, 220, 520, 185);
		line(485, 225,485, 220);
		//line();
	}
	else if(croad==1 && clane==1){
		int midx=500;
		int midy=400;
		line(485, 380, 520, 415);
		line(485, 380, 485, 375);
	}
	else if(croad==2 && clane==4){
		int midx=700;
		int midy=400;
		line(680, 415, 715, 380);
		line(715, 380, 715, 375);
	}
	else if(croad==1 && clane==4){
		int midx=700;
		int midy=200;
		line(680, 185, 715, 220);
		line(715, 220, 715, 225);
	}
}

void menu(int x,int y)
{
	readimagefile("Poth.jpg",0,0,1200,600);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,20);
	outtextxy(x,y,"Welcome to NFS Pothchola\n");
	outtextxy(x,y + 50,"Press S to start New game\n");
	outtextxy(x,y + 100,"Press E to exit the game\n");
}
void move_straight(int road, int time) {
     int x,y,cnt = 0,z;
	 if(road == 1) {
		 x = lane_formatter(road,3);
		 int x1=lane_formatter(road,2);
		 for(y = - 50,z = 650; y <= 550 && z >= 0;y = y + 10,z = z - 10) {
			 draw_car(x,y,road,3);
			 draw_car(x1,z,road,2);
			 delay(time/2);
			 erase_car(x,y,road,3);
			 erase_car(x1,z,road,2);
			 
			  }
	 }
	 else{
		y=lane_formatter(road, 2);
		int y1 = lane_formatter(road,3);
		for(x = -50,z = 1250; x <= 1150 && z >= 0; x = x + 10,z = z - 10) {
			draw_car(x,y,road,2);
			draw_car(z,y1,road,3);
			delay(time/2);
			erase_car(x,y,road,2);
		     erase_car(z,y1,road,3);
		}



	 
	 }


}


void move_turn(int road, int time) {
	int x,y,z;



}

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

/*void erase(int x,int y) {
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

} */


void move_person(int x,int y,char pos) {
	


}










int main()
{
	initwindow(1200,600,"Pothchola Begins B|");
	int x,y,count = 0,time,movecnt = 0,savex,savey;
	x = getmaxx() / 2;
    y = getmaxy() / 2;
	
	menu(x,y);
	
	char a;
	a = getch();
	
	time = 40;
	if(a == 'S' || a == 's') {
    cleardevice();
	background();
	x = 150;
	y = 185;
	while(!kbhit()){
    move_straight(1,time);
	move_straight(2,time);
	count++;
	if(count == 3) {
		count = 0;
		time = time - 4;
		if(time <= 5) {
			time=8;
		}

	}
  //  if(movecnt > 0) {
	//erase(savex,savey);
	//}

	make_person(x,y);
	movecnt++;
	
	char pos;
	pos = getch();
	if(pos  == 's') {
		savex = x;
		savey = y;
		x = x + 10;
		y = y;
	}
	else if(pos == 'a') {
		savex = x;
		savey = y;
		x = x - 10;
		y = y;
	}
	else if(pos == 'w') {
		savex = x;
		savey = y;
		y = y - 10;
		x = x;
	}
	else if(pos == 'x') {
		savex = x;
		savey = y;
		y = y + 10;
		x = x;
	}


	
	//draw_car(700-37, 0+10, 1, 4);
	//draw_car(513, 520, 1, 1);
	//draw_car(10, 213, 2, 1);
	//draw_car(1013, 356, 2, 4);
	//tilt_car(2, 1);
	//tilt_car(2, 4);
	//tilt_car(1, 1);
	//tilt_car(1, 4);
	//delay(500);
	//erase_car(700-37, 0+10, 1, 4);
	//erase_car(513, 520, 1, 1);
	//erase_car(10, 213, 2, 1);
	//erase_car(1013, 356, 2, 4);
	//delay(500);
	}
}
	else {
		outtextxy(x,y + 150,"Thank you for playing this game\n");
		delay(1500);
        return 0;
}
	return 0;
}
