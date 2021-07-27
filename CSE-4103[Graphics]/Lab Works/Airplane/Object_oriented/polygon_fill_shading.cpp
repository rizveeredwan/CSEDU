#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

#define MAX 7000
#define MAX_LINE 25
#define PI acos(-1.0)
#define INF 1000000000


//structure to represent point 
struct Point{
	double x1,y1,z1; 
};
Point point[MAX+1]; 

//A structure for line 
struct Line{
	double x1,y1,z1,x2,y2,z2;
};

//definition of a vector 
struct Vector{
	double x,y,z;
};

Vector S;


//structure to define a surface 
//n = number of lines 
//each line stays in line array (0,1) (1,2) (2,0) 
struct Surface{
	int n;
	Line line[MAX_LINE+1]; 
	
	bool operator < (const Surface &comp) const {
		double a_min = INF;
		double b_min = INF;
		for(int i=0;i<n;i++) {
			a_min = min(min(a_min,line[i].z1),line[i].z2);
		}
		for(int i=0;i<comp.n;i++) {
			b_min = min(min(b_min,comp.line[i].z1),comp.line[i].z2);
		}
		a_min = a_min - S.z;
		b_min = b_min - S.z;
	
		/*if(S.z<0) {
			if(a_min>b_min) return true;
			return false;
		}
		else {*/
			if(a_min<b_min) return true;
			return false;
		//}
		
	}
};

Surface surface[MAX+1]; 



//Global variables
double d,m;  //d = depth , m related to projection
double angle; //angle for rotation
int choice; //choice for x,y or z rotation 
bool flag; //flag just for drawing specific object
int given_input,connection;

//for shading
double shading_cos_value=1;

