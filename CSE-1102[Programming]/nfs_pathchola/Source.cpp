#include "graphics.h"
#include "car.h"
#include "background.h"
#include "menu.h"
#include "person.h"
#include "Tokens.h"
#include "bomb.h"
#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int carcolor[]={YELLOW, COLOR(255, 4, 4), COLOR(0, 0, 255), COLOR(255, 153, 151), COLOR(255, 204, 229)};  // car color selection

struct token{
	int x;                                                                   // token structure
	int y;
	int type; 
	int drawn;
}t[15];

struct car{
	int x;
	int y;
	int color;                                                               //car structure
	int road;
	int lane;
}c[20];

int is_pos_valid(int x, int y){
	if(x<=470 && y<=170) return 0;                                         // valid positions
	if(x<=470 && y>=430) return 0;
	if(x>=730 && y<=170) return 0;
	if(x>=730 && y>=430) return 0;
	if(x<=0 || x>=1192) return 0;
	if(y<=0 || y>=592) return 0;
	return 1;
}

int manpos(int x, int y)
{
	if((x>=470 && x<=500) && (y>=0 && y<=200)) return 0;
	if((x>=700 && x<=730) && (y>=0 && y<=200)) return 1;
	if((x>=730 && x<=1200) && (y>=170 && y<=200)) return 2;
	if((x>=730 && x<=1200) && (y>=400 && y<=430)) return 3;                                  // MAN POSS DETECTION
	if((x>=700 && x<=730) && (y>=400 && y<=600)) return 4;
	if((x>=470 && x<=500) && (y>=400 && y<=600)) return 5;
	if((x>=0 && x<=500) && (y>=400 && y<=430)) return 6;
	if((x>=0 && x<=470) && (y>=170 && y<=200)) return 7;
	if(x>=500 && x<=550) return 11;
	if(x>=550 && x<=600) return 12;
	if(x>=600 && x<=650) return 13;
	if(x>=650 && x<=700) return 14;
	if(y>=200 && y<=250) return 21;
	if(y>=250 && y<=300) return 22;
	if(y>=300 && y<=350) return 23;
	if(y>=350 && y<=400) return 24;
}

double distance(int x1, int y1, int x2,int y2)
{                                                                                     
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);                                                            // DISTENCE EQN
}

