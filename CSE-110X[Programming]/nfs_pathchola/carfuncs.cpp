#include "graphics.h"
void draw_car(int startx, int starty, int road, int lane, int color)
{
	int width=30;
	int length=65;
	setcolor(color);
	if((road==1) && (lane==3 || lane==4)){
		line(startx+5, starty, startx+width-5, starty);                           //Main Body
		line(startx+5, starty+length, startx+width-5, starty+length);
		line(startx, starty+length-5, startx, starty+5);
		line(startx+width, starty+length-5, startx+width, starty+5);
		line(startx+5, starty, startx, starty+5);
		line(startx+width-5, starty, startx+width, starty+5);
		line(startx, starty+length-5, startx+5, starty+length);
		line(startx+width, starty+length-5, startx+width-5, starty+length);
		setfillstyle(SOLID_FILL, color);
		floodfill(startx+width/2, starty+length/2, color);
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
		setfillstyle(SOLID_FILL, color);
		floodfill(startx+width/2, starty+length/2, color);
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
		setfillstyle(SOLID_FILL, color);
		floodfill(startx+length/2, starty+width/2, color);
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
		setfillstyle(SOLID_FILL, color);
		floodfill(startx+length/2, starty+width/2, color);
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

void tilt_car(int croad, int clane, int color)
{
	setcolor(color);
	if(croad==2 && clane==1){
		int poly[]={485, 220, 520, 185, 525, 185, 545, 190, 545, 195, 510, 230, 505, 230, 485, 225};
		int hl1[]={520, 185, 525, 185, 522, 190};
		int hl2[]={545, 195, 545, 190, 540, 192};
		int tl1[]={485, 220, 490, 222, 485, 225};
		int tl2[]={505, 230, 507, 227, 510, 230};
		int gl[]={515, 195, 535, 200, 515, 220, 495, 215};
		int rf[]={504, 211, 515, 201,526, 204, 515, 214};
		setfillstyle(SOLID_FILL, color);
		fillpoly(8, poly);
		setfillstyle(SOLID_FILL, WHITE);
		fillpoly(3, hl1);
		fillpoly(3, hl2);
		setfillstyle(SOLID_FILL, LIGHTRED);		
		fillpoly(3, tl1);
		fillpoly(3, tl2);
		setfillstyle(SOLID_FILL, BLACK);
		fillpoly(4, gl);
		setfillstyle(SOLID_FILL, color);
		fillpoly(4, rf);
	}
	else if(croad==1 && clane==1){
		int poly[]={485, 380, 485, 375, 505, 370, 510, 370, 545, 405, 545, 410, 525, 415, 520, 415};
		int hl1[]={485, 380, 485, 375, 490, 378};
		int hl2[]={505, 370, 510, 370, 508,375};
		int tl1[]={520, 415, 525, 415, 523, 410};
		int tl2[]={545, 405, 545, 410, 540, 408};
		int gl[]={495, 385, 515, 380, 535, 400, 515, 405};
		int rf[]={505, 389, 515, 386, 525, 396, 515, 399};
		setfillstyle(SOLID_FILL, color);
		fillpoly(8, poly);
		setfillstyle(SOLID_FILL, WHITE);
		fillpoly(3, hl1);
		fillpoly(3, hl2);
		setfillstyle(SOLID_FILL, LIGHTRED);		
		fillpoly(3, tl1);
		fillpoly(3, tl2);
		setfillstyle(SOLID_FILL, BLACK);
		fillpoly(4, gl);
		setfillstyle(SOLID_FILL, color);
		fillpoly(4, rf);
	}
	else if(croad==1 && clane==4){
		int poly[]={485, 380, 485, 375, 505, 370, 510, 370, 545, 405, 545, 410, 525, 415, 520, 415};
		int hl1[]={485, 380, 485, 375, 490, 378};
		int hl2[]={505, 370, 510, 370, 508,375};
		int tl1[]={520, 415, 525, 415, 523, 410};
		int tl2[]={545, 405, 545, 410, 540, 408};
		int gl[]={495, 385, 515, 380, 535, 400, 515, 405};
		int rf[]={505, 389, 515, 386, 525, 396, 515, 399};
		int i;
		for(i=0; i<16; i++){
			if(i%2==0){
				poly[i]+=175;
				if(i<6){
					hl1[i]+=175;
					hl2[i]+=175;
					tl1[i]+=175;
					tl2[i]+=175;
				}
				if(i<8){
					gl[i]+=175;
					rf[i]+=175;
				}
			}
			else{
				poly[i]-=180;
				if(i<6){
					hl1[i]-=180;
					hl2[i]-=180;
					tl1[i]-=180;
					tl2[i]-=180;
				}
				if(i<8){
					gl[i]-=180;
					rf[i]-=180;
				}
			}
		}
		setfillstyle(SOLID_FILL, color);
		fillpoly(8, poly);
		setfillstyle(SOLID_FILL, LIGHTRED);
		fillpoly(3, hl1);
		fillpoly(3, hl2);
		setfillstyle(SOLID_FILL, WHITE);		
		fillpoly(3, tl1);
		fillpoly(3, tl2);
		setfillstyle(SOLID_FILL, BLACK);
		fillpoly(4, gl);
		setfillstyle(SOLID_FILL, color);
		fillpoly(4, rf);
	}
	else if(croad==2 && clane==4){
		int poly[]={485, 220, 520, 185, 525, 185, 545, 190, 545, 195, 510, 230, 505, 230, 485, 225};
		int hl1[]={520, 185, 525, 185, 522, 190};
		int hl2[]={545, 195, 545, 190, 540, 192};
		int tl1[]={485, 220, 490, 222, 485, 225};
		int tl2[]={505, 230, 507, 227, 510, 230};
		int gl[]={515, 195, 535, 200, 515, 220, 495, 215};
		int rf[]={504, 211, 515, 201,526, 204, 515, 214};
		int i;
		for(i=0; i<16; i++){
			if(i%2==0){
				poly[i]+=175;
				if(i<6){
					hl1[i]+=175;
					hl2[i]+=175;
					tl1[i]+=175;
					tl2[i]+=175;
				}
				if(i<8){
					gl[i]+=175;
					rf[i]+=175;
				}
			}
			else{
				poly[i]+=180;
				if(i<6){
					hl1[i]+=180;
					hl2[i]+=180;
					tl1[i]+=180;
					tl2[i]+=180;
				}
				if(i<8){
					gl[i]+=180;
					rf[i]+=180;
				}
			}
		}
		setfillstyle(SOLID_FILL, color);
		fillpoly(8, poly);
		setfillstyle(SOLID_FILL, LIGHTRED);
		fillpoly(3, hl1);
		fillpoly(3, hl2);
		setfillstyle(SOLID_FILL, WHITE);		
		fillpoly(3, tl1);
		fillpoly(3, tl2);
		setfillstyle(SOLID_FILL, BLACK);
		fillpoly(4, gl);
		setfillstyle(SOLID_FILL, color);
		fillpoly(4, rf);
	}
	
}
void erase_tilt(int croad, int clane)
{
	if(croad==1){
			int poly[]={485, 380, 485, 375, 505, 370, 510, 370, 545, 405, 545, 410, 525, 415, 520, 415};
			int hl1[]={485, 380, 485, 375, 490, 378};
			int hl2[]={505, 370, 510, 370, 508,375};
			int tl1[]={520, 415, 525, 415, 523, 410};
			int tl2[]={545, 405, 545, 410, 540, 408};
			int gl[]={495, 385, 515, 380, 535, 400, 515, 405};
			int rf[]={505, 389, 515, 386, 525, 396, 515, 399};
			if(clane==4){
				int i;
				for(i=0; i<16; i++){
					if(i%2==0){
						poly[i]+=175;
						if(i<6){
							hl1[i]+=175;
							hl2[i]+=175;
							tl1[i]+=175;
							tl2[i]+=175;
						}
						if(i<8){
							gl[i]+=175;
							rf[i]+=175;
						}
					}	
					else{
						poly[i]-=180;
						if(i<6){
							hl1[i]-=180;
							hl2[i]-=180;
							tl1[i]-=180;
							tl2[i]-=180;
						}
						if(i<8){
							gl[i]-=180;
							rf[i]-=180;
						}
					}
				}
			}
			setcolor(BLACK);
			drawpoly(8, poly);
			drawpoly(3, hl1);
			drawpoly(3, hl2);
			drawpoly(3, tl1);
			drawpoly(3, tl2);
			drawpoly(4, rf);
			setfillstyle(SOLID_FILL, BLACK);
			fillpoly(8, poly);
			fillpoly(3, hl1);
			fillpoly(3, hl2);
			fillpoly(3, tl1);
			fillpoly(3, tl2);
			fillpoly(4, rf);
	}
	else{
		int poly[]={485, 220, 520, 185, 525, 185, 545, 190, 545, 195, 510, 230, 505, 230, 485, 225};
		int hl1[]={520, 185, 525, 185, 522, 190};
		int hl2[]={545, 195, 545, 190, 540, 192};
		int tl1[]={485, 220, 490, 222, 485, 225};
		int tl2[]={505, 230, 507, 227, 510, 230};
		int gl[]={515, 195, 535, 200, 515, 220, 495, 215};
		int rf[]={504, 211, 515, 201,526, 204, 515, 214};
		if(clane==4){
				int i;
				for(i=0; i<16; i++){
					if(i%2==0){
						poly[i]+=175;
						if(i<6){
							hl1[i]+=175;
							hl2[i]+=175;
							tl1[i]+=175;
							tl2[i]+=175;
						}
					if(i<8){
						gl[i]+=175;
						rf[i]+=175;
					}
					}	
					else{
						poly[i]+=180;
						if(i<6){
							hl1[i]+=180;
							hl2[i]+=180;
							tl1[i]+=180;
							tl2[i]+=180;
						}
						if(i<8){
							gl[i]+=180;
							rf[i]+=180;
						}
					}

				}
		}
		setcolor(BLACK);
		drawpoly(8, poly);
		drawpoly(3, hl1);
		drawpoly(3, hl2);
		drawpoly(3, tl1);
		drawpoly(3, tl2);
		drawpoly(4, rf);
		setfillstyle(SOLID_FILL, BLACK);
		fillpoly(8, poly);
		fillpoly(3, hl1);
		fillpoly(3, hl2);
		fillpoly(3, tl1);
		fillpoly(3, tl2);
		fillpoly(4, rf);
	}
}


