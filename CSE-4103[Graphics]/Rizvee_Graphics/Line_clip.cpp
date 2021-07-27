#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

using namespace std;
typedef int OutCode;

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

int XMIN,XMAX,YMIN,YMAX;
int x_st,y_st,x_en,y_en;
int in_x[250],in_y[250],out_x[250],out_y[250];
int n;



/*****************************************************
			(-y,x)			   |      (y,x)
							   |
	        (-x,y)             |      (x,y)
	       ----------------------------------------
	        (-x,-y)            |       (x,-y)
							   |
			(-y,-x)			   |       (y,-x)



 */

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

//function to make symmetry
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

//function to draw line
void line_draw(int b){

	if(b==0)glColor3f(1.0, 0.0, 0.0);
	else if(b==2) glColor3f(0.0, 1.0, 0.0);
	else glColor3f(0.0, 0.0, 1.0);


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
		//printf("x = %d y = %d\n",tempx,tempy);
	}
    tempx=x_en;
    tempy=y_en;
	glVertex2i(tempx,tempy);
	glEnd();
    glFlush();
	return;
}




OutCode ComputeOutCode(int x, int y)
{
    int xmin = XMIN;
    int ymin = YMIN;
    int xmax = XMAX;
    int ymax = YMAX;


	OutCode code;

	code = INSIDE;          // initialised as being inside of [[clip window]]

	if (x < xmin)           // to the left of clip window
		code |= LEFT;
	else if (x > xmax)      // to the right of clip window
		code |= RIGHT;
	if (y < ymin)           // below the clip window
		code |= BOTTOM;
	else if (y > ymax)      // above the clip window
		code |= TOP;

	return code;
}

void draw_rectange(int x0,int y0,int x1,int y1,int color){
    x_st=x0;
    y_st=y0;
    x_en=x1;
    y_en=y1;
    line_draw(color);
}

void CohenSutherlandLineClip(int x0, int  y0,int x1, int y1)
{

	int xmin = XMIN;
    int ymin = YMIN;
    int xmax = XMAX;
    int ymax = YMAX;

    int stx,sty,enx,eny;
    int sec_stx,sec_sty,sec_enx,sec_eny;
    int shurux,shuruy,sheshx,sheshy;
    bool ext1=false;
    bool ext2=false;
    shurux=x0;
    shuruy=y0;
    sheshx=x1;
    sheshy=y1;

	OutCode outcode0 = ComputeOutCode(x0, y0);
	OutCode outcode1 = ComputeOutCode(x1, y1);
	bool accept = false;

	while (true) {
		if (!(outcode0 | outcode1)) {
			accept = true;
			break;
		} else if (outcode0 & outcode1) {
			break;
		} else {

			int x, y;
			OutCode outcodeOut = outcode0 ? outcode0 : outcode1;
			if (outcodeOut & TOP) {
				x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
				y = ymax;
			} else if (outcodeOut & BOTTOM) {
				x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
				y = ymin;
			} else if (outcodeOut & RIGHT) {
				y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
				x = xmax;
			} else if (outcodeOut & LEFT) {
				y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
				x = xmin;
			}

			if (outcodeOut == outcode0) {
				x0 = x;
				y0 = y;
                if(x0 != shurux || y0 != shuruy){
                    stx=x0;
                    sty=y0;
                    enx=shurux;
                    eny=shuruy;
                    ext1=true;
                }

				outcode0 = ComputeOutCode(x0, y0);
			} else {
				x1 = x;
				y1 = y;
				outcode1 = ComputeOutCode(x1, y1);
                if(x1 != sheshx || y1 != sheshy){
					sec_stx=x1;
                    sec_sty=y1;
                    sec_enx=sheshx;
                    sec_eny=sheshy;
                    ext2=true;
                }
			}
		}
	}

	printf("line %d %d %d %d\n",x0,y0,x1,y1);
	if(ext1)printf("line %d %d %d %d\n",stx,sty,enx,eny);
	if(ext2)printf("line %d %d %d %d\n",sec_stx,sec_sty,sec_enx,sec_eny);

    draw_rectange(xmin,ymin,xmax,ymin,2);
	draw_rectange(xmin,ymin,xmin,ymax,2);
	draw_rectange(xmax,ymin,xmax,ymax,2);
	draw_rectange(xmin,ymax,xmax,ymax,2);

	if (accept) {
		x_st=x0;
		y_st=y0;
		x_en=x1;
        y_en=y1;
        printf("line %d %d %d %d\n",x_st,y_st,x_en,y_en);
        line_draw(0);

        if(ext1){
        printf("dhuke\n");
		x_st=stx;
		y_st=sty;
		x_en=enx;
        y_en=eny;
        line_draw(1);

        }
        if(ext2){
        printf("dhuke2\n");
		x_st=sec_stx;
		y_st=sec_sty;
		x_en=sec_enx;
        y_en=sec_eny;
        line_draw(1);
        }
	}
}

void draw_line(){
	glClear(GL_COLOR_BUFFER_BIT);
	for(int i=1;i<=n;i++){
        x_st=in_x[i];
        y_st=in_y[i];
        x_en=out_x[i];
        y_en=out_y[i];
		CohenSutherlandLineClip(x_st,y_st,x_en,y_en);
	}
}



 int main(int argc,char **argv){

	freopen("in3.txt","r",stdin);
    scanf("%d %d %d %d",&XMIN,&YMIN,&XMAX,&YMAX);
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



	return 0;
 }
