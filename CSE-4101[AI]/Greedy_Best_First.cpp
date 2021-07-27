#include <bits/stdc++.h>
using namespace std;
#define MAX 103
#define inf 100000

vector<int>graph[MAX+1],weight[MAX+1];

struct info{
	int n,inner_cost,par;
};

bool operator < (const info &a, const info &b) {
		if(a.inner_cost < b.inner_cost) return false;
		else return false;
}

int dist[MAX+1];
int parent[MAX+1];

void greedy_best_search(int src,int des,int node){
	
	for(int i=1;i<=node;i++){
		dist[i]=inf;
		parent[i]= -1;
	}
	dist[src]=0;
	priority_queue<info>PQ;
	info temp;
	temp.n=src;
	temp.inner_cost=dist[src];
	PQ.push(temp);
	
	while(PQ.empty() !=true) {
		info u=PQ.top();
		PQ.pop();
		if(dist[u.n] == u.inner_cost) {
			parent[u.n] = u.par;
		}
		else{
			continue;
		}
		for(int i=0;i<graph[u.n].size();i++){
			int v=graph[u.n][i];
			if(dist[v]>(weight[u.n][i])){
				dist[v]=weight[u.n][i];
				temp.n=v;
				temp.inner_cost=dist[v];
				temp.par=u.n;
				PQ.push(temp);
			}
		}
	}
	
}

void path_print(int des){
	vector<int>path;
	if(dist[des] != inf) {
		while(1){
		path.push_back(des);
		des = parent[des];
		if(des == -1) break;
	}
	reverse(path.begin(),path.end());
	for(int i=0;i<path.size();i++){
		cout<<path[i]<<" ";
	}
	cout<<endl;	
  }
  else{
	  cout<<"path doesn't exist" << endl;
  }
  return;
}

//solution tested for slide example Romania Traversal 
int main(int argc, char **argv) {
	int node,edge;
	scanf("%d %d",&node,&edge);
	
	for(int i=1;i<=edge;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		graph[a].push_back(b);
		weight[a].push_back(c);
	}
	
	int src,des;
	scanf("%d %d",&src,&des);
	greedy_best_search(src,des,node);
	path_print(des);
}
