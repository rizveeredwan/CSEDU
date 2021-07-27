#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;
#define MAX 700


struct Image{
	int r,g,b;
	int grey_avg;
};

vector<Image>arr[MAX+1];


int width,height;

void init2D(double r, double g, double b){
    glClearColor(r,g,b,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,699,0,699);
}

void draw_pixel(int x, int  y,double r,double g,double b){
	glColor3f(r,g,b);
	glBegin(GL_POINTS);
	//printf("x = %d y = %d %lf %lf %lf\n",x,y,r,g,b);
    glVertex2i(x,y);
    //printf("x = %d y = %d\n",x,y);
    glEnd();
}


unsigned char* ReadBMP(char* filename)
{
    int i;
    FILE* f = fopen(filename, "rb");

    if(f == NULL)
        throw "Argument Exception";

    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

    // extract image height and width from header
    width = *(int*)&info[18];
    height = *(int*)&info[22];

    cout << endl;
    cout << "  Name: " << filename << endl;
    cout << " Width: " << width << endl;
    cout << "Height: " << height << endl;

    int row_padded = (width*3 + 3) & (~3);
    unsigned char* data = new unsigned char[row_padded];
    unsigned char tmp;

    for(int i = 0; i < height; i++)
    {
        fread(data, sizeof(unsigned char), row_padded, f);
        for(int j = 0; j < width*3; j += 3)
        {
            // Convert (B, G, R) to (R, G, B)
            tmp = data[j];
            data[j] = data[j+2];
            data[j+2] = tmp;

            //cout << "R: "<< (int)data[j] << " G: " << (int)data[j+1]<< " B: " << (int)data[j+2]<< endl;
            Image  temp;
            temp.r = (int)data[j];
            temp.g = (int)data[j+1];
            temp.b = (int)data[j+2];
            temp.grey_avg = (temp.r+temp.g+temp.b)/3;
			arr[i].push_back(temp);
        }
    }

    fclose(f);
    return data;
}

void draw_color_image(){
	glClear(GL_COLOR_BUFFER_BIT);
	printf("ase\n");
	for(int i=0;i<height;i++) {
		for(int j=0;j<width;j++) {
			//cout<<i<<" "<<j<<endl;
			draw_pixel(i,j,arr[i][j].r/255.0,arr[i][j].g/255.0,arr[i][j].b/255.0);
		}
	}
	glFlush();
}

void draw_color_image_grey(){
	glClear(GL_COLOR_BUFFER_BIT);
	printf("ase\n");
	for(int i=0;i<height;i++) {
		for(int j=0;j<width;j++) {
			//cout<<i<<" "<<j<<endl;
			draw_pixel(i,j,arr[i][j].grey_avg/255.0,arr[i][j].grey_avg/255.0,arr[i][j].grey_avg/255.0);
		}
	}
	glFlush();
}

int halftone_approximate(int value){
	if(value<25) return 0;
	if(value<=50) return 1;
	if(value<=76) return 2;
	if(value<=102) return 3;
	if(value<=128) return 4;
	if(value<=154) return 5;
	if(value<=180) return 6;
	if(value<=206) return 7;
	if(value<=232) return 8;
	if(value<=258) return 9;
}

struct Point{
	int x,y;
	double col;
};

void half_tone_fill_up(int i, int j, int co) {
	//cout<<co<<" "<<i<<" "<<j<<endl;
	
	if(co>=1) {
		draw_pixel(i+1,j+1,1,1,1);
		//final_grid[i+1][j+1] = 255;
	}
	else {
		draw_pixel(i+1,j+1,0,0,0);
	}
	if(co>=2) {
		draw_pixel(i+1,j,1,1,1);
		
	}
	else {
		draw_pixel(i+1,j,0,0,0);
	}
	if(co>=3) {
		draw_pixel(i+1,j+2,1,1,1);
		//final_grid[i+1][j+2] = 255;
	}
	else {
		draw_pixel(i+1,j+2,0,0,0);
	}
	if(co>=4) {
		draw_pixel(i+2,j+1,1,1,1);
		//final_grid[i+2][j+1] = 255;
	}
	else {
		draw_pixel(i+2,j+1,0,0,0);
	}
	if(co>=5) {
		//final_grid[i][j+2] = 255;
		draw_pixel(i,j+2,1,1,1);
	}
	else {
		draw_pixel(i,j+2,0,0,0);
	}
	if(co>=6) {
		draw_pixel(i+2,j,1,1,1);
		//final_grid[i+2][j] = 255;
	}
	else {
		draw_pixel(i+2,j,0,0,0);
	}
	if(co>=7) {
		draw_pixel(i,j,1,1,1);
		//final_grid[i][j] = 255;
	}
	if(co>=8) {
		//final_grid[i+2][j+2] = 255;
		draw_pixel(i+2,j+2,1,1,1);
	}
	else {
		draw_pixel(i+2,j+2,0,0,0);
	}
	if(co>=9) {
		//final_grid[i][j+1] = 255;
		draw_pixel(i,j+1,1,1,1);
	}
	else {
		draw_pixel(i,j+1,0,0,0);
	}
	//cout<<"don"<<endl;
}


