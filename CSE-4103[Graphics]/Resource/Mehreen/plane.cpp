//gcc midpointalgo.c -o t -lGL -LGLU -lglut
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include<time.h>
#define WINDOW_WIDTH 640*2
#define WINDOW_HEIGHT 480*2

//double degree = (3.1416/180);
double degreex = (3.1416/180), degreey = (3.1416/180), degreez = (3.1416/180), d=2500, m=1500;
int n, n_p, n_i;
double x[1335], y[1335], z[1335], cx[1335], cy[1335];
int in_one[2452], in_two[2452], in_three[2452];

int findZone(double X0, double Y0, double X1, double Y1) 
{
	double dx = X1 - X0;
	double dy = Y1 - Y0;
	if (dx >= 0 && dy >= 0) {
		if (fabs(dx) > fabs(dy)) return 0;
		else return 1;
	}
	else if (dx<=0 && dy>=0) {
		if (fabs(dx) < fabs(dy)) return 2;
		return 3;
	}
	else if (dx <=0 && dy<=0) {
		if (fabs(dx) > fabs(dy)) return 4;
		return 5;
	}
	else if (dx >=0 && dy <= 0) {
		if (fabs(dx) < fabs(dy)) return 6;
		return 7;
	}
}
void drawPixel(double X, double Y, int zone) 
{
	glVertex2d((X*2) / WINDOW_WIDTH, (Y*2)/WINDOW_HEIGHT);
}
void drawLine(double X0, double Y0, double X1, double Y1) 
{
	double dx=(X1-X0);
	double dy=(Y1-Y0);
	double steps;
    	double xD,yD,x=X0,y=Y0;
	if (fabs(dx) > fabs(dy)) steps = abs(dx);
	else steps = abs(dy);
	xD=dx/(float)steps;
	yD=dy/(float)steps;	
	glBegin(GL_POINTS);
	int zone = findZone(X0, Y0, X1, Y1);
    	for(int i=0; i<steps; i++) 
	{
	    	x+=xD;
	    	y+=yD;
		glVertex2d((x*2) / WINDOW_WIDTH, (y*2)/WINDOW_HEIGHT );
    	}
	glEnd();
	glFlush();
}


void draw_axis()
{
	printf("axis in\n");
	glColor3f(0.0,1.0,0.0);
	glPointSize(1);	
	drawLine(-320.0*2, 0.0, 320.0*2, 0.0);
	printf("axis out\n");
	drawLine(0.0, 240.0*2, 0.0, -240.0*2);
}

void proj_3d_2d()
{
	printf("proj in\n");
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);	
	//draw_axis();
	for(int i=0; i<n_p; i++)
	{
		cx[i] = x[i]/(1+((z[i]+m)/d));
		cy[i] = y[i]/(1+((z[i]+m)/d));
		printf("cx[%d] = %lf\ncy[%d] = %lf\n", i, cx[i], i, cy[i]);
		printf("break\n");
		//if(i==1334)break;
		printf("break hoi nai\n");
	}
	draw_axis();
	for(int i=0; i<n_i; i++)
	{
		glColor3f(1.0, 0.0, 1.0);
		drawLine(cx[in_one[i]], cy[in_one[i]], cx[in_two[i]], cy[in_two[i]]);
		printf("cx[in_one[%d]] = %lf\n",i, cx[in_one[i]]);
		printf("Aaksi 1\n");
		glColor3f(0.0,1.0,0.0);
		drawLine(cx[in_two[i]], cy[in_two[i]], cx[in_three[i]], cy[in_three[i]]);
		printf("Aaksi 2\n");		
		glColor3f(0.0,1.0,1.0);
		drawLine(cx[in_three[i]], cy[in_three[i]], cx[in_one[i]], cy[in_one[i]]);
		printf("Aaksi 3\n");
		printf("break 1\n");
		//if(i==2451)break;
		printf("break 1 hoi nai\n");
	}
	printf("hoise break\n");
	printf("proj out\n");
	
}
		

 
void draw(void)
{
	printf("draw in\n");
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glutOrtho2D(.0,50.0,.0,50.0);	
	gluOrtho2D(-1200.0,1200.0,-1200.0,1200.0);
	glPointSize(2);
	proj_3d_2d();
	glFlush();
	glutSwapBuffers();
	glEnd();
	printf("draw out\n");

}

int main(int argc, char **argv)
{
	printf("main in\n");
	int k;
	printf("enter points:\n");
 	for(int i=0; i<1335; i++)
	{
		//printf("Enter Point %d (X%d, Y%d Z%d) :\n", i, i, i, i);
 		scanf("%lf %lf %lf",&x[i],&y[i],&z[i]);
		
	}
	for(int i=0; i<1335; i++)
	printf("X = %lf, Y = %lf, Z = %lf\n", x[i], y[i], z[i]);
	
	printf("enter indexes:\n");
	for(int i=0; i<2452; i++)
	{
		//printf("Enter Point %d (X%d, Y%d Z%d) :\n", i, i, i, i);
 		scanf("%d %d %d %d",&k, &in_one[i],&in_two[i], &in_three[i]);
		//printf("in_one = %d, in_two = %d, in_three = %d\n", in_one[i], in_two[i], in_three[i]);	
	}

	for(int i=0; i<1335; i++)
	printf("%d %d %d %d",&k, &in_one[i],&in_two[i], &in_three[i]);

	
 	glutInit(&argc, argv);
 	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-(640*2))/2, (glutGet(GLUT_SCREEN_HEIGHT)-(480*2))/2);
	glutInitWindowSize(640*2,480*2);
	glutCreateWindow("Rotation Window");
	glutDisplayFunc(draw);
	printf("ashchhi main e\n");
	//glutSpecialFunc(rotate);
	glutMainLoop();
	printf("main out\n");
	return 0;
}