//preparation of window 
void init2D(double r, double g, double b){
	glClearColor(r,g,b,0.0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (-1000,1000,-1000,1000);
}

//function to rotate
void general_rotation(double x,double y, double z, double &x1, double &y1, double &z1){
	double value = (angle * PI)/180.0;
	x1 = x * cos(value) - y * sin(value);
	y1 = x * sin(value) + y * cos(value);
	z1 = z;
	return;
}

//function to project 
void general_projection(double x, double y, double z, double &x1, double &y1, double &z1, double d,double m){
	double tx1=(x)/(1+(z+m)/d);
	double ty1=(y)/(1+(z+m)/d);
	double tz1=(z)/(1+((z+m)/d));
	
	/*double tx1,ty1,tz1;
	tx1 = x*(2500/(d-z));
	ty1 = y*(2500/(d-y));
	tz1=1500;*/
	
	x1 = tx1;
	y1 = ty1;
	z1 = tz1;
}

//section to draw line
struct Line_Draw{
	double x_st,y_st,x_en,y_en;
	
	//function to find zone
	int find_zone(Line_Draw &obj){
		double dx=obj.x_en-obj.x_st;
		double dy=obj.y_en-obj.y_st;
	
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
	
	//function to translate 8 way symmetry
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
	
	//function to draw line
	void line_draw(Line_Draw &obj){
		
		glColor3f(1.0*shading_cos_value,1.0*shading_cos_value,1.0*shading_cos_value);
		glBegin(GL_POINTS);
		
		int zone = obj.find_zone(obj);
		double x1=obj.return_x(obj.x_st,obj.y_st,zone,0,0);
		double y1=obj.return_x(obj.x_st,obj.y_st,zone,0,1);
		double x2=obj.return_x(obj.x_en,obj.y_en,zone,0,0);
		double y2=obj.return_x(obj.x_en,obj.y_en,zone,0,1);
		
		if(x1>x2){
			double temp=x1;
			x1=x2;
			x2=temp;

			temp=y1;
			y1=y2;
			y2=temp;
		}
		
		double x = x1;
		double y = y1;

		double dx=x2-x1;
		double dy=y2-y1;
		double d = 2*dy - dx;
		double d_n= 2*dy;
		double d_ne=2*(dy-dx);
		
		double tempx=obj.return_x(x,y,0,zone,0);
		double tempy=obj.return_x(x,y,0,zone,1);
		
		glVertex2i(round(tempx),round(tempy));
		
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
		
		tempx=obj.return_x(x,y,0,zone,0);
		tempy=obj.return_x(x,y,0,zone,1);
		glVertex2i(round(tempx),round(tempy));
		
		}
		tempx=obj.x_en;
		tempy=obj.y_en;
		glVertex2i(round(tempx),round(tempy));
		glEnd();
		return;

	}
};


//Polygon Filling
struct Edge_table{
	double ymin;
	double ymax;
	double x;
	double dx;
	double dy;
	int sign;
	double new_x;
	double new_y;
	
	bool operator < (const Edge_table &a) const {
			if(ymin<a.ymin) return true;
			if(ymin == a.ymin) {
				if(x<a.x) return true;
				if(x == a.x) return true;
				return false;
			}
			return false;
	}
};

struct Shading_Structure{
	
	
	double dot_product(Shading_Structure &obj,Vector a, Vector b){
		double value;
		value = a.x * b.x + a.y * b.y + a.z * b.z;
		return value;
	}
	
	Vector light_normal_vector(Shading_Structure &obj,Vector P) {
		Vector L;
		L.x = -P.x + S.x;
		L.y = -P.y + S.y;
		L.z = -P.z + S.z;
		double value = obj.vector_value(obj,L);
		L.x /= value;
		L.y /= value;
		L.z /= value;
		return L;
	}
	
	Vector vorkendro(Shading_Structure &obj,Surface temp) {
		Vector result;
		result.x=0;
		result.y=0;
		result.z=0;
		for(int i=0;i<temp.n;i++) {
			result.x = result.x + temp.line[i].x1;
			result.y = result.y + temp.line[i].y1;
			result.z = result.z + temp.line[i].z1;
		}
		result.x /= temp.n;
		result.y /= temp.n;
		result.z /= temp.n;
		return result;
	}
	double vector_value(Shading_Structure &obj,Vector a) {
		double value = a.x*a.x + a.y * a.y + a.z * a.z;
		value = sqrt(value);
		return value;
	}
	Vector cross_product(Shading_Structure &obj, Vector a, Vector b){
		Vector result;
		result.x = a.y * b.z - b.y * a.z;
		result.y = b.x * a.z - a.x * b.z;
		result.z = a.x * b.y - b.x * a.y ;
		double value = obj.vector_value(obj,result);
		result.x /= value;
		result.y /= value;
		result.z /= value;
		return result;
	}
	
	double shading(Shading_Structure &obj, Surface temp){
	Vector N,P,One,Two,L;
	P.x=0;
	P.y=0;
	P.z=0;
	/********Ami ekvabe korsi eta onek vabe kora possible****/ 

	/*One.x = temp.line[0].x1 - temp.line[0].x2;
	One.y = temp.line[0].y1 - temp.line[0].y2;
	One.z = temp.line[0].z1 - temp.line[0].z2;
	
	Two.x = temp.line[1].x2 - temp.line[1].x1;
	Two.y = temp.line[1].y2 - temp.line[1].y1;
	Two.z = temp.line[1].z2 - temp.line[1].z1;
	
	/*Two.x = temp.line[0].x1 - temp.line[0].x2;
	Two.y = temp.line[0].y1 - temp.line[0].y2;
	Two.z = temp.line[0].z1 - temp.line[0].z2;
	
	One.x = temp.line[1].x2 - temp.line[1].x1;
	One.y = temp.line[1].y2 - temp.line[1].y1;
	One.z = temp.line[1].z2 - temp.line[1].z1;*/
	
	/*One.x = temp.line[0].x2 - temp.line[0].x1;
	One.y = temp.line[0].y2 - temp.line[0].y1;
	One.z = temp.line[0].z2 - temp.line[0].z1;
	
	Two.x = temp.line[temp.n-1].x1 - temp.line[temp.n-1].x2;
	Two.y = temp.line[temp.n-1].y1 - temp.line[temp.n-1].y2;
	Two.z = temp.line[temp.n-1].z1 - temp.line[temp.n-1].z2;*/
	
	/*Two.x = temp.line[0].x2 - temp.line[0].x1;
	Two.y = temp.line[0].y2 - temp.line[0].y1;
	Two.z = temp.line[0].z2 - temp.line[0].z1;
	
	One.x = temp.line[temp.n-1].x1 - temp.line[temp.n-1].x2;
	One.y = temp.line[temp.n-1].y1 - temp.line[temp.n-1].y2;
	One.z = temp.line[temp.n-1].z1 - temp.line[temp.n-1].z2; */
	
	One.x = temp.line[0].x2 - temp.line[0].x1;
	One.y = temp.line[0].y2 - temp.line[0].y1;
	One.z = temp.line[0].z2 - temp.line[0].z1;
	
	Two.x = temp.line[1].x2 - temp.line[1].x1;
	Two.y = temp.line[1].y2 - temp.line[1].y1;
	Two.z = temp.line[1].z2 - temp.line[1].z1;
	
	N = obj.cross_product(obj,One,Two);
	P = obj.vorkendro(obj,temp);
	L = obj.light_normal_vector(obj,P);
	
	double result = obj.dot_product(obj,N,L);
	return result;
		
	}

};


//A structure to draw polygon filling 
struct scan_line_polygon_filling{
	Edge_table edge_table[MAX+1],temp_edge_table[MAX+1]; //Full edge table and koto tuku niye kaj kortesi
	double Y_MIN,Y_MAX;
	int n; //For counting lines 
	int pointer_edge_table,counter;
	
	//initialize 
	void initialize(scan_line_polygon_filling &obj){
		obj.pointer_edge_table=0;
		obj.counter = 0;
		obj.Y_MIN = INF; 
		obj.Y_MAX = -INF;
	}
	
	//function to make edge table 	
	void make_edge_table(scan_line_polygon_filling &obj, double x1, double y1, double x2, double y2,int number){
		int guni = number;
		if(y1<y2) {
			obj.edge_table[number].ymin = y1;
			obj.edge_table[guni].ymax = y2;
			obj.edge_table[guni].x = x1 ;
			obj.edge_table[guni].dx = abs(x2-x1);
			obj.edge_table[guni].dy = abs(y2 - y1);
			obj.edge_table[guni].new_x = x1;
			obj.edge_table[guni].new_y = y1;
			if(((x2-x1)*(y2-y1))>=0){
				obj.edge_table[guni].sign=1;
			}
			else{
				obj.edge_table[guni].sign=-1;
			}
		}
		else {
			obj.edge_table[number].ymin = y2;
			obj.edge_table[guni].ymax = y1;
			obj.edge_table[guni].x = x2 ;
			obj.edge_table[guni].dx = abs(x2-x1);
			obj.edge_table[guni].dy = abs(y2 - y1);
			obj.edge_table[guni].new_x = x2;
			obj.edge_table[guni].new_y = y2;
			if(((x2-x1)*(y2-y1))>=0){
				obj.edge_table[guni].sign=1;
			}
			else{
			 obj.edge_table[guni].sign=-1;
			}
		}	
	}

	
	//function start
	void polygon_filling(scan_line_polygon_filling &obj,Surface temp){
		obj.initialize(obj);
		int guni = 0;
		for(int i=0;i<temp.n;i++) {
		obj.Y_MIN = min(obj.Y_MIN,round(temp.line[i].y1));
		obj.Y_MAX = max(obj.Y_MAX,round(temp.line[i].y1));
		obj.Y_MAX = max(obj.Y_MAX,round(temp.line[i].y2));
		obj.Y_MIN = min(obj.Y_MIN,round(temp.line[i].y2));
			if(temp.line[i].y1 != temp.line[i].y2) {
				obj.make_edge_table(obj,round(temp.line[i].x1),round(temp.line[i].y1),round(temp.line[i].x2),round(temp.line[i].y2),guni);
				guni++;
			}
		}
		obj.n=guni; 
		sort(obj.edge_table,obj.edge_table+obj.n);
		obj.active_list(obj);
	}
	
	//return those edeges where ymin == desired ymin
	int return_edge(scan_line_polygon_filling &obj, double ymin){
		//start from pointer
		for(int i=obj.pointer_edge_table;i<obj.n;i++){
			if(obj.edge_table[i].ymin == ymin){
				obj.counter++;
				obj.temp_edge_table[counter]=obj.edge_table[i];
				obj.pointer_edge_table++;
			}
			else {
				break;
			}
		}
		return obj.counter; 
	}

	
	//The working function 
	void active_list(scan_line_polygon_filling &obj){
		double y_min,y_max;
		y_min = obj.Y_MIN;
		y_max = obj.Y_MAX;
		obj.pointer_edge_table=0;
		obj.counter = 0;
		for(double i=y_min;i<y_max;i++){
			//edge niye asi jeigular ymin i er shoman
			obj.counter = obj.return_edge(obj,i); 
			// x er basis e sort kori 
			sort(obj.temp_edge_table+1,obj.temp_edge_table+counter); 
			//scan line 
			for(int j=1;j<=obj.counter && (j+1)<=obj.counter; j+= 2) {
				//draw line between j and j+1
				//make set of lines 
				
				Line_Draw main_object;
				main_object.x_st = obj.temp_edge_table[j].x;
				main_object.y_st = obj.temp_edge_table[j].ymin;
				main_object.x_en = obj.temp_edge_table[j+1].x;
				main_object.y_en = obj.temp_edge_table[j+1].ymin;
				
				main_object.line_draw(main_object); 
		}
		//update 
		//now change the edges 
		int second_counter = 0;
		for(int j=1;j<=obj.counter;j++){
			obj.temp_edge_table[j].ymin++;
			if(obj.temp_edge_table[j].ymin != obj.temp_edge_table[j].ymax){
				second_counter++;
				obj.temp_edge_table[second_counter].ymin=obj.temp_edge_table[j].ymin;
				obj.temp_edge_table[second_counter].ymax=obj.temp_edge_table[j].ymax;
				obj.temp_edge_table[second_counter].dx= obj.temp_edge_table[j].dx;
				obj.temp_edge_table[second_counter].dy=	obj.temp_edge_table[j].dy;
				obj.temp_edge_table[second_counter].sign=	obj.temp_edge_table[j].sign;
				obj.temp_edge_table[second_counter].new_x=	obj.temp_edge_table[j].new_x;
				obj.temp_edge_table[second_counter].new_y=	obj.temp_edge_table[j].new_y;
				if(obj.temp_edge_table[second_counter].dy != 0){ //x will change 
						double lob = (double)obj.temp_edge_table[j].dx*1.0;
						double hor = (double)obj.temp_edge_table[j].dy*1.0;
						double frac = (double)obj.temp_edge_table[j].new_x+1.0*(obj.temp_edge_table[j].sign)*(lob/hor)*(obj.temp_edge_table[j].ymin-obj.temp_edge_table[j].new_y);
						obj.temp_edge_table[second_counter].x = frac;
				}
				else{
					obj.temp_edge_table[second_counter].x=obj.temp_edge_table[j].x;
				}
			}
		}
		obj.counter = second_counter;
	}
}


};




//the controlling function of the whole process 
void controlling2(){
	glClear(GL_COLOR_BUFFER_BIT);
	d=2500; 
	m=1500;
	
	for(int i=0;i<connection;i++){
		Surface temp;
		temp.n = surface[i].n;
		for(int j=0;j<surface[i].n;j++){
			
			double x1,y1,z1,x2,y2,z2;
			
			
			if(choice==0) {
				//around z axis 
				general_rotation(surface[i].line[j].x1,surface[i].line[j].y1,surface[i].line[j].z1,x1,y1,z1);
				surface[i].line[j].x1 = x1;
				surface[i].line[j].y1 = y1;
				surface[i].line[j].z1 = z1;
				general_projection(x1,y1,z1,x1,y1,z1,d,m);
				
				general_rotation(surface[i].line[j].x2,surface[i].line[j].y2,surface[i].line[j].z2,x2,y2,z2);
				surface[i].line[j].x2 = x2;
				surface[i].line[j].y2 = y2;
				surface[i].line[j].z2 = z2;
				general_projection(x2,y2,z2,x2,y2,z2,d,m);
			}
			else if(choice==1) {
				general_rotation(surface[i].line[j].y1,surface[i].line[j].z1,surface[i].line[j].x1,y1,z1,x1);
				surface[i].line[j].x1 = x1;
				surface[i].line[j].y1 = y1;
				surface[i].line[j].z1 = z1;
				general_projection(x1,y1,z1,x1,y1,z1,d,m);
				
				general_rotation(surface[i].line[j].y2,surface[i].line[j].z2,surface[i].line[j].x2,y2,z2,x2);
				surface[i].line[j].x2 = x2;
				surface[i].line[j].y2 = y2;
				surface[i].line[j].z2 = z2;
				general_projection(x2,y2,z2,x2,y2,z2,d,m);
			}
			else if(choice==2) {
				general_rotation(surface[i].line[j].z1,surface[i].line[j].x1,surface[i].line[j].y1,z1,x1,y1);
				surface[i].line[j].x1 = x1;
				surface[i].line[j].y1 = y1;
				surface[i].line[j].z1 = z1;
				general_projection(x1,y1,z1,x1,y1,z1,d,m);
				
				general_rotation(surface[i].line[j].z2,surface[i].line[j].x2,surface[i].line[j].y2,z2,x2,y2);
				surface[i].line[j].x2 = x2;
				surface[i].line[j].y2 = y2;
				surface[i].line[j].z2 = z2;
				general_projection(x2,y2,z2,x2,y2,z2,d,m);
			}
		}
	}
	
	sort(surface,surface+connection);
	
	//now drawing
	for(int i=0;i<connection;i++) {
		Surface temp;
		temp.n = surface[i].n;
		for(int j=0;j<surface[i].n;j++){
			
			double x1,y1,z1,x2,y2,z2;
			x1 = surface[i].line[j].x1;
			y1 = surface[i].line[j].y1;
			z1 = surface[i].line[j].z1;
			general_projection(x1,y1,z1,x1,y1,z1,d,m);
			
			x2 = surface[i].line[j].x2;
			y2 = surface[i].line[j].y2;
			z2 = surface[i].line[j].z2;
			general_projection(x2,y2,z2,x2,y2,z2,d,m);
			
			
			temp.line[j].x1 = x1;
			temp.line[j].y1 = y1;
			temp.line[j].z1 = z1;
			
			temp.line[j].x2 = x2;
			temp.line[j].y2 = y2;
			temp.line[j].z2 = z2;
		}
		
		/*First find shading*/
		Shading_Structure shade;
		double value = shade.shading(shade,temp);
		if(value>=0) {
			shading_cos_value=value;
			/* Drawing Polygon */
			scan_line_polygon_filling obj;
			obj.initialize(obj);
			obj.polygon_filling(obj,temp);
		}
		else {
			shading_cos_value=0;
			/* Drawing Polygon */
			scan_line_polygon_filling obj;
			obj.initialize(obj);
			obj.polygon_filling(obj,temp);
		}
		
		
	}
	glFlush(); 
}


//function to take input
void input(){
	scanf("%d %d",&given_input,&connection);
	cout<<given_input<<" "<<connection<<endl;
	for(int i=0;i<given_input;i++){
		scanf("%lf %lf %lf",&point[i].x1,&point[i].y1,&point[i].z1);
		if(flag) { //for drawing cow 
			point[i].x1 *= 400/80;
			point[i].y1 *= 400/80;
			point[i].z1 *= 400/80;
			//cout<<point[i].x1<<" "<<point[i].y1<<" "<<point[i].z1<<endl;
		}
	}
	for(int i=0;i<connection;i++){
		scanf("%d",&surface[i].n);
		int target[MAX_LINE+1];
		for(int j=0;j<surface[i].n;j++) {
			scanf("%d",&target[j]);
		}
		for(int j=0;j<surface[i].n;j++) {
			int one = target[j];
			int two = target[(j+1)%surface[i].n];
			
			surface[i].line[j].x1 = point[one].x1;
			surface[i].line[j].y1 = point[one].y1;
			surface[i].line[j].z1 =	point[one].z1;
			
			surface[i].line[j].x2 = point[two].x1;
			surface[i].line[j].y2 =	point[two].y1;
			surface[i].line[j].z2 = point[two].z1;
		}
	}
	//initialize
	angle=0; 
};

void catchKey(int key, int x, int y){
	//printf("key %d\n",key);
	if(key == GLUT_KEY_LEFT) {
		//printf("Left key is pressed\n");
		//printf("moving around x axis\n");
		angle=angle+1;
		choice=1;
		controlling2();
	}        
    else if(key == GLUT_KEY_RIGHT) {
		// printf("Right key is pressed\n");
		 //printf("moving around y axis\n");
		 angle=angle-1;
		 choice=2;
		 controlling2();
	}  
    else if(key == GLUT_KEY_DOWN) {
		 //printf("Down key is pressed\n");
		 //printf("moving around z axis\n");
		 angle=angle-1;
		 choice=0;
		 controlling2();
		 
	}  
    else if(key == GLUT_KEY_UP) {
        //printf("Up key is pressed\n");
        //printf("moving around z axis\n");
        angle=angle+1;
		choice=0;
		controlling2();
	}
	else if(key == 112) {
		choice = -1;
		if(S.x>7000) {
			S.x -= 500;
		}
		else {
			S.x += 500;
		}
		controlling2();
	}
	else if(key == 114) {
		choice = -1;
		if(S.y>7000) {
			S.y -= 500;
		}
		else {
			S.y += 500;
		}
		controlling2();
	}
	else if(key == 1) {
		choice = -1;
		if(S.z>7000) {
			S.z -= 500;
		}
		else {
			S.z += 500;
		}
		controlling2();
	}
	
}




int main(int argc, char **argv) {

	S.x=300;
	S.y=0;
	S.z=3000;
	
	//printf("%lf %lf %lf\n",S.x,S.y,S.z);

	flag=true;
	freopen("sphere.ply","r",stdin);
	input();
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (600,600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("points and lines");
	init2D(0.0,0.0,0.0);
	glutSpecialFunc(catchKey);
	glutDisplayFunc(controlling2);
	glutMainLoop();
	
}


