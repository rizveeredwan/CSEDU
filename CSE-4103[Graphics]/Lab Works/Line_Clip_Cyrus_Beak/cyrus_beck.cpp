#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std; 
#define MAX 150
#define INF 1000000000

using namespace std;


#define X_MIN -50
#define Y_MIN -50
#define X_MAX  50
#define Y_MAX  50

int in_x[250],in_y[250],ou_x[250],ou_y[250];
int n;
int x_st,y_st,x_en,y_en;


void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (-250,250,-250,250);
}


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

int return_x(int x,int y,int pr_zone,int tr_zone,int choice){
		//converting into 0 ghor
		int tx,ty;
		if(pr_zone==0) {
			tx=x;
			ty=y;
		}
		if(pr_zone==1) {
			tx=y;
			ty=x;
		}
		if(pr_zone==2){
			tx=-y;
			ty=x;
		}
		if(pr_zone==3){
			tx=-x;
			ty=y;
		}
		if(pr_zone==4) {
			tx=-x;
			ty=-y;
		}
		if(pr_zone==5) {
			tx=-y;
			ty=-x;
		}
		if(pr_zone==6) {
			tx=y;
			ty=-x;
		}
		if(pr_zone==7) {
			tx=x;
			ty=-y;
		}
			x=tx;
			y=ty;
			if(tr_zone==0) {
				 if(choice==0) return x;
				 else return y;
			}
			if(tr_zone==1) {
				 if(choice==0) return y;
				 else return x;
			}
			if(tr_zone==2) {
				 if(choice==0) return -y;
				 else return x;
			}
			if(tr_zone==3) {
				 if(choice==0) return -x;
				 else return y;
			}
			if(tr_zone==4) {
				 if(choice==0) return -x;
				 else return -y;
			}
			if(tr_zone==5) {
				 if(choice==0) return -y;
				 else return -x;
			}
			if(tr_zone==6) {
				 if(choice==0) return y;
				 else return -x;
			}
			if(tr_zone==7) {
				 if(choice==0) return x;
				 else return -y;
			}
			return -1;
}


void line_draw(double r,double g,double b){

	glColor3f(r, g, b);
	glBegin(GL_POINTS);

	int zone = find_zone();
	/*if(zone==0) glColor3f(1.0, 0.0, 0.0);
	if(zone==1) glColor3f(0.0, 0.5, 0.7);
	if(zone==2) glColor3f(0.2, 0.6, 0.0);
	if(zone==3) glColor3f(0.3, 0.4, 0.5);
	if(zone==4) glColor3f(0.5, 0.0, 0.0);
	if(zone==5) glColor3f(1.0, 1.0, 0.0);
	if(zone==6) glColor3f(0.4, 0.5, 0.0);
	if(zone==7) glColor3f(0.9, 0.0, 0.4);*/

	int x1=return_x(x_st,y_st,zone,0,0);
	int y1=return_x(x_st,y_st,zone,0,1);
	int x2=return_x(x_en,y_en,zone,0,0);
	int y2=return_x(x_en,y_en,zone,0,1);
	if(x1>x2){
		int temp=x1;
		x1=x2;
		x2=temp;

		temp=y1;
		y1=y2;
		y2=temp;
	}
	//cout<<"x1 = " <<x1<<" "<<y1<<endl;
	//cout<<"x2 = " <<x2<<" "<<y2<<endl;
	int x = x1;
	int y = y1;

	int dx=x2-x1;
	int dy=y2-y1;
	int d = 2*dy - dx;
	int d_n= 2*dy;
	int d_ne=2*(dy-dx);

	//printf("zone %d\n",zone);
	int tempx=return_x(x,y,0,zone,0);
	int tempy=return_x(x,y,0,zone,1);

	glVertex2i(tempx,tempy);
	//printf("x = %d y = %d\n",tempx,tempy);
	while(x<x2){
		if(d<0){
			x++;
			d=d+d_n; //error bare
		}
		else{
			x++;
			y++;
			d=d+d_ne; //error kome
		}
		//cout<<"x = " <<x<<" "<<y<<endl;
		tempx=return_x(x,y,0,zone,0);
		tempy=return_x(x,y,0,zone,1);
		glVertex2i(tempx,tempy);
		//printf("x = %d y = %d\n",tempx,tempy);
	}
	//printf("ber hoi\n");
    tempx=x_en;
    tempy=y_en;
	glVertex2i(tempx,tempy);
	glEnd();
    glFlush();
	return;
}




int vector_multi(int a1,int a2,int b1,int b2){
	return (a1*b1+a2*b2);
}

