#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

using namespace std;


/*****************************************************
			(-y,x)			   |      (y,x)
							   |
	        (-x,y)             |      (x,y)
	       ----------------------------------------
	        (-x,-y)            |       (x,-y)
							   |
			(-y,-x)			   |       (y,-x)



 */

int x_st,y_st,x_en,y_en;
int in_x[250],in_y[250],out_x[250],out_y[250];
int n;


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

void line_draw(){

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);

	int zone = find_zone();
	if(zone==0) glColor3f(1.0, 0.0, 0.0);
	if(zone==1) glColor3f(0.0, 0.5, 0.7);
	if(zone==2) glColor3f(0.2, 0.6, 0.0);
	if(zone==3) glColor3f(0.3, 0.4, 0.5);
	if(zone==4) glColor3f(0.5, 0.0, 0.0);
	if(zone==5) glColor3f(1.0, 1.0, 0.0);
	if(zone==6) glColor3f(0.4, 0.5, 0.0);
	if(zone==7) glColor3f(0.9, 0.0, 0.4);

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
	cout<<"x1 = " <<x1<<" "<<y1<<endl;
	cout<<"x2 = " <<x2<<" "<<y2<<endl;
	int x = x1;
	int y = y1;

	int dx=x2-x1;
	int dy=y2-y1;
	int d = 2*dy - dx;
	int d_n= 2*dy;
	int d_ne=2*(dy-dx);

	printf("zone %d\n",zone);
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
		printf("x = %d y = %d\n",tempx,tempy);
	}
    tempx=x_en;
    tempy=y_en;
	glVertex2i(tempx,tempy);
	glEnd();
    glFlush();
	return;
}

void draw_line(){

	glClear(GL_COLOR_BUFFER_BIT);
	for(int i=1;i<=n;i++){
        x_st=in_x[i];
        y_st=in_y[i];
        x_en=out_x[i];
        y_en=out_y[i];

        line_draw();
	}

}

int main(int argc,char **argv){

    //freopen("in.txt","r",stdin);
    freopen("in2.txt","r",stdin);
	scanf("%d",&n);
    for(int i=1;i<=n;i++){
		scanf("%d %d %d %d",&x_st,&y_st,&x_en,&y_en);
        in_x[i] = x_st;
        in_y[i] = y_st;
        out_x[i] = x_en;
        out_y[i] = y_en;
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

