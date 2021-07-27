#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;


double R; // equation for ellipse B*B*x*x + A*A*y*y - A*A*B*B;


void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (-250,250,-250,250);
}


void circle_drawing(){
	double d=1-R;
	double x=0,y=R;
	while(x<y){
		double dE=2.0*x+3.0;
		double dSE=2*x-2*y+5;
		if(d<0){
			d=d+dE;
		}
		else {
			d=d+dSE;
			y--;
		}
		x++;
		glVertex2i(x,y);
		double tx,ty;
		tx=y;
		ty=x;
		glVertex2i(tx,ty);
		tx=y;
		ty=-x;
		glVertex2i(tx,ty);
		tx=x;
		ty=-y;
		glVertex2i(tx,ty);
		tx=-x;
		ty=-y;
		glVertex2i(tx,ty);
		tx=-y;
		ty=-x;
		glVertex2i(tx,ty);
		tx=-y;
		ty=x;
		glVertex2i(tx,ty);
		tx=-x;
		ty=y;
		glVertex2i(tx,ty);
	}
	
}


void circle_drawing_midpoint_algorithm(){
	freopen("in.txt","r",stdin);
	scanf("%lf",&R);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	circle_drawing();
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
	glutDisplayFunc(circle_drawing_midpoint_algorithm);
	glutMainLoop();
	
	return 0;
}