void cyrus_beck_line_clip(int x0,int y0,int x1,int y1){
	
	cout<<"main ly " << x0<<" "<<y0<<" "<<x1<<" "<<y1<<endl;
	int sx,sy,ex,ey;
	//void outside window cases
	if(x0>X_MAX && x1>X_MAX) {
		x_st=x0;
		y_st=y0;
		x_en=x1;
		y_en=y1;
		//line_draw(1.0,0.0,0.0);
		//return;
	}
	if(x0<X_MIN && x1<X_MIN) {
		x_st=x0;
		y_st=y0;
		x_en=x1;
		y_en=y1;
		//line_draw(1.0,0.0,0.0);
		//return;
		 
	}
	if(y0>Y_MAX && y1>Y_MAX) {
		
		x_st=x0;
		y_st=y0;
		x_en=x1;
		y_en=y1;
		//line_draw(1.0,0.0,0.0);
		//return;
		 
	}
	if(y0<Y_MIN && y1<Y_MIN) {
		
		x_st=x0;
		y_st=y0;
		x_en=x1;
		y_en=y1;
		//line_draw(1.0,0.0,0.0);
		//return;
	}
	
	//trivial accept case
	if(x0>=X_MIN && x0<=X_MAX && y0>=Y_MIN && y0<=Y_MAX && x1>=X_MIN && x1<=X_MAX && y1>=Y_MIN && y1<=Y_MAX){
		x_st=x0;
		y_st=y0;
		x_en=x1;
		y_en=y1;
		//line_draw(1.0,0.0,0.0);
		//return;
	} 
	sx=x0;
	sy=y0;
	ex=x1;
	ey=y1;
	double teT = (double)y0 - (double)Y_MAX;
	teT = -teT / ((y1-y0)*1.0);
	//cout<<"teT "<<teT<<endl;
	//if(teT>1) teT = 1;
	//if(teT<0) teT = 0;
	double teR = (double)x0 - (double)X_MAX;
	teR = -teR / ((x1-x0)*1.0);
	//cout<<"teR "<<teR<<endl;
	//if(teR>1) teR = 1;
	//if(teR<0) teR = 0;
	double teB = (double)y0 - (double)Y_MIN;
	teB = -teB / ((y1-y0)*1.0);
	//cout<<"teB "<<teB<<endl;
	//if(teB>1) teB = 1;
	//if(teB<0) teB = 0;
	double teL = (double)x0 - (double)X_MIN;
	teL = -teL / ((x1-x0)*1.0);
	//cout<<"teL "<<teL<<endl;
	//if(teL>1) teL = 1;
	//if(teL<0) teL = 0;
	
	double tE = 0,tL = 1;
	int dir1 = vector_multi(x1-x0,y1-y0,-1,0); //Left
	if(dir1<0) {
		//entering
		tE=max(tE,teL);
	}
	else{
		tL=min(tL,teL);
	}
	dir1 = vector_multi(x1-x0,y1-y0,0,-1); //Bottom
	if(dir1<0) {
		//entering
		tE=max(tE,teB);
	}
	else{
		tL=min(tL,teB);
	}
	dir1 = vector_multi(x1-x0,y1-y0,1,0); //Right
	if(dir1<0) {
		//entering
		tE=max(tE,teR);
	}
	else{
		tL=min(tL,teR);
	}
	dir1 = vector_multi(x1-x0,y1-y0,0,1);
	if(dir1<0) {
		//entering
		tE=max(tE,teT);
	}
	else{
		tL=min(tL,teT);
	}
	cout<<"sx = " <<sx<<" "<<sy<<" "<<ex<<" "<<ey<<endl;
	cout<<"top = " <<teT<<" "<<"bottom " <<teB<<" "<<"right " <<teR <<" " <<"left " <<teL << endl;
	cout<<"tE " << tE<<" "<<"tL " << tL << endl;
	int xt0 = round(x0 + tE * (x1 - x0) *1.0);
	int yt0 = round(y0 + tE * (y1 - y0) *1.0);
	int xt1 = round(x0 + tL * (x1 - x0) * 1.0);
	int yt1 = round(y0 + tL * (y1 - y0) * 1.0);
	//cout<<"changed " << endl;
	cout<<xt0<<" "<<yt0<<" "<<xt1<<" "<<yt1<<endl;
	/*x_st=xt0;
	y_st=yt0;
	x_en=xt1;
	y_en=yt1;
	line_draw(1.0,0.0,0.0); */
	
	x_st=sx;
	y_st=sy;
	x_en=ex;
	y_en=ey;
	line_draw(1.0,0.0,0.0);
	x_st=xt0;
	y_st=yt0;
	x_en=xt0;
	y_en=yt0;
	line_draw(0.5,1,0.5);
	x_st=xt1;
	y_st=yt1;
	x_en=xt1;
	y_en=yt1;
	line_draw(0.5,1,0.5);
	
}

void draw_reactangle(){
	x_st = X_MIN;
	y_st = Y_MIN;
	x_en = X_MAX;
	y_en = Y_MIN;
	line_draw(1.0,1.0,1.0);
	x_st = X_MIN;
	y_st = Y_MIN;
	x_en = X_MIN;
	y_en = Y_MAX;
	line_draw(1.0,1.0,1.0);
	x_st = X_MIN;
	y_st = Y_MAX;
	x_en = X_MAX;
	y_en = Y_MAX;
	line_draw(1.0,1.0,1.0);
	x_st = X_MAX;
	y_st = Y_MIN;
	x_en = X_MAX;
	y_en = Y_MAX;
	line_draw(1.0,1.0,1.0);
}

void draw_line(){
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	draw_reactangle();
	
	for(int i=0;i<n;i++) {
		cyrus_beck_line_clip(in_x[i],in_y[i],ou_x[i],ou_y[i]);
	}
	return;
}

int main(int argc,char **argv){
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d",&in_x[i],&in_y[i],&ou_x[i],&ou_y[i]);
	}
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("points and lines");
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(draw_line);
	glutMainLoop();
	
}
