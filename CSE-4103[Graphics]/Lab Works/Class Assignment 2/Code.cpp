#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;
#define MAX 25
#define PI acos(-1.0)

int n;
double d;
double x_st,y_st,x_en,y_en;

double Y_MIN,Y_MAX; //min Y and max Y 
int pointer_edge_table=0; //koto tuke porjonto nawa hoise
int counter = 0 ; // temp_edge_table e koita element ache
int tot_line;
double angle=0; 
int connection;

//For normal line input 
struct Line{
	double x1,y1,z1;
	double x2,y2,z2;
};
Line arr[MAX+1];

//For normal point input 
struct Point{
	double x1,y1,z1;
};

//For polygon filling 
struct Edge_table{
	double ymin;
	double ymax;
	double x;
	double dx;
	double dy;
	int sign;
	double new_x;
	double new_y;
};
Edge_table edge_table[MAX+1],temp_edge_table[MAX+1]; //Full edge table and koto tuku niye kaj kortesi 

//function to sort edge table 
bool sort_edge_table(const Edge_table &a, const Edge_table &b){
	if(a.ymin<b.ymin) return true;
	else if(a.ymin == b.ymin){
		if(a.x<b.x) return true;
		if(a.x==b.x) return true;
		else return false;
	}
	return false;
} 

void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);
	glMatrixMode (GL_PROJECTION);
	//gluOrtho2D (-250,250,-250,250);
	gluOrtho2D (-700,700,-700,700);
}

//line drawing part 
//function to find zone
int find_zone(){
	double dx=x_en-x_st;
	double dy=y_en-y_st;
	//cout<<"dx = " <<dx<<" "<<dy<<endl;
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

	double x1=return_x(x_st,y_st,zone,0,0);
	double y1=return_x(x_st,y_st,zone,0,1);
	double x2=return_x(x_en,y_en,zone,0,0);
	double y2=return_x(x_en,y_en,zone,0,1);
	
	//cout<<"x1 = " <<x1<<" "<<y1<<endl;
	
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
	//printf("ber hoi\n");
    tempx=x_en;
    tempy=y_en;
	glVertex2i(round(tempx),round(tempy));
	glEnd();
    
	return;
}

void make_edge_table(double x1, double y1, double x2, double y2,int number){
	
	int guni = number;
	if(y1<y2) {
		edge_table[number].ymin = y1;
		edge_table[guni].ymax = y2;
		edge_table[guni].x = x1 ;
		edge_table[guni].dx = abs(x2-x1);
		edge_table[guni].dy = abs(y2 - y1);
		edge_table[guni].new_x = x1;
		edge_table[guni].new_y = y1;
		if(((x2-x1)*(y2-y1))>=0){
				edge_table[guni].sign=1;
		}
		else{
			 edge_table[guni].sign=-1;
		}
	}
	else {
		edge_table[number].ymin = y2;
		edge_table[guni].ymax = y1;
		edge_table[guni].x = x2 ;
		edge_table[guni].dx = abs(x2-x1);
		edge_table[guni].dy = abs(y2 - y1);
		edge_table[guni].new_x = x2;
		edge_table[guni].new_y = y2;
		if(((x2-x1)*(y2-y1))>=0){
				edge_table[guni].sign=1;
		}
		else{
			 edge_table[guni].sign=-1;
		}
	}
}


//return those edeges where ymin == desired ymin
int return_edge(double ymin){
	//start from pointer
	
	cout<<"return edge " << endl;
	for(int i=0;i<n;i++) {
		cout<<edge_table[i].ymin<< " "<<edge_table[i].ymax << " "<<edge_table[i].x<<endl;
	}
	
	for(int i=pointer_edge_table;i<n;i++){
		if(edge_table[i].ymin == ymin){
			counter++;
			temp_edge_table[counter]=edge_table[i];
			pointer_edge_table++;
			cout<<"selected " << edge_table[i].ymin<<" "<<edge_table[i].ymax<<" "<<edge_table[i].x<<endl;
		}
		else {
			break;
		}
	}
	return counter; 
}

