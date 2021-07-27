#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

int x_st,y_st,x_en,y_en;
int in_x[250],in_y[250],ou_x[250],ou_y[250];
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

int symmetry(int x0,int y0,int x1, int y1){

}

//function : implementation of mid point line drawing algorithm
void zone_seven(){
	glColor3f(0.0, 0.2, 0.4);
	glBegin(GL_POINTS);

	int dx=x_en-x_st;
	int dy=y_en-y_st;

	int d=2*dy + dx;
	int d_n=2*dy;
	int d_ne=2*(dy+dx);
	int x=x_st;
	int y=y_st;
	glVertex2i(x,y);
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
		glVertex2i(x,y);
	}
	glVertex2i(x,y);
	glEnd();
	glFlush();
	printf("found\n");
}

//(2,10)   (5,2)
void zone_six(){

	glColor3f(0.0, 0.5, 0.3);
	glBegin(GL_POINTS);

	int dx=x_en-x_st;
	int dy=y_en-y_st;

	int d=dy + 2*dx;
	int d_n=2*dx;
	int d_ne=2*(dy+dx);
	int x=x_st;
	int y=y_st;
	glVertex2i(x,y);
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
		glVertex2i(x,y);
	}
	glVertex2i(x,y);
	glEnd();
	glFlush();
	printf("found\n");
}

//(5,10) (3,2)
void zone_five(){

	glColor3f(0.5, 0.0, 0.7);
	glBegin(GL_POINTS);

	int dx=x_en-x_st;
	int dy=y_en-y_st;

	int d= -dy + 2*dx;
	int d_n=2*dx;
	int d_ne=2*(-dy+dx);
	int x=x_st;
	int y=y_st;
	glVertex2i(x,y);
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
		glVertex2i(x,y);
	}
	glVertex2i(x,y);
	glEnd();
	glFlush();
	printf("found\n");
}
//(10,5) (2,1)
void zone_four(){

	glColor3f(0.0, 0.7, 0.5);
	glBegin(GL_POINTS);

	int dx=x_en-x_st;
	int dy=y_en-y_st;

	int d= -2*dy + dx;
	int d_n= -2*dy;
	int d_ne=2*(-dy+dx);
	int x=x_st;
	int y=y_st;
	glVertex2i(x,y);
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
		glVertex2i(x,y);
	}
	glVertex2i(x,y);
	glEnd();
	glFlush();
	printf("found\n");
}

//(10,5) (2,7)
void zone_three(){


	glColor3f(0.5, 0.7, 0.0);
	glBegin(GL_POINTS);

	int dx=x_en-x_st;
	int dy=y_en-y_st;

	int d= -2*dy + dx;
	int d_n= -2*dy;
	int d_ne=2*(-dy-dx);
	int x=x_st;
	int y=y_st;
	glVertex2i(x,y);
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
		glVertex2i(x,y);
	}
	glVertex2i(x,y);
	glEnd();
	glFlush();
	printf("found\n");
}

//(10,5) (8,10)
void zone_two(){


	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POINTS);
	int dx=x_en-x_st;
	int dy=y_en-y_st;

	int d= -dy - 2 * dx;
	int d_n= -2*dx;
	int d_ne=2*(-dy-dx);
	int x=x_st;
	int y=y_st;
	glVertex2i(x,y);
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
		glVertex2i(x,y);
	}
	glVertex2i(x,y);
	glEnd();
	glFlush();
	printf("found\n");
}

//(10,5) (12,10)
void zone_one(){

	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POINTS);

	int dx=x_en-x_st;
	int dy=y_en-y_st;

	int d= dy - 2 * dx;
	int d_n= -2*dx;
	int d_ne=2*(-dy+dx);
	int x=x_st;
	int y=y_st;
	glVertex2i(x,y);
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
		glVertex2i(x,y);
	}
	glVertex2i(x_en,y_en);
	glEnd();
	glFlush();
	printf("found\n");
}

//(10,5) (20,10)
void zone_zero(){

	//
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);

	int dx=x_en-x_st;
	int dy=y_en-y_st;

	int d= 2*dy - dx;
	int d_n= 2*dy;
	int d_ne=2*(dy-dx);
	int x=x_st;
	int y=y_st;
	glVertex2i(x,y);
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
		glVertex2i(x,y);
	}
	glVertex2i(x_en,y_en);
    glEnd();
    glFlush();
	printf("found\n");
}

void draw_line(){

	glClear(GL_COLOR_BUFFER_BIT);


	for(int i=1;i<=n;i++){
		x_st=in_x[i];
		y_st=in_y[i];
		x_en=ou_x[i];
		y_en=ou_y[i];
        int zone=find_zone();
        printf("zone = %d %d\n",zone,i);

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

		}
		return;
}

int main(int argc,char **argv){

	freopen("in.txt","r",stdin);
	scanf("%d",&n);
    for(int i=1;i<=n;i++){
		scanf("%d %d %d %d",&x_st,&y_st,&x_en,&y_en);
        in_x[i] = x_st;
        in_y[i] = y_st;
        ou_x[i] = x_en;
        ou_y[i] = y_en;
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
