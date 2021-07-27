#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;
#define MAX 25
#define PI acos(-1.0)

int n;
double d;
double x_st,y_st,x_en,y_en;
double off_x,off_y,off_z;
double angle;


struct Line{
	double x1,y1,z1;
	double x2,y2,z2;
};

Line arr[MAX+1];

void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (-250,250,-250,250);
}

//line drawing part 
//function to find zone
int find_zone(){
	double dx=x_en-x_st;
	double dy=y_en-y_st;
	cout<<"dx = " <<dx<<" "<<dy<<endl;
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


double return_x(double x,double y,int pr_zone,int tr_zone,int choice){
		//converting into 0 ghor
		double tx,ty;
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
	/*if(zone==0) glColor3f(1.0, 0.0, 0.0);
	if(zone==1) glColor3f(0.0, 0.5, 0.7);
	if(zone==2) glColor3f(0.2, 0.6, 0.0);
	if(zone==3) glColor3f(0.3, 0.4, 0.5);
	if(zone==4) glColor3f(0.5, 0.0, 0.0);
	if(zone==5) glColor3f(1.0, 1.0, 0.0);
	if(zone==6) glColor3f(0.4, 0.5, 0.0);
	if(zone==7) glColor3f(0.9, 0.0, 0.4);*/

	double x1=return_x(x_st,y_st,zone,0,0);
	double y1=return_x(x_st,y_st,zone,0,1);
	double x2=return_x(x_en,y_en,zone,0,0);
	double y2=return_x(x_en,y_en,zone,0,1);
	
	cout<<"x1 = " <<x1<<" "<<y1<<endl;
	
	if(x1>x2){
		double temp=x1;
		x1=x2;
		x2=temp;

		temp=y1;
		y1=y2;
		y2=temp;
	}
	cout<<"x1 = " <<x1<<" "<<y1<<endl;
	cout<<"x2 = " <<x2<<" "<<y2<<endl;
	double x = x1;
	double y = y1;

	double dx=x2-x1;
	double dy=y2-y1;
	double d = 2*dy - dx;
	double d_n= 2*dy;
	double d_ne=2*(dy-dx);

	//printf("zone %d\n",zone);
	double tempx=return_x(x,y,0,zone,0);
	double tempy=return_x(x,y,0,zone,1);

	glVertex2i(round(tempx),round(tempy));
	//cout<<"main x " << x<<" "<<y<<endl;
	//cout<<tempx<<" "<<tempy<<endl;
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
		glVertex2i(round(tempx),round(tempy));
		//cout<<"aki " << endl;
		//cout<<tempx<<" "<<tempy<<endl;
		//printf("x = %d y = %d\n",tempx,tempy);
	}
	printf("ber hoi\n");
    tempx=x_en;
    tempy=y_en;
	glVertex2i(round(tempx),round(tempy));
	glEnd();
    glFlush();
	return;
}

void general_rotation(double x,double y, double z, double &x1, double &y1, double &z1){
	
}

void general_perspective_projection(){
	glClear(GL_COLOR_BUFFER_BIT);
	d=-500;
}

void perspective_projection(){
	glClear(GL_COLOR_BUFFER_BIT);
	d=-500;
	double value=(angle*PI)/180.0;
	for(int i=0;i<n;i++){
		double tx1=(arr[i].x1+off_x)/(1+(arr[i].z1/d));
		double ty1=(arr[i].y1+off_y)/((1+arr[i].z1/d));
		double tz1=(arr[i].z1+off_z)/((1+arr[i].z1/d));
		
		double tx2=(arr[i].x2+off_x)/((1+arr[i].z2/d));
		double ty2=(arr[i].y2+off_y)/((1+arr[i].z2/d));
		double tz2=(arr[i].z2+off_z)/((1+arr[i].z2/d));
		cout<<"main = " << arr[i].x1<<" "<<" "<<arr[i].z1<<" "<<arr[i].y1<<" "<<arr[i].x2<<" "<<arr[i].y2<<endl;
		cout<<tx1<<" tx1 "<<ty1<<" ty1 "<<tx2<<" tx2 "<<ty2<<" ty2 " << endl;
		cout<<"angle = " << angle<<endl;
		double ttx1 = tx1*cos(value) - ty1*sin(value);
		double tty1 = tx1*sin(value) - ty1*cos(value);
		
		double ttx2 = tx2*cos(value) - ty2*sin(value);
		double tty2 = tx2*sin(value) - ty2*cos(value);
		
		x_st=ttx1;
		y_st=tty1;
		x_en=ttx2;
		y_en=tty2;
		line_draw();
	}
}

