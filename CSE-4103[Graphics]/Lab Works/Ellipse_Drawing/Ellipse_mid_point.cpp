#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

double x_ellipse,y_ellipse;
double B,A; // equation for ellipse B*B*x*x + A*A*y*y - A*A*B*B;

void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (-250,250,-250,250);
}


void draw_region_1(double stx,double sty,double d){
	//double d=(B*B) + (A*A)/4.0 -A*A*B*B;
	double x=stx;
	double y=sty;
	int counter=0;
	while(y!=0){
		double dE = A*A*(-2*y+3);
		double dNE = B*B*(2*x+2) + A*A*(3-2*y);
		if(d<0) {
			d=d+dNE;
			x++;	
		}
		else{
			d=d+dE;
		}
		y--;
		glVertex2i(x,y);
		double tx,ty;
		tx=-x;
		ty=y;
		glVertex2i(tx,ty);
		tx=-x;
		ty=-y;
		glVertex2i(tx,ty);
		tx=x;
		ty=-y;
		glVertex2i(tx,ty);
		
	}
	return;
}

void draw_region_2(double stx,double sty){
	double d=(B*B) + A*A/4.0 - A*A*B;
	double dE,dNE;
	double x=stx,y=sty; //stx=0 sty=B
	while(true){
		double value = A*A*(y-0.5) - B*B*(x+1);
		if(value<0) break;
		dE = B*B*(2*x+3);
		dNE = B*B*(2*x+3) + A*A*(2-2*y);
		if(d<0) {
			//move axis direction
			d=d+dE;
		}
		else{
			d=d+dNE;
			y--;
		}
		x++;
		glVertex2i(x,y);
		double tx=-x,ty=y;
		glVertex2i(tx,ty);
		tx=-x;
		ty=-y;
		glVertex2i(tx,ty);
		tx=x;
		ty=-y;
		glVertex2i(tx,ty);
	}
	draw_region_1(x,y,d);
}	


void ellipse_drawing_midpoint_algorithm(){
	freopen("in.txt","r",stdin);
	scanf("%lf %lf",&A,&B);
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	draw_region_2(0,B);
	glEnd();
    glFlush();
   
}



int main(int argc, char **argv){
	
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("points and lines");
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(ellipse_drawing_midpoint_algorithm);
	glutMainLoop();
	
	return 0;
}
