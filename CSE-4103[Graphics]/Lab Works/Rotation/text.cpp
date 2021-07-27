#include <bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace std;
#define MAX 150
#define MAX_ROW 10
#define MAX_COL 10
#define PI acos(-1.0)



int n;
double in_x[MAX+1],in_y[MAX+1],in_z[MAX+1],ou_x[MAX+1],ou_y[MAX+1],ou_z[MAX+1];
double matrix_multi_result[MAX_ROW+1][MAX_COL+1];
double x_st,y_st,x_en,y_en;
double global_angle_fixed_z,global_angle_fixed_x,global_angle_fixed_y;

void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (-250,250,-250,250);
	//glClear (GL_COLOR_BUFFER_BIT);
   // glFlush();
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
			tx=y;
			ty=-x;
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
			tx=-y;
			ty=x;
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
	if(x1>x2){
		double temp=x1;
		x1=x2;
		x2=temp;

		temp=y1;
		y1=y2;
		y2=temp;
	}
	//cout<<"x1 = " <<x1<<" "<<y1<<endl;
	//cout<<"x2 = " <<x2<<" "<<y2<<endl;
	double x = x1;
	double y = y1;

	double dx=x2-x1;
	double dy=y2-y1;
	double d = 2*dy - dx;
	double d_n= 2*dy;
	double d_ne=2*(dy-dx);

	printf("zone %d\n",zone);
	double tempx=return_x(x,y,0,zone,0);
	double tempy=return_x(x,y,0,zone,1);

	glVertex2i(round(tempx),round(tempy));
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
		//printf("x = %d y = %d\n",tempx,tempy);
	}
	//printf("ber hoi\n");
    tempx=x_en;
    tempy=y_en;
	glVertex2i(round(tempx),round(tempy));
	glEnd();
    glFlush();
	return;
}





void matrix_multiplication(int row_num,double rotation_matrix[MAX_ROW+1][MAX_COL+1],double basic[MAX_ROW+1][MAX_COL+1]){
	for(int i=0;i<=row_num;i++){
		double value = 0.0;
		for(int j=0;j<=row_num;j++){
			value = value + rotation_matrix[i][j]*basic[j][0];
		}
		matrix_multi_result[i][0]=value;
	}
	return;
}

void point_rotation_2D(double x0,double y0,double z0,double angle, double &tx, double &ty, double &tz){
	int dim=3;
	double rotation_matrix[MAX_ROW+1][MAX_COL+1];
	angle = (angle * PI)/180.0;
	rotation_matrix[0][0] = cos(angle);
	rotation_matrix[0][1] = -sin(angle);
	rotation_matrix[0][2] = 0;
	rotation_matrix[0][3] = 0;
	
	rotation_matrix[1][0] = sin(angle);
	rotation_matrix[1][1] = cos(angle);
	rotation_matrix[1][2] = 0;
	rotation_matrix[1][3] = 0;
	
	rotation_matrix[2][0] = 0;
	rotation_matrix[2][1] = 0;
	rotation_matrix[2][2] = 1;
	rotation_matrix[2][3] = 0;
	
	rotation_matrix[3][0] = 0;
	rotation_matrix[3][1] = 0;
	rotation_matrix[3][2] = 0;
	rotation_matrix[3][3] = 1;
	
	
	
	int row=3;
	int col=1;
	double basic[MAX_ROW+1][MAX_COL+1];
	basic[0][0]=x0;
	basic[1][0]=y0;
	basic[2][0]=z0;
	basic[3][0]=1;
	
	memset(matrix_multi_result,0,sizeof(matrix_multi_result));
	matrix_multiplication(3,rotation_matrix,basic);
	tx=matrix_multi_result[0][0];
	ty=matrix_multi_result[1][0];
	tz=matrix_multi_result[2][0];
	return;
}

void draw_object(double angle,int choice){
	
	glClear(GL_COLOR_BUFFER_BIT);
	//printf("global angle %d\n",angle);
	
	int cnt=0;
	for(int j=0;j<n;j++){
		cout<<"main " << in_x[j]<<" "<<in_y[j]<<" "<<" "<< ou_x[j]<<" "<<ou_y[j]<<" "<<endl;
		double tx,ty,tz;
		double tx1,ty1,tz1;
		if(choice==1) {
			//move around x 
			cnt++;
			if(cnt==1){
				cout<<"angle " << angle<<endl;
				angle = (angle * PI)/180.0;
			}
			/*
			tx=in_x[j];
			ty=in_y[j]*cos(angle);
			
			tx1=ou_x[j];
			ty1=ou_y[j]*cos(angle);*/
			point_rotation_2D(in_y[j],in_z[j],in_x[j],angle,tx,ty,tz);
			point_rotation_2D(ou_y[j],ou_z[j],ou_x[j],angle,tx1,ty1,tz1);
		}
		else if(choice==2){
			cnt++;
			if(cnt==1){
				cout<<"angle " << angle<<endl;
				angle = (angle * PI)/180.0;
			}
			
			
			
			//move around y axis
			tx=in_x[j]*cos(angle);
			ty=in_y[j];
			
			tx1=ou_x[j]*cos(angle);
			ty1=ou_y[j];
			//cout<<"angle " << angle<<endl;
			//continue;
			
			point_rotation_2D(in_z[j],in_x[j],in_y[j],angle,tx,ty,tz);
			point_rotation_2D(ou_z[j],ou_x[j],ou_x[j],angle,tx1,ty1,tz1);
			
		}
		else if(choice==3){
			//move around z axis
			point_rotation_2D(in_x[j],in_y[j],in_z[j],angle,tx,ty,tz);
			point_rotation_2D(ou_x[j],ou_y[j],ou_z[j],angle,tx1,ty1,tz1);
		}
		x_st=tx;
		y_st=ty;
		x_en=tx1;
		y_en=ty1;
		line_draw();
		//cout<<"rotation " <<tx<<" "<<ty<<" "<<tx1<<" "<<ty1<<endl;
		
	}
}

void input_polygon(){
	
	global_angle_fixed_z=0;
	global_angle_fixed_x=0;
	global_angle_fixed_y=0;
	draw_object(global_angle_fixed_z,3);
}

void catchKey(int key, int x, int y){
	if(key == GLUT_KEY_LEFT) {
		printf("Left key is pressed\n");
		global_angle_fixed_x--;
		//global_angle = (global_angle-1+360)%360;
		draw_object(global_angle_fixed_x,1);
	}        
    else if(key == GLUT_KEY_RIGHT) {
		 printf("Right key is pressed\n");
		 //global_angle = (global_angle+1+360)%360;
		 global_angle_fixed_x++;
		 draw_object(global_angle_fixed_x,1);
	}  
    else if(key == GLUT_KEY_DOWN) {
		 printf("Down key is pressed\n");
		 //global_angle = (global_angle-1+360)%360;
		global_angle_fixed_z++;
		draw_object(global_angle_fixed_z,3);
	}  
    else if(key == GLUT_KEY_UP) {
        printf("Up key is pressed\n");
        //global_angle = (global_angle+1+360)%360;
        global_angle_fixed_y++;
		draw_object(global_angle_fixed_y,2);
     }
}

int main(int argc,char **argv){
	
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf %lf %lf %lf",&in_x[i],&in_y[i],&ou_x[i],&ou_y[i]);
	}
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("points and lines");
	init2D(0.0,0.0,0.0);
	glutSpecialFunc(catchKey);
	//glLoadIdentity();
	glutDisplayFunc(input_polygon);
	glutMainLoop();
	
	
	return 0;
}
