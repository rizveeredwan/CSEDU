#include "graphics.h"
#include "car.h"
#include "background.h"
#include "menu.h"
#include "person.h"
void move_straight(int road, int time) {
     int x,y,cnt = 0,z;
	 if(road == 1) {
		 x = lane_formatter(road,3);
		 int x1=lane_formatter(road,2);
		 for(y = - 50,z = 650; y <= 550 && z >= 0;y = y + 10,z = z - 10) {
			 draw_car(x,y,road,3, COLOR(255, 4, 4));
			 draw_car(x1,z,road,2, COLOR(255, 4, 4));
			 delay(time/2);
			 erase_car(x,y,road,3);
			 erase_car(x1,z,road,2);
		}
	 }
	 else{
		y=lane_formatter(road, 2);
		int y1 = lane_formatter(road,3);
		for(x = -50,z = 1250; x <= 1150 && z >= 0; x = x + 10,z = z - 10) {
			draw_car(x,y,road,2, COLOR(255, 4, 4));
			draw_car(z,y1,road,3, COLOR(255, 4, 4));
			delay(time/2);
			erase_car(x,y,road,2);
    	    erase_car(z,y1,road,3);
		}



	 
	 }


}


void move_turn(int road, int time) {
	int x,y,z;



}



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
    tilt_car(1, 1, COLOR(255, 4, 4));
	tilt_car(2, 1, COLOR(255, 4, 4));
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

	}
}
	else {
		outtextxy(x,y + 150,"Thank you for playing this game\n");
		delay(1500);
        return 0;
}
	return 0;
}


