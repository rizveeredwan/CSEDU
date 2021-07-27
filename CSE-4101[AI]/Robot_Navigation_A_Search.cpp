#include <bits/stdc++.h>
using namespace std;
#define MAX 105

//implementation of A* search

int arr[MAX+1][MAX+1];
int visit[MAX+1][MAX+1];
int parent[MAX+1][MAX+1];
int parent_y[MAX+1][MAX+1];

//direction array
int dix[]={-1,1,0,0};
int diy[]={0,0,1,-1};

struct info{
	int x,y;
	int g_n,f_n;
	int px,py;
};

bool operator < (const info &a,const info &b) {
	if((a.g_n+a.f_n)>(b.g_n+b.f_n)) return true;
	else return false;
}

bool valid(int x,int y,int row,int col){
	if(x>= 0 && x<row && y>=0 && y<col) return true;
	return false;
}

//function to calculate f_n
int calculate_f(int x,int y,int dx,int dy){
	return abs(x-dx)+abs(y-dy); 
}

int robot_navigation(int sx,int sy,int dx,int dy,int row,int col){
	
	memset(visit,0,sizeof(visit)); 
	priority_queue<info>PQ;
	info temp;
	int answer=0;
	if(arr[sx][sy] == 0 && arr[dx][dy] == 0) { //src and destination both can be touched 
		temp.x=sx;
		temp.y=sy;
		temp.g_n=0;
		temp.f_n=calculate_f(sx,sy,dx,dy);
		temp.px=-1;
		temp.py=-1;
		PQ.push(temp);
		while(PQ.empty() != true){
			info u=PQ.top();
			PQ.pop();
			if(visit[u.x][u.y]==1) continue; 
			visit[u.x][u.y]=1;
			parent[u.x][u.y]=u.px;
			parent_y[u.x][u.y]=u.py; 
			if(u.x==dx && u.y==dy) {
				answer=temp.g_n;
				break;
			} 
			for(int i=0;i<=3;i++){
				int x=u.x+dix[i];
				int y=u.y+diy[i];
				bool ok=valid(x,y,row,col);
				if(ok && arr[x][y] == 0 && visit[x][y] == 0) {
					temp.x=x;
					temp.y=y;
					temp.g_n=u.g_n+1;
					temp.f_n=calculate_f(x,y,dx,dy);
					temp.px=u.x;
					temp.py=u.y;
					PQ.push(temp); 
				}
			}
		}
		while(1){
			printf("%d %d\n",dx,dy);
			int x=parent[dx][dy];
			int y=parent_y[dx][dy];
			dx=x;
			dy=y;
			if(dx == -1 && dy == -1) break;
		}
		return answer;
	}
	else{
		cout<<" answer not found. " << endl;
	}
	return -1;
}

int main(int argc,char **argv) {
	
	freopen("in_robot.txt","r",stdin);
	int row,col;
	scanf("%d %d",&row,&col);
	
	memset(arr,0,sizeof(arr));
	int k;
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		arr[a][b]=1;
	}
	int sx,sy,dx,dy;
	scanf("%d %d %d %d",&sx,&sy,&dx,&dy);
	int ans=robot_navigation(sx,sy,dx,dy,row,col);
	printf("%d\n",ans);
	
	
	return 0;
}