void perspective_projection_around_y(){
	glClear(GL_COLOR_BUFFER_BIT);
	d=-500;
	double value=(angle*PI)/180.0;
	for(int i=0;i<n;i++){
		double tx1=(arr[i].x1+off_x)/(1+(arr[i].z1/d));
		double ty1=(arr[i].y1+off_y)/((1+arr[i].z1/d));
		double tz1=(arr[i].z1+off_z)/((1+arr[i].z1/d));
		
		double tx2=(arr[i].x2+off_x)/((1+arr[i].z2/d));
		double ty2=(arr[i].y2+off_y)/((1+arr[i].z2/d));
		double tz2=(arr[i].z2+off_z)/((1+arr[i].z2/d));
		cout<<"main = " << arr[i].x1<<" "<<" "<<arr[i].z1<<" "<<arr[i].y1<<" "<<arr[i].x2<<" "<<arr[i].y2<<endl;
		cout<<tx1<<" tx1 "<<ty1<<" ty1 "<<tx2<<" tx2 "<<ty2<<" ty2 " << endl;
		cout<<"angle = " << angle<<endl;
		double ttx1 = tx1*cos(value);
		double tty1 = ty1;
		
		double ttx2 = tx2*cos(value);
		double tty2 = ty2;
		
		x_st=ttx1;
		y_st=tty1;
		x_en=ttx2;
		y_en=tty2;
		line_draw();
	}
}

void perspective_projection_around_x(){
	glClear(GL_COLOR_BUFFER_BIT);
	d=-500;
	double value=(angle*PI)/180.0;
	for(int i=0;i<n;i++){
		double tx1=(arr[i].x1+off_x)/(1+(arr[i].z1/d));
		double ty1=(arr[i].y1+off_y)/((1+arr[i].z1/d));
		double tz1=(arr[i].z1+off_z)/((1+arr[i].z1/d));
		
		double tx2=(arr[i].x2+off_x)/((1+arr[i].z2/d));
		double ty2=(arr[i].y2+off_y)/((1+arr[i].z2/d));
		double tz2=(arr[i].z2+off_z)/((1+arr[i].z2/d));
		cout<<"main = " << arr[i].x1<<" "<<" "<<arr[i].z1<<" "<<arr[i].y1<<" "<<arr[i].x2<<" "<<arr[i].y2<<endl;
		cout<<tx1<<" tx1 "<<ty1<<" ty1 "<<tx2<<" tx2 "<<ty2<<" ty2 " << endl;
		cout<<"angle = " << angle<<endl;
		double ttx1 = tx1;
		double tty1 = ty1*cos(value);
		
		double ttx2 = tx2;
		double tty2 = ty2*cos(value);
		
		x_st=ttx1;
		y_st=tty1;
		x_en=ttx2;
		y_en=tty2;
		line_draw();
	}
}




void input_line(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	for(int i=0;i<n;i++){
		x_st=arr[i].x1;
		y_st=arr[i].y1;
		
		x_en=arr[i].x2;
		y_en=arr[i].y2;
		//line_draw();
	}
	perspective_projection();
}

void catchKey(int key, int x, int y){
	if(key == GLUT_KEY_LEFT) {
		printf("Left key is pressed\n");
		angle--;
		perspective_projection();
	}        
    else if(key == GLUT_KEY_RIGHT) {
		 printf("Right key is pressed\n");
		 angle++;
		 perspective_projection();
	}  
    else if(key == GLUT_KEY_DOWN) {
		 printf("Down key is pressed\n");
		 angle--;
		 perspective_projection_around_x();
		 
	}  
    else if(key == GLUT_KEY_UP) {
        printf("Up key is pressed\n");
        angle++;
		perspective_projection_around_y();
     }
}



int main(int argc, char **argv){
	freopen("cube.txt","r",stdin);
	angle=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf %lf %lf %lf %lf %lf",&arr[i].x1,&arr[i].y1,&arr[i].z1,&arr[i].x2,&arr[i].y2,&arr[i].z2);
	}
	off_x=0;
	off_y=0;
	off_z=0;
	scanf("%lf %lf %lf",&off_x,&off_y,&off_z);
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("points and lines");
	init2D(0.0,0.0,0.0);
	glutSpecialFunc(catchKey);
	glutDisplayFunc(input_line);
	glutMainLoop();
	return 0;
}