void halftone(){
	glClear(GL_COLOR_BUFFER_BIT);
	cout<<height<<" "<<width<<endl;
	for(int i=0;i<height;i+=3) {
		//cout<<"i = " <<i<<endl;
		for(int j=0;j<width;j+=3) {
			cout<<j<<endl;
			vector<Point>temp;
			
			double val = arr[i][j].grey_avg;
			Point variable;
			variable.x=i;
			variable.y=j;
			variable.col=0;
			
			int cnt=1;
			int col=width;
			
			if(i<height) {
				if((j+1)<col) {
					val=val+arr[i][j+1].grey_avg;
					cnt++;
					variable.x=i;
					variable.y=j+1;
					variable.col=0;
					temp.push_back(variable);
				}
				if((j+2)<col) {
					val=val+arr[i][j+2].grey_avg;
					cnt++;
					variable.x=i;
					variable.y=j+2;
					variable.col=0;
					temp.push_back(variable);
				}
			}
			
			if((i+1)<height) {
				if(j<col) {
					val=val+arr[i+1][j].grey_avg;
					cnt++;
					variable.x=i+1;
					variable.y=j;
					variable.col=0;
					temp.push_back(variable);
				}
				if((j+1)<col) {
					val=val+arr[i+1][j+1].grey_avg;
					cnt++;
					variable.x=i+1;
					variable.y=j+1;
					variable.col=0;
					temp.push_back(variable);
				}
				if((j+2)<col) {
					val=val+arr[i+1][j+2].grey_avg;
					cnt++;
					variable.x=i+1;
					variable.y=j+2;
					variable.col=0;
					temp.push_back(variable);
				}
			}
			
			
			if((i+2)<height) {
				if(j<col) {
					val=val+arr[i+2][j].grey_avg;
					cnt++;
					variable.x=i+2;
					variable.y=j;
					variable.col=0;
					temp.push_back(variable);
				}
				if((j+1)<col) {
					val=val+arr[i+2][j+1].grey_avg;
					cnt++;
					variable.x=i+2;
					variable.y=j+1;
					variable.col=0;
					temp.push_back(variable);
				}
				else {
					variable.x=i+2;
					variable.y=j+1;
					variable.col=0;
					temp.push_back(variable);
				}
				if((j+2)<col) {
					val=val+arr[i+2][j+2].grey_avg;
					cnt++;
					variable.x=i+2;
					variable.y=j+2;
					variable.col=0;
					temp.push_back(variable);
				}
				else {
					variable.x=i+2;
					variable.y=j+2;
					variable.col=0;
					temp.push_back(variable);
				}
			}
			//cout<<"do 3 " << endl;
			int avg = val / cnt;
			int grp = halftone_approximate(avg);
			half_tone_fill_up(i,j,grp);
			//cout<<"i = " <<i<<endl;
		}
	}
	cout<<"done"<<endl;
	glFlush();
}


void draw_color_image_halftone(){
	
	printf("ase\n");
	for(int i=0;i<height;i++) {
		for(int j=0;j<width;j++) {
			//cout<<i<<" "<<j<<endl;
			draw_pixel(i,j,arr[i][j].grey_avg/255.0,arr[i][j].grey_avg/255.0,arr[i][j].grey_avg/255.0);
		}
	}
	glFlush();
}


int main(int argc, char **argv){
	ReadBMP("Lion(1).bmp");
	

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    
    glutCreateWindow("Color Image");
    glutDisplayFunc(draw_color_image);
	init2D(0,0,0);
	
	glutCreateWindow("Grey Image");
	glutDisplayFunc(draw_color_image_grey);
	init2D(0,0,0);
	
	glutCreateWindow("Halftone Image");
	glutDisplayFunc(halftone);
	init2D(0,0,0);
	
    //glutDisplayFunc(draw_color_image);
    //
    //
    glutMainLoop();
}
