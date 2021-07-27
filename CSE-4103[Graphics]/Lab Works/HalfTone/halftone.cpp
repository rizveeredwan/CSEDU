#include <bits/stdc++.h>
using namespace std;

int final_grid[700][700]={0};

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

void half_tone_fill_up(int i, int j, int co) {
	//cout<<co<<" "<<i<<" "<<j<<endl;
	if(co == 0) {
		for(int k=i;k<=i+2;k++) {
			for(int l=j;l<=j+2;l++) {
				final_grid[k][l]=0;
			}
		}
	}
	if(co>=1) {
		final_grid[i+1][j+1] = 255;
	}
	if(co>=2) {
		final_grid[i+1][j] = 255;
	}
	if(co>=3) {
		final_grid[i+1][j+2] = 255;
	}
	if(co>=4) {
		final_grid[i+2][j+1] = 255;
	}
	if(co>=5) {
		final_grid[i][j+2] = 255;
	}
	if(co>=6) {
		final_grid[i+2][j] = 255;
	}
	if(co>=7) {
		final_grid[i][j] = 255;
	}
	if(co>=8) {
		final_grid[i+2][j+2] = 255;
	}
	if(co>=9) {
		final_grid[i][j+1] = 255;
	}
}

int main(void){
	freopen("columns.ascii.pgm","r",stdin);
	freopen("test.ascii.pgm","w",stdout);
	string type,comment;
	getline(cin,type); //P2
	getline(cin,comment); //comment
	
	int height,width,max_color;
	cin>>width>>height>>max_color;
	
	int average[height+10][width+10];
	for(int i=1;i<=height;i++) {
		for(int j=1;j<=width;j=j+1) {
			scanf("%d",&average[i][j]);
		}
	}
	
	for(int i=1;i<700;i++) {
		for(int j=1;j<700;j++) {
			final_grid[i][j] = 0;
		}
	}
	//half tone approximation
	
	for(int i=1;i<=height;i=i+3) {
		
		//cout<<"size = " << average[i].size()<<endl;
		for(int j=1; j<=width;j=j+3) {
			int line=0;
			int point=0;
			line++;
			point++;
			
			int value = average[i][j];
			if((j+1)<=width) {
				 value += average[i][j+1];
				 point++;
			}
			if((j+2)<= width) {
				 value += average[i][j+2];
				 point++;
			}

			
			if((i+1)<=height) {
				value += average[i+1][j];
				point++;
				
				if((j+1)<=width) {
					value += average[i+1][j+1];
					point++;
				}
				if((j+2)<=width) {
					value += average[i+1][j+2];
					point++;
				}
				line++;
			}
			if((i+2)<=height) {
				value += average[i+2][j];
				point++;
				
				if((j+1)<=width) {
					value += average[i+2][j+1];
					point++;
				}
				if((j+2)<= width) {
					value += average[i+2][j+2];
					point++;
				}
				line++;
			}
			int color = halftone_approximate(value/(point));
			//cout<<color<<endl;
			half_tone_fill_up(i,j,color);
			/*if(i==1 && j == 1) {
				cout<<color<<endl;
				for(int k=i;k<=i+2;k++) {
					for(int l=j;l<=j+2;l++) {
						cout<<final_grid[k][l]<<" ";
					}
					cout<<endl;
				}
			}
			/*
			}*/
		}
		//cout<<ptr<<endl;
	}
	//printing
	cout<<type<<endl;
	cout<<comment<<endl;
	cout<<width<<" "<<height<<endl;
	cout<<max_color<<endl;
	for(int i=1;i<=height;i++) {
		for(int j=1;j<=width;j++) {
			cout<<final_grid[i][j]<<" ";
		}
	}
	
	return 0;
}