void active_list(){
	
	cout<<"YMAX YMIN " <<Y_MAX<<" "<<Y_MIN<<endl;
	cout<<"edge table " <<endl;
	for(int i=0;i<n;i++) {
		cout<<edge_table[i].x<<" "<<edge_table[i].ymin<<" "<<edge_table[i].ymax<<endl;
	}
	double y_min,y_max;
	y_min = Y_MIN;
	y_max = Y_MAX;
	pointer_edge_table=0;
	counter = 0;
	for(double i=y_min;i<y_max;i++){
		//edge niye asi jeigular ymin i er shoman
		counter = return_edge(i); 
		// x er basis e sort kori 
		sort(temp_edge_table+1,temp_edge_table+counter,sort_edge_table); 
		cout<<"active list e kaj and " << counter << endl;
		for(int j=1;j<=counter; j+= 2) {
			cout<<temp_edge_table[j].ymin<<" "<<temp_edge_table[j].ymax<<" "<<temp_edge_table[j].dx<<" "<<temp_edge_table[j].dy<<" "<<temp_edge_table[j].x<<endl;
			cout<<temp_edge_table[j+1].ymin<<" "<<temp_edge_table[j+1].ymax<<" "<<temp_edge_table[j+1].dx<<" "<<temp_edge_table[j+1].dy<<" "<<temp_edge_table[j+1].x<<endl;
		}
		
		//scan line 
		for(int j=1;j<=counter && (j+1)<=counter; j+= 2) {
			//draw line between j and j+1
			//make set of lines 
			x_st = temp_edge_table[j].x;
			y_st = temp_edge_table[j].ymin;
			x_en = temp_edge_table[j+1].x;
			y_en = temp_edge_table[j+1].ymin;
			tot_line++;
			printf("x_st = %lf y_st = %lf x_en = %lf y_en = %lf\n",x_st,y_st,x_en,y_en);
			line_draw(); 
		}
		//update 
		//now change the edges 
		int second_counter = 0;
		for(int j=1;j<=counter;j++){
			temp_edge_table[j].ymin++;
			if(temp_edge_table[j].ymin != temp_edge_table[j].ymax){
				second_counter++;
				temp_edge_table[second_counter].ymin=temp_edge_table[j].ymin;
				temp_edge_table[second_counter].ymax=temp_edge_table[j].ymax;
				temp_edge_table[second_counter].dx=temp_edge_table[j].dx;
				temp_edge_table[second_counter].dy=temp_edge_table[j].dy;
				temp_edge_table[second_counter].sign=temp_edge_table[j].sign;
				temp_edge_table[second_counter].new_x=temp_edge_table[j].new_x;
				temp_edge_table[second_counter].new_y=temp_edge_table[j].new_y;
				if(temp_edge_table[second_counter].dy != 0){ //x will change 
						double lob = (double)temp_edge_table[j].dx*1.0;
						double hor = (double)temp_edge_table[j].dy*1.0;
						double frac = (double)temp_edge_table[j].new_x+1.0*(temp_edge_table[j].sign)*(lob/hor)*(temp_edge_table[j].ymin-temp_edge_table[j].new_y);
						temp_edge_table[second_counter].x = frac;
				}
				else{
					temp_edge_table[second_counter].x=temp_edge_table[j].x;
				}
			}
		}
		counter = second_counter;
		cout<<"second counter " << counter << endl;
	}
	
}


void calculate_n(Point temp[],int n, double &nx, double &ny, double &nz){
	double x1 = temp[1].x1 - temp[0].x1;
	double x2 = temp[2].x1 - temp[1].x1;
	
	double y1 = temp[1].y1 - temp[0].y1;
	double y2 = temp[2].y1 - temp[1].y1;
	
	double z1 = temp[1].z1 - temp[0].z1;
	double z2 = temp[2].z1 - temp[1].z1;
	
	nx = y1 * z2 - y2*z1;
	ny = -(x1*z2 - x2*z1);
	nz = x1 * y2 - x2 * y1;
	
	double hor = nx*nx + ny*ny + nz*nz;
	hor = sqrt(hor);
	nx /= hor;
	ny /= hor;
	nz /= hor;
}

void general_rotation(double x,double y, double z, double &x1, double &y1, double &z1){
	double value = (angle * PI)/180.0;
	x1 = x * cos(value) - y * sin(value);
	y1 = x * sin(value) + y * cos(value);
	z1 = z;
	return;
}


