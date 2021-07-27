#include <stdio.h>
#include <stdlib.h>
int x_st,y_st,x_en,y_en;

//function to find zone
int find_zone(){
	int dx=x_en-x_st;
	int dy=y_en-y_st;
	if(dx>=0 && dy >=0){
		if(abs(dx)>=abs(dy)) return 0;
		return 1;
	}
	if(dx<=0 && dy>=0){
		if(abs(dy)>=abs(dx)) return 2;
		return 3;
	}
	if(dx<=0 && dy <= 0){
		if(abs(dx)>=abs(dy)) return 4;
		return 5; 
	}
	if(dx>=0 && dy<=0){
		if(abs(dy)>=abs(dx)) return 6;
		return 7;
	}
	return 0;
}

//function : implementation of mid point line drawing algorithm
void zone_seven(){
	int dx=x_en-x_st;
	int dy=y_en-y_st;
	
	int d=2*dy + dx;
	int d_n=2*dy;
	int d_ne=2*(dy+dx);
	int x=x_st;
	int y=y_st;
	while(x<x_en){
		if(d<0){
			x++;
			d=d-d_n;
		}
		else{
			x++;
			y--;
			d=d-d_ne;
		}
		printf("x = %d y = %d\n",x,y);
	}
	
	printf("found\n");
}

//(2,10)   (5,2)
void zone_six(){
	int dx=x_en-x_st;
	int dy=y_en-y_st;
	
	int d=dy + 2*dx;
	int d_n=2*dx;
	int d_ne=2*(dy+dx);
	int x=x_st;
	int y=y_st;
	while(y>y_en){
		if(d<0){
			y--;
			d=d+d_n;
		}
		else{
			x++;
			y--;
			d=d+d_ne;
		}
		printf("x = %d y = %d\n",x,y);
	}
	
	printf("found\n");
}

//(5,10) (3,2)
void zone_five(){
	int dx=x_en-x_st;
	int dy=y_en-y_st;
	
	int d= -dy + 2*dx;
	int d_n=2*dx;
	int d_ne=2*(-dy+dx);
	int x=x_st;
	int y=y_st;
	while(y>y_en){
		if(d<0){
			y--;
			d=d-d_n; //error bare 
		}
		else{
			x--;
			y--;
			d=d-d_ne; //error kome 
		}
		printf("x = %d y = %d\n",x,y);
	}
	
	printf("found\n");
}
//(10,5) (2,1)
void zone_four(){
	int dx=x_en-x_st;
	int dy=y_en-y_st;
	
	int d= -2*dy + dx;
	int d_n= -2*dy;
	int d_ne=2*(-dy+dx);
	int x=x_st;
	int y=y_st;
	while(x>x_en){
		if(d<0){
			x--;
			d=d+d_n; //error bare 
		}
		else{
			x--;
			y--;
			d=d+d_ne; //error kome 
		}
		printf("x = %d y = %d\n",x,y);
	}
	
	printf("found\n");
}

//(10,5) (2,7)
void zone_three(){
	int dx=x_en-x_st;
	int dy=y_en-y_st;
	
	int d= -2*dy + dx;
	int d_n= -2*dy;
	int d_ne=2*(-dy-dx);
	int x=x_st;
	int y=y_st;
	while(x>x_en){
		if(d<0){
			x--;
			d=d-d_n; //error bare 
		}
		else{
			x--;
			y++;
			d=d-d_ne; //error kome 
		}
		printf("x = %d y = %d\n",x,y);
	}
	
	printf("found\n");
}

//(10,5) (8,10)
void zone_two(){
	int dx=x_en-x_st;
	int dy=y_en-y_st;
	
	int d= -dy - 2 * dx;
	int d_n= -2*dx;
	int d_ne=2*(-dy-dx);
	int x=x_st;
	int y=y_st;
	while(y<y_en){
		if(d<0){
			y++;
			d=d+d_n; //error bare 
		}
		else{
			x--;
			y++;
			d=d+d_ne; //error kome 
		}
		printf("x = %d y = %d\n",x,y);
	}
	
	printf("found\n");
}

//(10,5) (12,10)
void zone_one(){
	int dx=x_en-x_st;
	int dy=y_en-y_st;
	
	int d= dy - 2 * dx;
	int d_n= -2*dx;
	int d_ne=2*(-dy+dx);
	int x=x_st;
	int y=y_st;
	while(y<y_en){
		if(d<0){
			y++;
			d=d-d_n; //error bare 
		}
		else{
			x++;
			y++;
			d=d+d_ne; //error kome 
		}
		printf("x = %d y = %d\n",x,y);
	}
	
	printf("found\n");
}

//(10,5) (20,10)
void zone_zero(){
	int dx=x_en-x_st;
	int dy=y_en-y_st;
	
	int d= 2*dy - dx;
	int d_n= 2*dy;
	int d_ne=2*(dy-dx);
	int x=x_st;
	int y=y_st;
	while(x<x_en){
		if(d<0){
			x++;
			d=d+d_n; //error bare 
		}
		else{
			x++;
			y++;
			d=d+d_ne; //error kome 
		}
		printf("x = %d y = %d\n",x,y);
	}
	
	printf("found\n");
}

int main(void){
	scanf("%d %d %d %d",&x_st,&y_st,&x_en,&y_en);
	int zone = find_zone();
	printf("zone = %d\n",zone);
	if(zone==7){
		zone_seven();
	}
	if(zone==6){
		zone_six();
	}
	if(zone==5){
		zone_five();
	}
	if(zone==4){
		zone_four();
	}
	if(zone==3){
		zone_three();
	}
	if(zone==2){
		zone_two();
	}
	if(zone==1){
		zone_one();
	}
	if(zone == 0){
		zone_zero();
	}
	return 0;
}
