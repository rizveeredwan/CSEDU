#include <bits/stdc++.h>
using namespace std;
#define MAX 3

//direction array
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

int row,col;
int arr[MAX+1][MAX+1];
int last[MAX+1][MAX+1];
int given[MAX+1][MAX+1];
int parent[100000];
int counter;
int goal;

bool reached;

struct tic_tac_toe{
	int state[MAX+1][MAX+1];
	int id;
	int f_n,g_n; 
};

struct compare{
	bool operator()(const tic_tac_toe &a, const tic_tac_toe &b) {
		if(a.state[1][1]<b.state[1][1]) return true;
		else if(a.state[1][1]>b.state[1][1]) return false;
		else {
			if(a.state[1][2]<b.state[1][2]) return true;
			else if(a.state[1][2] > b.state[1][2]) return false;
			else{
				if(a.state[1][3]<b.state[1][3]) return true;
				else if(a.state[1][3] > b.state[1][3]) return false;
				else{
					if(a.state[2][1]<b.state[2][1]) return true;
					else if(a.state[2][1]>b.state[2][1]) return false;
					else{
						if(a.state[2][2]<b.state[2][2]) return true;
						else if(a.state[2][2]>b.state[2][2]) return false;
						else{
							if(a.state[2][3]<b.state[2][3]) return true;
							else if(a.state[2][3]>b.state[2][3]) return false;
							else{
								if(a.state[3][1]<b.state[3][1]) return true;
								else if(a.state[3][1]>b.state[3][1]) return false;
								else{
									if(a.state[3][2]<b.state[3][2]) return true;
									else if(a.state[3][2]>b.state[3][2]) return false;
									else{
										if(a.state[3][3]<b.state[3][3]) return true;
										else if(a.state[3][3]>b.state[3][3]) return false;
										else {
											return false;
										}
									}
								}
								
							}
						}
					}
				}
			}
		}
	}
};

struct compare_two{
	bool operator ()(const tic_tac_toe &a,const tic_tac_toe &b) {
		if((a.f_n+a.g_n)>(b.f_n+b.g_n)) return true;
		else return false;
	}
};

struct jora{
	int x,y;
}save[11];

int calculate_f(int a[MAX+1][MAX+1]){
	int sum=0;
	for(int i=1;i<=row;i++){
		for(int j=1;j<=col;j++) {
			int v=a[i][j];
			sum=sum+abs(i-save[v].x)+abs(j-save[v].y);
		}
	}
	return sum;
}

bool valid(int x,int y){
	if(x>=1 && x<=row && y>=1 && y<=col) return true;
	else return false;
}

map<tic_tac_toe,int,compare>M; 
priority_queue<tic_tac_toe,vector<tic_tac_toe>,compare_two>PQ;

vector<tic_tac_toe>States; 


//function to solve tic tac toe
int solve_tic_tac_toe(){
	reached=false;
	int min_move=0;
	//printf("size = %d\n",PQ.size());
	while(PQ.empty() != true) {
		tic_tac_toe u=PQ.top();
		PQ.pop();
		int manhattan[12]={0};
		int cum_sum=0;
		if(u.f_n == 0) break; //ending state 
		
		tic_tac_toe temp;
		for(int i=1;i<=row;i++){
			for(int j=1;j<=col;j++) {
				int v=u.state[i][j];
				manhattan[v] = abs(save[v].x-i)+abs(save[v].y-j);
				cum_sum += manhattan[v];
				temp.state[i][j]=u.state[i][j];
			}
		}
		int variable=0;
		for(int i=1;i<=row;i++){
			for(int j=1;j<=col;j++) {
				int v=u.state[i][j];
				for(int k=0;k<=3;k++){
					int x=i+dx[k];
					int y=j+dy[k];
					bool ok=valid(x,y);
					if(ok && u.state[x][y]==9) {
						//swap performed 
						temp.state[i][j]=u.state[x][y]; 
						temp.state[x][y]=u.state[i][j]; 
						temp.g_n=u.g_n+1;
						temp.f_n=cum_sum - manhattan[v]-manhattan[9] + abs(i-save[temp.state[i][j]].x)+abs(j-save[temp.state[i][j]].y);
						temp.f_n += abs(x-save[temp.state[x][y]].x)+abs(y-save[temp.state[x][y]].y);
						
						if(M[temp]==0){
							//not visited 
							counter++;
							M[temp]=counter;
							States.push_back(temp); //state saved
							parent[counter]=u.id; 
							temp.id=counter;  
							PQ.push(temp); 
							variable++;
							
						}
						
						if(M[temp]==goal){
							//final destination reached 
							parent[goal]=u.id;
							reached=true;
							variable++;
							return (u.g_n+1);
						}
						//need to back
						temp.state[i][j]=u.state[i][j];
						temp.state[x][y]=u.state[x][y];
					}
				}
			}
		}
		/*if(variable==0){
		 	cout<<"blocking state"<<endl;
		 	for(int i=1;i<=row;i++){
				for(int j=1;j<=col;j++){
					if(u.state[i][j] == 9) cout<<" "<<" ";
					else cout<<u.state[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}*/
	}
	return min_move;
}


void path_print(int number){
	vector<tic_tac_toe>answer;
	while(1){
		tic_tac_toe temp;
		temp=States[number];
		answer.push_back(temp);
		number=parent[number];
		if(number==-1) break;
	}
	reverse(answer.begin(),answer.end());
	for(int i=0;i<answer.size();i++){
		tic_tac_toe temp=answer[i];
		cout<<"State " <<i<<endl;
		for(int j=1;j<=row;j++){
			for(int k=1;k<=col;k++){
				if(temp.state[j][k] == 9) cout<<" "<<" ";
				else cout<< " ( " << temp.state[j][k]<<" and heuristic " << temp.f_n+temp.g_n<<" ) " << " ";
			}
			cout<<endl;
		}
	}
	return;
}

int main(void){
	freopen("Tic_Tac_Toe_2.txt","r",stdin);
	scanf("%d %d",&row,&col);
	//initial configuration
	for(int i=1;i<=row;i++){
		for(int j=1;j<=col;j++) {
			scanf("%d",&arr[i][j]); //9 means empty space
			save[arr[i][j]].x=i;
			save[arr[i][j]].y=j;
		}
	}
	//final configuration
	for(int i=1;i<=row;i++) {
		for(int j=1;j<=col;j++) {
			scanf("%d",&given[i][j]);
		}
	}
	
	//this will be pushed in priority_queue as src 
	tic_tac_toe temp;
	for(int i=1;i<=row;i++){
		for(int j=1;j<=col;j++) {
			temp.state[i][j]=given[i][j];
		}
	}
	counter=0;
	tic_tac_toe start;
	States.push_back(start);
	//initial 
	if(M[temp] == 0) {
		counter++;
		M[temp]=counter; 
		temp.g_n=0;
		temp.f_n=calculate_f(temp.state);
		temp.id=M[temp];
		PQ.push(temp); 
		parent[1] = -1;
		
		States.push_back(temp);
	}
	
	for(int i=1;i<=row;i++){
		for(int j=1;j<=col;j++) {
			temp.state[i][j]=arr[i][j];
		}
	}
	//final 
	if(M[temp] == 0) {
		counter++;
		M[temp]=counter; 
		States.push_back(temp);
		goal=counter;	
		for(int i=1;i<=row;i++){
			for(int j=1;j<=col;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
	} 
	int min_move = solve_tic_tac_toe();
	if(reached){
		printf("min_move = %d\n",min_move);
		//path_print(goal);
	}
	else{
		cout<<"Not reachable"<<endl;
	}
	return 0; 
	
}
