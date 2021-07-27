#include <bits/stdc++.h>
using namespace std;
#define MAX 9

int dim;
int dx[] = {0,0,1,-1,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,1,-1,-1};

struct Info{
	int board[MAX+1][MAX+1];
	int conflict;
	bool operator < (const Info &a) const {
		for(int i=1;i<=dim;i++){
			for(int j=1;j<=dim;j++){
				if(board[i][j]<a.board[i][j]) return true;
				if(board[i][j]>a.board[i][j]) return false;
			}
		}
		return false;
	}
};
map<Info,int>M;

int min_conflict(int board[MAX+1][MAX+1]){
	int conflict=0;
	for(int i=1;i<=dim;i++){
		for(int j=1;j<=dim;j++) {
			if(board[i][j] == 1) {
				//eikhane queen ase
			
				for(int k=1;k<=dim;k++) {
					//row check
					if(k != j && board[i][k] == board[i][j] && board[i][j] == 1) {
						conflict++;
					}
					//col check
					if(k != i && board[k][j] == board[i][j] && board[i][j] == 1) {
						conflict++;
					}
				}
				//diagonal check
				//diagonal type 1
				for(int l=1;l<=dim;l++){
					int u=i+l;
					int v=j+l;
					if(u<=dim && u>=1 && v<=dim && v>=1) {
						if(board[i][j] == board[u][v] && board[i][j] == 1) conflict++;
					} 
					u=i-l;
					v=j-l;
					if(u<=dim && u>=1 && v<=dim && v>=1) {
						if(board[i][j] == board[u][v] && board[i][j] == 1) conflict++;
					}
					u=i-l;
					v=j+l;
					if(u<=dim && u>=1 && v<=dim && v>=1) {
						if(board[i][j] == board[u][v] && board[i][j] == 1) conflict++;
					}
					u=i+l;
					v=j-l;
					if(u<=dim && u>=1 && v<=dim && v>=1) {
						if(board[i][j] == board[u][v] && board[i][j] == 1) conflict++;
					}
				}
			}
		}
	}
	return conflict;
}

struct CMP_Priority{
	bool operator () (const Info &a, const Info &b) {
		if(a.conflict>b.conflict) return true;
		return false;
	}
};

priority_queue<Info,vector<Info>,CMP_Priority>PQ;

int a_search(Info st){
	int state = 0;
	PQ.push(st);
	while(PQ.empty() != true) {
		Info u = PQ.top();
		PQ.pop();
		for(int i=1;i<=dim;i++){
			for(int j=1;j<=dim;j++) {
				if(u.board[i][j] == 1) {
					Info temp;
					for(int m=1;m<=dim;m++){
						for(int n=1;n<=dim;n++){
							temp.board[m][n]=u.board[m][n];
						}
					}
					for(int k=0;k<=7;k++){
						int x = i+k;
						int y=j+k;
						if(x>=1 && x<=dim && u.board[x][y]==0){
							swap(temp.board[x][y],temp.board[i][j]);
							int conflict = min_conflict(temp.board);
							temp.conflict = conflict;
							if(M[temp] == 0) {
								state++;
								M[temp]=state;
								PQ.push(temp);
							}
							swap(temp.board[x][y],temp.board[i][j]);
						}
					}
				}
			}
		}
	}
}

int main(void){
	
}	
