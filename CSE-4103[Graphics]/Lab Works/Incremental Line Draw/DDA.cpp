#include <bits/stdc++.h>
#include <GL/glut.h>
#define MAX 250

using namespace std;

int n;
double x_st,y_st,x_en,y_en;
double in_x[MAX+1],in_y[MAX+1],ou_x[MAX+1],ou_y[MAX+1];

//initialization
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

//functions to draw line where x will increment
void x_incr(int zone){
	//zone : 0,7
	double dx=x_en-x_st;
	double dy=y_en-y_st;
	double m;
	if(dy==0) m=0;
	else {
		m=dy/dx; // m
	}
	double tx=x_st;
	double ty=y_st;
	glVertex2i(round(tx),round(ty));
	cout<<round(tx)<<" "<<round(ty)<<endl;
	for(double i=x_st+1;i<=x_en;i++){
		if(zone==0) ty=ty+fabs(m);
		else if(zone==7) ty=ty-fabs(m);
		tx=i;
		glVertex2i(round(tx),round(ty));
		cout<<round(tx)<<" "<<round(ty)<<endl;
	}
	return;
}

//functions to draw line where y will increment
void y_incr(){
	//zone : 1,2
	double dx=x_en-x_st;
	double dy=y_en-y_st;
	double m;
	if(dx==0) m=0;
	else {
		m=dx/dy; // 1/m
	}
	double tx=x_st;
	double ty=y_st;
	glVertex2i(round(tx),round(ty));
	cout<<round(tx)<<" "<<round(ty)<<endl;
	for(double i=y_st+1;i<=y_en;i++){
		if(zone==1) tx=tx+fabs(m);
		else if(zone==2) tx=tx-fabs(m);
		ty=i;
		glVertex2i(round(tx),round(ty));
		cout<<round(tx)<<" "<<round(ty)<<endl;
	}
	return;
}

//functions to draw line where x will decrement
void x_decr(){
	//zone : 3,4
	double dx=x_en-x_st;
	double dy=y_en-y_st;
	double m;
	if(dy==0) m=0;
	else {
		m=dy/dx; // m
	}
	double tx=x_st;
	double ty=y_st;
	glVertex2i(round(tx),round(ty));
	cout<<round(tx)<<" "<<round(ty)<<endl;
	for(double i=x_st-1;i>=x_en;i--){
		if(zone==3) ty=ty+fabs(m);
		else if(zone==4) ty=ty-fabs(m);
		tx=i;
		glVertex2i(round(tx),round(ty));
		cout<<round(tx)<<" "<<round(ty)<<endl;
	}
	return;
}

//functions to draw line where y will increment
void y_decr(){
	//zone : 5,6
	double dx=x_en-x_st;
	double dy=y_en-y_st;
	double m;
	if(dx==0) m=0;
	else {
		m=dx/dy; // 1/m
	}
	double tx=x_st;
	double ty=y_st;
	glVertex2i(round(tx),round(ty));
	cout<<round(tx)<<" "<<round(ty)<<endl;
	for(double i=y_st-1;i>=y_en;i--){
		if(zone==5) tx=tx-fabs(m);
		else if(zone==6) tx=tx+fabs(m);
		ty=i;
		glVertex2i(round(tx),round(ty));
		cout<<round(tx)<<" "<<round(ty)<<endl;
	}
	return;
}


void draw_line(){
	int zone=find_zone();
	if(zone==0 || zone == 7) {
		x_incr();
	}
	if(zone==1 || zone == 2) {
		y_incr();
	}
	if(zone==3 || zone == 4) {
		x_decr();
	}
	if(zone==5 || zone == 6) {
		y_decr();
	}
}

void dda(){
	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for(int i=0;i<n;i++){
		x_st=in_x[i];
		y_st=in_y[i];
		x_en=ou_x[i];
		y_en=ou_y[i];
		draw_line();
	}
	glEnd();
    glFlush();
}

int main(int argc, char **argv){
	
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf %lf %lf %lf",&in_x[i],&in_y[i],&ou_x[i],&ou_y[i]);
	}
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("DDA");
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(dda);
	glutMainLoop();
}
