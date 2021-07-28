#include <stdio.h>
#include <string.h>
#include "graphics.h"
using namespace std;

char use1[20];

struct info{
char name[50];
int score;

}ab[20];

void sorting(int value) {
    char line[50];
	int i,j;
	for(i = value - 1; i >= 1; i--) {
		if(ab[i].score > ab[i - 1].score) {
		  int temp = ab[i].score;
		  ab[i].score = ab[i -1].score;
		  ab[i - 1].score = temp;
		  strcpy(line,ab[i].name);
		  strcpy(ab[i].name, ab[i - 1].name);
		  strcpy(ab[i - 1].name,line);
		}
}
} 

void  making_string(int number) {
  int i = -1,rem,v = number;
  while(1)
  {
	      rem = v % 10;
		  v = v / 10;
		  i++;
		  use1[i] = rem + '0';
		  if(v == 0) {
			  i++;
			  use1[i] = NULL;
			  break;
		  }
  }
  for(i = 0; i < strlen(use1)/2;i++) {
	  char temp = use1[i];
	  use1[i] = use1[strlen(use1) - 1 - i];
	  use1[strlen(use1) - 1 - i] = temp;
  } 
      
 }

void printing(int n) {
	int i,x = 800,y = 50;
	char string_number;
	cleardevice();
	readimagefile("score_image.jpg",0,0,795,600);
	settextstyle(COMPLEX_FONT,HORIZ_DIR,3);
	outtextxy(870,20,"High scorers\n");
	for(i = 0;i < n; i++) {
	 making_string(ab[i].score);
	 outtextxy(x,y,ab[i].name);
	 outtextxy(x + 250,y,use1);
	   y = y + 50;
	   }
}

void highscore(int newscore,char newname[20]){
	FILE *fp1;
    fp1 = fopen("input.txt","r");
	int n,i,data;
    char func[50];
	//char newname[] = "Mehreen";
    fscanf(fp1,"%d",&n);
    for(i = 0; i < n; i++) {
        fscanf(fp1,"%s",func);
        fscanf(fp1,"%d",&data);
        strcpy(ab[i].name,func);
        ab[i].score = data;
		 }
	    if(ab[n - 1].score < newscore) {   //new change of parameter newname from console input
		//scanf("%s",newscore);
        strcpy(ab[n - 1].name,newname);
        ab[n - 1].score = newscore;
        sorting(n);
		}
		fclose(fp1);
	    printing(n);
        fopen("input.txt","w");
        fprintf(fp1,"%d\n",n);
        for(i = 0; i < n; i++) {
          fprintf(fp1,"%s %d\n",ab[i].name,ab[i].score);
        }
        fclose(fp1);
	}

void show_score(int number) {
	char score[200];
	sprintf(score,"score = %d\n",number);
	setcolor(WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
	outtextxy(1070,20,score);
}