void perspective_projection(){
	glClear(GL_COLOR_BUFFER_BIT);
	d=-500;
	Y_MIN = 100000;
	Y_MAX = -100000;
	int not_horizontal = 0;
	pointer_edge_table=0; //koto tuke porjonto nawa hoise
	counter = 0 ; // temp_edge_table e koita element ache
	angle++; 
	
	cout<<"YMAX and YMIN " << Y_MAX<<" "<<Y_MIN<<endl;
	
	Point temp[5]; 
	for(int i=0;i<connection;i++){
		
		double x1,y1,z1,x2,y2,z2;
		general_rotation(arr[i].x1,arr[i].y1,arr[i].z1,x1,y1,z1);
		
		double tx1=(x1)/(1+(z1/d));
		double ty1=(y1)/((1+z1/d));
		double tz1=(z1)/((1+z1/d));
		
		temp[i].x1 = round(tx1);
		temp[i].y1 = round(ty1);
		temp[i].z1 = round(tz1);
		
		general_rotation(arr[i].x2,arr[i].y2,arr[i].z2,x2,y2,z2);
		double tx2=(x2)/((1+z2/d));
		double ty2=(y2)/((1+z2/d));
		double tz2=(z2)/((1+z2/d));
		
		cout<<tx1<<" "<<ty1<<" "<<tx2<<" "<<ty2<<endl;
		
		x_st=round(tx1);
		y_st=round(ty1);
		x_en=round(tx2);
		y_en=round(ty2);
		
		Y_MIN = min(min(Y_MIN,y_st),y_en);
		Y_MAX = max(max(Y_MAX,y_st),y_en);
		
		cout<<x_st<<" "<<y_st<<" "<<x_en<<" "<<y_en<<endl;
		
		double diff = y_st-y_en;
		if(fabs(diff)>0) {
			cout<<"YES"<<" "<<Y_MIN<<" "<<Y_MAX<<endl;
			make_edge_table(round(tx1),round(ty1),round(tx2),round(ty2),not_horizontal);
			not_horizontal++; 
		}
	}
	
	//calculating N
	double nx,ny,nz;
	calculate_n(temp,n,nx,ny,nz);
	
	//calculating L
	double sx = 0,sy = 0, sz = -d;
	double lx,ly,lz;
	double px=0,py=0,pz=0;
	for(int i=0;i<n;i++){
		px=px+temp[i].x1;
		py=py+temp[i].y1;
		pz=pz+temp[i].z1;
	}
	px /= n;
	py /= n;
	pz /= n;
	
	lx = sx - px;
	ly = sy - py;
	lz = sz - pz;
	
	double value = lx*lx + ly*ly + lz*lz;
	lx /= value;
	ly /= value;
	lz /= value;
	
	double dot_product = nx * lx + ny * ly + nz * lz ;
	//if(dot_product>=0){
		n = not_horizontal;
		sort(edge_table,edge_table+n,sort_edge_table); //sorting been done 	
		cout<<"after sorting " << Y_MAX<<" "<<Y_MIN<<endl;
		for(int j=0;j<n;j++) {
			cout<<edge_table[j].ymin<<" "<<edge_table[j].ymax<<" "<<edge_table[j].dx<<" "<<edge_table[j].dy<<" "<<edge_table[j].x<<endl;
		}
		cout<<"start"<<endl;
		active_list(); 
	//}
	glFlush();		
}

void draw(){
	Point point[5];
	
	for(int i=0;i<n;i++){
		scanf("%lf %lf %lf",&point[i].x1,&point[i].y1,&point[i].z1);
	}
	for(int i=0;i<n;i++){
		arr[i].x1=point[i].x1;
		arr[i].y1=point[i].y1;
		arr[i].z1=point[i].z1;
		
		arr[i].x2=point[(i+1)%n].x1;
		arr[i].y2=point[(i+1)%n].y1;
		arr[i].z2=point[(i+1)%n].z1;
	}
	connection = n;
	perspective_projection();
	
}

void catchKey(int key, int x, int y){
	int choice;
	if(key == GLUT_KEY_LEFT) {
		printf("Left key is pressed\n");
		printf("moving around x axis\n");
		angle=angle-10;
		choice=1;
		perspective_projection();
	}        
    else if(key == GLUT_KEY_RIGHT) {
		 printf("Right key is pressed\n");
		 printf("moving around y axis\n");
		 angle=angle+10;
		 choice=2;
		 perspective_projection();
	}  
    else if(key == GLUT_KEY_DOWN) {
		 printf("Down key is pressed\n");
		 printf("moving around z axis\n");
		 angle=angle-10;
		 choice=0;
		 perspective_projection();
		 
	}  
    else if(key == GLUT_KEY_UP) {
        printf("Up key is pressed\n");
        printf("moving around z axis\n");
        angle=angle+10;
		choice=0;
		perspective_projection();
     }
}


void take_input(){
	glClear(GL_COLOR_BUFFER_BIT);
	int T,t;
	T=1;
	for(t=1;t<=T;t++){
		scanf("%d",&n);
		draw();
	}
}


int main(int argc, char **argv) {
	freopen("test.txt","r",stdin);
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1400,1400);
	//glutInitWindowSize (500,500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("points and lines");
	init2D(0.0,0.0,0.0);
	glutSpecialFunc(catchKey);
	glutDisplayFunc(take_input);
	glutMainLoop();
	return 0;
}
