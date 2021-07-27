#include <bits/stdc++.h>

using namespace std;

int main(void){

    freopen("in3.txt","w",stdout);
    int xmin,ymin,xmax,ymax;
    xmin = -200;
    ymin = -200;
    xmax = 200;
    ymax = 200;
    printf("%d %d %d %d\n",xmin,ymin,xmax,ymax);
    int n=20;
	printf("%d\n",n);
    for(int i=1;i<=20;i++){
        int x_st=rand()%220;
        int y_st=rand()%220;
        int x_en=rand()%220;
        int y_en=rand()%220;;
        bool ok=rand()%2;
        if(!ok) x_st *= -1;
        ok=rand()%2;
        if(!ok) y_st *= -1;
        ok=rand()%2;
        if(!ok) x_en *= -1;
        ok=rand()%2;
        if(!ok) y_en *= -1;

        printf("%d %d %d %d\n",x_st,y_st,x_en,y_en);
    }

    /*for(int i=1;i<=220;i++){
		int x_st=0;
        int y_st=0;
        int x_en=-5;
        int y_en=i;
        printf("%d %d %d %d\n",x_st,y_st,x_en,y_en);
    }

    for(int i=1;i<=220;i++){
		int x_st=0;
        int y_st=0;
        int x_en=5;
        int y_en=-i;
        printf("%d %d %d %d\n",x_st,y_st,x_en,y_en);
    }

    for(int i=1;i<=220;i++){
		int x_st=0;
        int y_st=0;
        int x_en=-5;
        int y_en=-i;
        printf("%d %d %d %d\n",x_st,y_st,x_en,y_en);
    }*/
    return 0;

}
