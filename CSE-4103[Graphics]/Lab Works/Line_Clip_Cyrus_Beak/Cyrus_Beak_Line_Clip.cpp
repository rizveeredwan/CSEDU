#include <bits/stdc++.h>

#define X_MIN -120
#define Y_MIN -120
#define X_MAX  120
#define Y_MAX  120

int in_x[250],in_y[250],ou_x[250],ou_y[250];
int n;

int vector_multi(int a1,int a2,int b1,int b2){
	return (a1*b1+a2*b2);
}

void cyrus_beck_line_clip(int x0,int y0,int x1,int y1){
	double teT = (double)y0 - (double)Y_MAX;
	teT = teT / ((y1-y0)*1.0);
	if(teT>1) teT = 1;
	if(teT<0) teT = 0;
	double teR = (double)x0 - (double)X_MAX;
	teR = teR / ((x1-x0)*1.0);
	if(teR>1) teR = 1;
	if(teR<0) teR = 0;
	double teB = (double)y0 - (double)Y_MIN;
	teB = teB / ((y1-y0)*1.0);
	if(teB>1) teB = 1;
	if(teB<0) teB = 0;
	double teL = (double)x0 - (double)X_MAX;
	teL = teL / ((x1-x0)*1.0);
	if(teL>1) teT = 1;
	if(teL<0) teT = 0;
	
	double tE = 0,tL = 1;
	int dir1 = vector_multi(x1-x0,y1-y0,-1,0); //Left
	if(dir1<0) {
		//entering
		tE=max(tE,teL);
	}
	else{
		tL=min(tL,teL);
	}
	dir1 = vector_multi(x1-x0,y1-y0,0,-1); //Bottom
	if(dir1<0) {
		//entering
		tE=max(tE,teB);
	}
	else{
		tL=min(tL,teB);
	}
	dir1 = vector_multi(x1-x0,y1-y0,1,0); //Right
	if(dir1<0) {
		//entering
		tE=max(tE,teR);
	}
	else{
		tL=min(tL,teR);
	}
	dir1 = vector_multi(x1-x0,y1-y0,0,1);
	if(dir1<0) {
		//entering
		tE=max(tE,teT);
	}
	else{
		tL=min(tL,teT);
	}
	
	
	x0 = round(x0 + tE * (x1-x0)*1.0);
	y0 = round(y0 + tE * (y1 - y0) *1.0);
	x1 = round(x0 + tL * (x1 - x0) * 1.0);
	y1 = round(y1 + tL * (y1 - y0) * 1.0);
	
}

void draw_line(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d %d %d %d",&in_x[i],&in_y[i],&ou_x[i],&ou_y[i]);
	}
}

int main(int argc,char **argv){
	
}