int does_collide(int manx, int many, int bombx, int bomby)
{
	if((manx-bombx)==0){
		if(abs(many-bomby)<=18) return 1;                                                             //COLLISION FORMATION
	}
	else if((many-bomby)==0){
		if(abs(manx-bombx)<=13) return 1;
	}
	return 0;
}
int car_launcher(int manx, int many, int carcnt, int cardist[10][10], int window, int colorselect)
{
	int posman=manpos(manx, many);                                                                               // CAR LAUNCHER SELECTION
	if(carcnt<=2){
		if(posman==0){
			if(rand()%2){
				if(cardist[2][1]>=window){
					c[carcnt].road=2;
					c[carcnt].lane=1;
					c[carcnt].x=00;
					c[carcnt].y=lane_formatter(2, 1);
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[1][2]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=2;
					c[carcnt].x=lane_formatter(1, 2);
					c[carcnt].y=600;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[1][3]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=3;
					c[carcnt].x=lane_formatter(1, 3);
					c[carcnt].y=00;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
		}
		else if(posman==1){
			if(rand()%2){
				if(cardist[1][4]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=4;
					c[carcnt].x=lane_formatter(1, 4);
					c[carcnt].y=00;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[1][3]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=3;
					c[carcnt].x=lane_formatter(1, 3);
					c[carcnt].y=00;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
		}
		else if(posman==2){
			if(rand()%2){
				if(cardist[1][4]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=4;
					c[carcnt].x=lane_formatter(1, 4);
					c[carcnt].y=00;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[2][2]>=window){
					c[carcnt].road=2;
					c[carcnt].lane=2;
					c[carcnt].x=00;
					c[carcnt].y=lane_formatter(2, 2);
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[2][3]>=window){
					c[carcnt].road=2;
					c[carcnt].lane=3;
					c[carcnt].x=1200;
					c[carcnt].y=lane_formatter(2, 3);
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
		}
		else if(posman==3){
			if(rand()%2){
				if(cardist[2][3]>=window){
					c[carcnt].road=2;
					c[carcnt].lane=3;
					c[carcnt].x=1200;
					c[carcnt].y=lane_formatter(2, 3);
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[2][4]>=window){
					c[carcnt].road=2;
					c[carcnt].lane=4;
					c[carcnt].x=1200;
					c[carcnt].y=lane_formatter(2, 4);
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
		}
		else if(posman==4){
			if(rand()%2){
				if(cardist[2][4]>=window){
					c[carcnt].road=2;
					c[carcnt].lane=4;
					c[carcnt].x=1200;
					c[carcnt].y=lane_formatter(2, 4);
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[1][3]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=3;
					c[carcnt].x=lane_formatter(1, 3);
					c[carcnt].y=00;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[1][2]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=2;
					c[carcnt].x=lane_formatter(1, 2);
					c[carcnt].y=600;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
		}
		else if(posman==5){
			if(rand()%2){
				if(cardist[1][1]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=1;
					c[carcnt].x=lane_formatter(1, 1);
					c[carcnt].y=600;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[1][2]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=2;
					c[carcnt].x=lane_formatter(1, 2);
					c[carcnt].y=600;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
		}
		else if(posman==6){
			if(rand()%2){
				if(cardist[1][1]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=1;
					c[carcnt].x=lane_formatter(1, 1);
					c[carcnt].y=600;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[2][3]>=window){
					c[carcnt].road=2;
					c[carcnt].lane=3;
					c[carcnt].x=1200;
					c[carcnt].y=lane_formatter(2, 3);
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[2][2]>=window){
					c[carcnt].road=2;
					c[carcnt].lane=2;
					c[carcnt].x=0;
					c[carcnt].y=lane_formatter(2, 2);
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
		}
		else if(posman==7){
			if(rand()%2){
				if(cardist[2][1]>=window){
					c[carcnt].road=2;
					c[carcnt].lane=1;
					c[carcnt].x=0;
					c[carcnt].y=lane_formatter(2, 1);
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[2][2]>=window){
					c[carcnt].road=2;
					c[carcnt].lane=2;
					c[carcnt].x=0;
					c[carcnt].y=lane_formatter(2, 2);
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
		}
		//Road
		else if(posman==11){
			if(rand()%2){
				if(cardist[2][1]>=window){
					c[carcnt].road=2;
					c[carcnt].lane=1;
					c[carcnt].x=0;
					c[carcnt].y=lane_formatter(2, 1);
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[1][2]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=2;
					c[carcnt].x=lane_formatter(1, 2);
					c[carcnt].y=600;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[1][1]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=1;
					c[carcnt].x=lane_formatter(1, 1);
					c[carcnt].y=600;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
		}
		else if(posman==12){
			if(rand()%2){
				if(cardist[1][2]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=2;
					c[carcnt].x=lane_formatter(1, 2);
					c[carcnt].y=600;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[1][3]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=3;
					c[carcnt].x=lane_formatter(1, 3);
					c[carcnt].y=00;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
		}
		else if(posman==13){
			if(rand()%2){
				if(cardist[1][3]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=3;
					c[carcnt].x=lane_formatter(1, 3);
					c[carcnt].y=00;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[1][4]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=4;
					c[carcnt].x=lane_formatter(1, 4);
					c[carcnt].y=00;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
		}
		else if(posman==14){
			if(rand()%2){
				if(cardist[1][3]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=3;
					c[carcnt].x=lane_formatter(1, 3);
					c[carcnt].y=00;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[1][4]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=4;
					c[carcnt].x=lane_formatter(1, 4);
					c[carcnt].y=0;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[2][4]>=window){
					c[carcnt].road=2;
					c[carcnt].lane=4;
					c[carcnt].x=1200;
					c[carcnt].y=lane_formatter(2, 4);
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
		}
		else if(posman==21){
			if(rand()%2){
				if(cardist[2][1]>=window){
					c[carcnt].road=2;
					c[carcnt].lane=1;
					c[carcnt].x=00;
					c[carcnt].y=lane_formatter(2, 1);
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[1][4]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=4;
					c[carcnt].x=lane_formatter(1, 4);
					c[carcnt].y=00;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[2][2]>=window){
					c[carcnt].road=2;
					c[carcnt].lane=2;
					c[carcnt].x=0;
					c[carcnt].y=lane_formatter(2, 2);
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
		}
		else if(posman==22 || posman==23){
			if(rand()%2){
				if(cardist[2][2]>=window){
					c[carcnt].road=2;
					c[carcnt].lane=2;
					c[carcnt].x=0;
					c[carcnt].y=lane_formatter(2, 2);
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[2][3]>=window){
					c[carcnt].road=2;
					c[carcnt].lane=3;
					c[carcnt].x=1200;
					c[carcnt].y=lane_formatter(2, 3);
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
		}
		else if(posman==24){
			if(rand()%2){
				if(cardist[2][4]>=window){
					c[carcnt].road=2;
					c[carcnt].lane=4;
					c[carcnt].x=1200;
					c[carcnt].y=lane_formatter(2, 4);
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[2][3]>=window){
					c[carcnt].road=2;
					c[carcnt].lane=3;
					c[carcnt].x=1200;
					c[carcnt].y=lane_formatter(2, 3);
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
			if(rand()%2){
				if(cardist[1][1]>=window){
					c[carcnt].road=1;
					c[carcnt].lane=1;
					c[carcnt].x=lane_formatter(1, 1);
					c[carcnt].y=600;
					if(colorselect==-1) c[carcnt].color=carcolor[rand()%5];
					else c[carcnt].color=carcolor[colorselect];
					carcnt++;
				}
			}
		}
	}
	return carcnt;
}

int move_car(int carcnt, int cardist[10][10], int carspeed)
{
	int i, l1, l2;
	for(i=0; i<carcnt; i++){
		for(l1=1; l1<=3; l1++){
			for(l2=1; l2<=5; l2++){
				cardist[l1][l2]=100000;
			}
		}
		if(c[i].road==1){
				if(c[i].lane==3 && c[i].road==1){
					erase_car(c[i].x, c[i].y, c[i].road, c[i].lane);
					c[i].y+=carspeed;
					draw_car(c[i].x, c[i].y, c[i].road, c[i].lane, c[i].color);
					//cardist[1][3]=min(c[i].y, cardist[1][3]);
					cardist[1][3]=c[i].y;
				}
				else if(c[i].lane==2 && c[i].road==1){
					erase_car(c[i].x, c[i].y, c[i].road, c[i].lane);
					c[i].y-=carspeed;
					draw_car(c[i].x, c[i].y, c[i].road, c[i].lane, c[i].color);
					//cardist[1][2]=min(600-c[i].y, cardist[1][2]);
					cardist[1][2]=600-c[i].y;
				}
				else if(c[i].lane==1 && c[i].road==1){
					if((c[i].y<=170 || c[i].y>=430)){
						erase_car(c[i].x, c[i].y, c[i].road, c[i].lane);
						c[i].y-=carspeed;
						draw_car(c[i].x, c[i].y, c[i].road, c[i].lane, c[i].color);
						//cardist[1][1]=min(600-c[i].y, cardist[1][1]);
						cardist[1][1]=600-c[i].y;
					}
					else{
						erase_car(c[i].x, c[i].y, c[i].road, c[i].lane);
						tilt_car(1, 1, c[i].color);
						delay(50);
						erase_tilt(c[i].road, c[i].lane);
						c[i].road=2;
						c[i].lane=4;
						c[i].x=470;
						c[i].y=lane_formatter(c[i].road, c[i].lane);
					}

				}
				else if(c[i].lane==4 && c[i].road==1){
					if((c[i].y<=170 || c[i].y>=430)){
						erase_car(c[i].x, c[i].y, c[i].road, c[i].lane);
						c[i].y+=carspeed;
						draw_car(c[i].x, c[i].y, c[i].road, c[i].lane, c[i].color);
						//cardist[1][4]=min(c[i].y, cardist[1][4]);
						cardist[1][4]=c[i].y;
					}
					else{
						erase_car(c[i].x, c[i].y, c[i].road, c[i].lane);
						tilt_car(1, 4, c[i].color);
						delay(20);
						erase_tilt(c[i].road, c[i].lane);
						c[i].road=2;
						c[i].lane=1;
						c[i].x=730;
						c[i].y=lane_formatter(c[i].road, c[i].lane);
					}	
				}
			}
			else if(c[i].road==2){
				if(c[i].road==2 && c[i].lane==3){
					erase_car(c[i].x, c[i].y, c[i].road, c[i].lane);
					c[i].x-=carspeed;
					draw_car(c[i].x, c[i].y, c[i].road, c[i].lane, c[i].color);
					//cardist[2][3]=min(1200-c[i].x, cardist[2][3]);
					cardist[2][3]=1200-c[i].x;
				}
				else if(c[i].road==2 && c[i].lane==2){
					erase_car(c[i].x, c[i].y, c[i].road, c[i].lane);
					c[i].x+=carspeed;
					draw_car(c[i].x, c[i].y, c[i].road, c[i].lane, c[i].color);
					//cardist[2][2]=min(c[i].x, cardist[2][2]);
					cardist[2][2]=c[i].x;
				}
				else if(c[i].road==2 && c[i].lane==1){
					if((c[i].x<=470 || c[i].x>=730)){
						erase_car(c[i].x, c[i].y, c[i].road, c[i].lane);
						c[i].x+=carspeed;
						draw_car(c[i].x, c[i].y, c[i].road, c[i].lane, c[i].color);
						//cardist[2][1]=min(c[i].x, cardist[2][1]);
						cardist[2][1]=c[i].x;

					}
					else{
						erase_car(c[i].x, c[i].y, c[i].road, c[i].lane);
						tilt_car(2, 1, c[i].color);
						delay(20);
						erase_tilt(c[i].road, c[i].lane);
						c[i].road=1;
						c[i].lane=1;
						c[i].x=lane_formatter(c[i].road, c[i].lane);
						c[i].y=170;
						
					}

				}
				else if(c[i].road==2 && c[i].lane==4){
					
					if((c[i].y<=470 || c[i].y>=730)){
						erase_car(c[i].x, c[i].y, c[i].road, c[i].lane);
						c[i].x-=carspeed;
						draw_car(c[i].x, c[i].y, c[i].road, c[i].lane, c[i].color);
						//cardist[2][4]=min(1200-c[i].x, cardist[2][4]);
						cardist[2][4]=1200-c[i].x;
					}
					else{
						erase_car(c[i].x, c[i].y, c[i].road, c[i].lane);
						tilt_car(2, 4, c[i].color);
						delay(50);
						erase_tilt(c[i].road, c[i].lane);
						c[i].road=1;
						c[i].lane=4;
						c[i].x=lane_formatter(c[i].road, c[i].lane);
						c[i].y=430;
					}	
				}
			}
			int k;
			if(c[i].road==1 && (c[i].lane==1 || c[i].lane==2)){
				if(c[i].y<=-150){
					for(k=i+1; k<carcnt; k++){
						c[k-1]=c[k];
					}
					carcnt--;
					int rec[]={505, 0, 545, 0, 545, 100, 505, 100};
					int rec1[]={553, 0, 595, 0, 595, 100, 553, 100};
					setfillstyle(SOLID_FILL, BLACK);
					fillpoly(4, rec);
					fillpoly(4, rec1);
				}
			}
			else if(c[i].road==1 && (c[i].lane==3 || c[i].lane==4)){
				if(c[i].y>=750){
					//printf("%d %d 13\n", c[i].road, c[i].lane);
					int rec[]={605, 600, 645, 600, 645, 550, 605, 550};
					int rec1[]={653, 600, 695, 600, 695, 550, 653, 550};
					for(k=i+1; k<carcnt; k++){
						c[k-1]=c[k];
					}
					carcnt--;
					setfillstyle(SOLID_FILL, BLACK);
					fillpoly(4, rec);
					fillpoly(4, rec1);
				}
			}
			else if(c[i].road==2 && (c[i].lane==1 || c[i].lane==2)){
				if(c[i].x>=1350){
					//printf("%d %d 21\n", c[i].road, c[i].lane);
					for(k=i+1; k<carcnt; k++){
						c[k-1]=c[k];
					}
					carcnt--;
					int rec[]={1100, 205, 1100, 245, 1200, 245, 1200, 205};
					int rec1[]={1200, 253, 1200, 295, 1100, 295, 1100, 253};
					setfillstyle(SOLID_FILL, BLACK);
					fillpoly(4, rec);
					fillpoly(4, rec1);
				}
			}
			else if(c[i].road==2 && (c[i].lane==3 || c[i].lane==4)){
				if(c[i].x<=-150){
					//printf("%d %d 23\n", c[i].road, c[i].lane);
					for(k=i+1; k<carcnt; k++){
						c[k-1]=c[k];
					}
					carcnt--;
					
					int rec[]={0, 305, 0, 345, 100, 345, 100, 305};
					int rec1[]={0, 353, 0, 395, 100, 395, 100, 353};
					
					setfillstyle(SOLID_FILL, BLACK);
					fillpoly(4, rec);
					fillpoly(4, rec1);
				}
			}
	}
	return carcnt;
}
int main()
{
	initwindow(1200,600,"Pothchola Begins B|");
	menu(600,300);
	char a;
	a = getch();
	if(a == 'S' || a == 's') {
		cleardevice();
		background(1);
		//tilt_car(2, 4, COLOR(255, 0, 0));
		int duration=0, carcnt=0, manx=25, many=185, tokentype[20], i, j, remaining_coins;
		int cardist[10][10]={{0}}, carspeed=10, window=515;
		int maninc=23, poschanged;
		int mode=0;
		int bombx, bomby, bombflag=0;
		int crossings=0, activator=0;
		int colorselect=-1;
		int quitflag=0;
		char command, escpause;
		for(i=1; i<=3; i++){
			for(j=1; j<=5; j++){
				cardist[i][j]=1400;
			}
		}
		for(i=0; i<=9; i++){  //  correct korlam   
			t[i].drawn=-1;
			tokentype[i]=0;
			//t[i].x = 0;
			//t[i].y = 0;
			//t[i].type = 0;
			
		}
		
		tokentype[5]=2;
		tokentype[3]=1;
		remaining_coins=0;
		make_person(manx, many, mode);
		
		while(!quitflag){
			printf("ase 3\n");
			poschanged=0;
			if(crossings){
				erase_bomb(bombx, bomby);
				bombflag=0;
				mode=0;
				crossings=0;
			}
			if(remaining_coins==0){
				if(t[0].drawn==-1){
					t[0].x=485;
					t[0].y=(rand()%(170-16))+8;
				}
				if(t[1].drawn==-1){
					t[1].x=715;
					t[1].y=(rand()%(170-16))+8;
				}
				if(t[2].drawn==-1){
					t[2].x=(rand()%(1200-16-730))+730+8;
					t[2].y=185;
				}
				if(t[3].drawn==-1){
					t[3].x=(rand()%(1200-730-16))+738;
					t[3].y=415;
				}
				if(t[4].drawn==-1){
					t[4].x=715;
					t[4].y=(rand()%(600-16-430))+438;
				}
				if(t[5].drawn==-1){
					t[5].x=485;
					t[5].y=(rand()%(600-16-430))+438;
				}
				if(t[6].drawn==-1){
					t[6].x=(rand()%(470-16))+8;
					t[6].y=415;
				}
				if(t[7].drawn==-1){
					t[7].x=(rand()%(470-16))+8;
					t[7].y=185;
				}
			printf("ase 1\n");
				for(i=0; i<8; i++){
						if(t[i].drawn==-1){
						t[i].type=tokentype[rand()%10];
						if(t[i].type==0){ 
							coin(t[i].x, t[i].y);
							remaining_coins++;
						}
						else if(t[i].type==1)   king(t[i].x, t[i].y); 

						else if(t[i].type==2)  flash(t[i].x, t[i].y);  
						t[i].drawn=1; 
					}
					printf("%d i\n",i);
				}
				
	
			}

			printf("ase 2\n");
			if(bombflag==0){
				if(manpos(manx, many)==0){
					if(t[7].drawn==1){
						bomby=185;
						bombx=t[7].x+18+(rand()%(485-t[7].x-18));
						bombflag=1;
					                                                                           

					}

					else if(t[1].drawn==1){
						bombx=715;
						if((many-18)>=(t[1].y+18))bomby=t[1].y+18+(rand()%(185-t[1].y-18));
						else bomby=(rand()%(t[1].y-many-36))+many;
						bombflag=1;					
					}
					else if(t[5].drawn==1){
						bombx=485;
						bomby=415+(rand()%(t[5].y-18-415));
						bombflag=1;
					}
					else if(t[6].drawn==1){
						bomby=415;
						bombx=t[6].x+18+(rand()%(485-t[6].x-18));
						bombflag=1;
					}
					else if(t[2].drawn==1){
						bombx=715;
						bomby=415+(rand()%(t[4].y-18-415));
						bombflag=1;
					}
					else{
						bomby=415;
						bombx=715+(rand()%(t[3].x-18-715));
						bombflag=1;
					}
				}
				else if(manpos(manx, many)==1){
					if(t[2].drawn==1){
						bomby=185;
						bombx=715+(rand()%(t[2].x-18-715));
						bombflag=1;
					}
					else if(t[0].drawn==1){
						bombx=485;
						if((many-18)>=(bomby+18))bomby=t[0].y+18+(rand()%(185-t[0].y-18));
						else bomby=(rand()%(t[0]).y-many-36)+many;
						bombflag=1;
					}
					else if(t[4].drawn==1){
						bombx=715;
						bomby=415+(rand()%(t[4].y-18-415));
						bombflag=1;
					}
					else if(t[3].drawn==1){
						bomby=415;
						bombx=715+(rand()%(t[3].x-18-715));
						bombflag=1;
					}
					else if(t[7].drawn==1){
						bomby=185;
						bombx=t[7].x+18+(rand()%(485-t[7].x-18));
						bombflag=1;
					}
					else{
						bombx=485;
						bomby=415+(rand()%(t[5].y-18-415));
						bombflag=1;
					}
				}
				else if(manpos(manx, many)==2){
					if(t[1].drawn==1){
						bombx=715;
						bomby=t[1].y+18+(rand()%(185-t[1].y-18));
						bombflag=1;
					}
					else if(t[3].drawn==1){
						bomby=415;
						if((manx+18)<(t[3].x-18))	bombx=715+(rand()%(t[3].x-18-715));
						else bombx=rand()%(1200-(t[3].x+18))+t[3].x;
						bombflag=1;
					}
					else if(t[4].drawn==1){
						bombx=715;
						bomby=415+(rand()%(t[4].y-18-415));
						bombflag=1;
					}
					else if(t[7].drawn==1){
						bomby=185;
						bombx=t[7].x+18+(rand()%(485-t[7].x-18));
						bombflag=1;					
					}
					else if(t[0].drawn==1){
						bombx=485;
						bomby=t[0].y+18+(rand()%(185-t[0].y-18));
						bombflag=1;
					}
					else{
						bombx=485;
						bomby=415+(rand()%(t[5].y-18-415));
						bombflag=1;
					}
				}
				else if(manpos(manx, many)==3){
					if(t[4].drawn==1){
						bombx=715;
						bomby=415+(rand()%(t[4].y-18-415));
						bombflag=1;
					}
					else if(t[2].drawn==1){
						bomby=185;
						bombx=715+(rand()%(t[2].x-18-715));
						bombflag=1;
					}
					else if(t[6].drawn==1){
						bomby=415;
						bombx=t[6].x+18+(rand()%(485-t[6].x-18));
						bombflag=1;
					}
					else if(t[1].drawn==1){
						bombx=715;
						bomby=t[1].y+18+(rand()%(185-t[1].y-18));
						bombflag=1;
					}
					else if(t[5].drawn==1){
						bombx=485;
						bomby=415+(rand()%(t[5].y-18-415));
						bombflag=1;
					}
					else{
						bombx=485;
						bomby=t[0].y+18+(rand()%(185-t[0].y-18));
						bombflag=1;
					}
				}
				else if(manpos(manx, many)==4){
					if(t[3].drawn==1){
						bomby=415;
						bombx=715+(rand()%(t[3].x-18-715));
						bombflag=1;
					}
					else if(t[5].drawn==1){
						bombx=485;
						if((t[5].y-18)>=(many+18)) bomby=415+(rand()%(t[5].y-18-415));
						else bomby=t[5].y+18+rand()%(many-t[5].y-36);
						bombflag=1;
					}
					else if(t[1].drawn==1){
						bombx=715;
						bomby=t[1].y+18+(rand()%(185-t[1].y-18));
						bombflag=1;
					}
					else if(t[6].drawn==1){
						bomby=415;
						bombx=t[6].x+18+(rand()%(485-t[6].x-18));
						bombflag=1;
					}
					else if(t[2].drawn==1){
						bomby=185;
						bombx=715+(rand()%(t[2].x-18-715));
						bombflag=1;
					}
					else{
						bombx=485;
						bomby=t[0].y+18+(rand()%(185-t[0].y-18));
						bombflag=1;
					}
				}
				else if(manpos(manx, many)==5){
					if(t[6].drawn==1){
						bomby=415;
						bombx=t[6].x+18+(rand()%(485-t[6].x-18));
						bombflag=1;
					}
					else if(t[4].drawn==1){
						bombx=715;
						if((t[4].y-18)>=(many+18)) bomby=415+(rand()%(t[4].y-18-415));
						else bomby=t[4].y+18+rand()%(many-t[4].y-36);
						bombflag=1;
					}
					else if(t[0].drawn==1){
						bombx=485;
						bomby=t[0].y+18+(rand()%(185-t[0].y-18));
						bombflag=1;
					}
					else if(t[3].drawn==1){
						bomby=415;
						bombx=715+(rand()%(t[3].x-18-715));
						bombflag=1;
					}
					else if(t[7].drawn==1){
						bomby=185;
						bombx=t[7].x+18+(rand()%(485-t[7].x-18));
						bombflag=1;
					}
					else{
						bombx=715;
						bomby=t[1].y+18+(rand()%(185-t[1].y-18));
						bombflag=1;
					}
				}
				else if(manpos(manx, many)==6){
					if(t[5].drawn==1){
						bombx=485;
						bomby=415+(rand()%(t[5].y-18-415));
						bombflag=1;
					}
					else if(t[7].drawn==1){
						bomby=185;
						if((manx-18)>=(t[7].x+18))bombx=t[7].x+18+(rand()%(485-t[7].x-18));
						else bombx=rand()%(t[7].x);
						bombflag=1;
					}
					else if(t[0].drawn==1){
						bombx=485;
						bomby=t[0].y+18+(rand()%(185-t[0].y-18));
						bombflag=1;
					}
					else if(t[3].drawn==1){
						bomby=415;
						bombx=715+(rand()%(t[3].x-18-715));
						bombflag=1;
					}
					else if(t[4].drawn==1){
						bombx=715;
						bomby=415+(rand()%(t[4].y-18-415));
						bombflag=1;
					}
					else{
						bomby=185;
						bombx=715+(rand()%(t[2].x-18-715));
						bombflag=1;
					}
				}
				else if(manpos(manx, many)==7){
					if(t[0].drawn==1){
						bombx=485;
						bomby=t[0].y+18+(rand()%(185-t[0].y-18));
						bombflag=1;
					}
					else if(t[6].drawn==1){
						bomby=415;
						if((manx-18)>=(t[7].x+18))bombx=t[7].x+18+(rand()%(485-t[7].x-18));
						else bombx=rand()%(t[7].x);
						bombflag=1;
					}
					else if(t[2].drawn==1){
						bomby=185;
						bombx=715+(rand()%(t[2].x-18-715));
						bombflag=1;
					}
					else if(t[5].drawn==1){
						bombx=485;
						bomby=415+(rand()%(t[5].y-18-415));
						bombflag=1;
					}
					else if(t[1].drawn==1){
						bombx=715;
						bomby=t[1].y+18+(rand()%(185-t[1].y-18));
						bombflag=1;
					}
					else{
						bombx=715;
						bomby=415+(rand()%(t[4].y-18-415));
						bombflag=1;
					}
				}
			}
			carcnt=car_launcher(manx, many, carcnt, cardist, window, colorselect);
			carcnt=move_car(carcnt, cardist,  carspeed);
			if(bombflag==1) draw_bomb(bombx, bomby);
			if(kbhit()){
			while(kbhit()) command=getch();
				int cnt, rep;
				if(mode==1) rep=3;
				else rep=1;
				for(cnt=0; cnt<rep && !quitflag; cnt++){
					if(command==KEY_UP){
						erase_person(manx, many);
						if(is_pos_valid(manx, many-maninc)){
							many-=maninc;
							poschanged=1;
						}
						make_person(manx, many, mode);
					}
					else if(command==KEY_DOWN){
						erase_person(manx, many);
						if(is_pos_valid(manx, many+maninc)){
							many+=maninc;
							poschanged=1;
						}	
							make_person(manx, many, mode);
					}
					else if(command==KEY_LEFT){
						erase_person(manx, many);
						if(is_pos_valid(manx-maninc, many)){
							manx-=maninc;
							poschanged=1;
						}
						make_person(manx, many, mode);
					}
					else if(command==KEY_RIGHT){
						erase_person(manx, many);
						if(is_pos_valid(manx+maninc, many)){
							manx+=maninc;
							poschanged=1;
						}	
						make_person(manx, many, mode);
					}
					else if(command==13 || command==' '){
						while(1){
							while(!kbhit());
							escpause=getch();
							if(escpause==13 || escpause==' ' || escpause==27){ 
								break;
							}
						}
					}
					else if(command==27){
						quitflag=1;
						break;
					}
					if(manpos(manx, many)<8 && manpos(manx, many)>=0 && poschanged && t[manpos(manx, many)].drawn==1){
						if(distance(t[manpos(manx, many)].x, t[manpos(manx, many)].y, manx, many)<=(16*16)){
							if(t[manpos(manx, many)].type==0){ 
								erase_coin(t[manpos(manx, many)].x, t[manpos(manx, many)].y);
								make_person(manx, many, mode);
								remaining_coins--;
							}
							else if(t[manpos(manx, many)].type==1){ 
								erase_king(t[manpos(manx, many)].x, t[manpos(manx, many)].y);
								make_person(manx, many, mode);
								mode=2;
							}
							else if(t[manpos(manx, many)].type==2){ 
								erase_flash(t[manpos(manx, many)].x, t[manpos(manx, many)].y);
								make_person(manx, many, mode);
								mode=1;
							}
							t[manpos(manx, many)].drawn=-1;
						}
					}
					if(manpos(manx, many)<=7 && manpos(manx, many)>=0){
						if(activator==1){
								crossings=1;
								activator=0;
						}
					}
					else activator=1;
				}
			}
			if(does_collide(manx, many, bombx, bomby)){
						explode(bombx, bomby);
						break;
			}

			if(duration%10000==0){ 
				if(carspeed<50)carspeed+=10;
				if(window>85) window-=5;
			}
			
			delay(20);
			duration+=50;
		}
	}
	
	else{
		outtextxy(600,300 + 150,"Thank you for playing this game\n");
		delay(1500);
	}
	return 0;
}


