#include <bits/stdc++.h>
using namespace std;
#define MAX 4
#define BEST_MOVE 10
#define INF 10000000

char board[MAX+1][MAX+1];

int row,col;
struct MOVE{
	int x,y;
};

MOVE pc;

void input(){
	//freopen("in.txt","r",stdin);
	scanf("%d %d",&row,&col);
	char ch = getchar();
	for(int i=0;i<row;i++) {
		string s;
		getline(cin,s);
		//cout<<s<<endl;
		for(int j=0;j<s.size();j++) {
			board[i][j]=s[j];
		}
	}
}

int calculate_board(char temp[MAX+1][MAX+1]){
	//cout<<"board"<<endl;
	/*for(int i=0;i<=2;i++) {
		for(int j=0;j<=2;j++) {
			cout<<temp[i][j];
		}
		cout<<endl;
	}*/
	for(int i=0;i<=2;i++){
			if(temp[i][0] == temp[i][1] && temp[i][1] == temp[i][2]) {
					//cout<<"row milse"<<endl;
					//same row 
					if(temp[i][0] == 'X') return 1; // max wins 
					if(temp[i][0] == 'O') return -1; //min wins
			}
			if(temp[0][i] == temp[1][i] && temp[1][i] == temp[2][i]) {
					//cout<<"column milse"<<endl;
					//same row 
					if(temp[0][i] == 'X') return 1; // max wins 
					if(temp[0][i] == 'O') return -1; //min wins
			}
		}
		//diagonal moves 
		if(temp[0][0] == temp[1][1] && temp[1][1] == temp[2][2]) {
			//cout<<"shoja diagonal milse"<<endl;
			if(temp[0][0] == 'X') return 1; // max wins 
			if(temp[0][0] == 'O')return -1; //min wins
		}
		if(temp[0][2] == temp[1][1] && temp[1][1] == temp[2][0]) {
			//cout<<"ulta diagonal milse"<<endl;
			if(temp[0][2] == 'X') return 1; // max wins 
			if(temp[0][2] == 'O') return -1; //min wins
		}
		return 0;
}


void print_board(char temp[MAX+1][MAX+1]){
	cout<<"present board"<<endl;
	for(int i=0;i<row;i++) {
		for(int j=0;j<col;j++) {
			cout<<temp[i][j];
		}
		cout<<endl;
	}
	return;
}

int minimax_with_alpha_beta_prunning(char temp[MAX+1][MAX+1], int num_player, int alpha, int beta, int depth){
	//print_board(temp);
	int result = calculate_board(temp);
	if(result == 1 || result == -1) {
		 //cout<<"one completed result"<<endl;
		 //if(result==1) cout<<"First Player Wins"<<endl;
		 //else cout<<"Second Player Wins"<<endl;
		 return result;
	}
	else {
		bool all_done = true;
		for(int i=0;i<row;i++) {
			for(int j=0;j<col;j++) {
				if(temp[i][j] == '_') {
					all_done = false;
					break;
				}
			}
			if(!all_done) break;
		}
		if(all_done) return result;
	}
	//cout<<"ase"<<endl;
	if(num_player == 1) {
		//max_player
		int best_value = -INF;
		for(int i=0;i<row;i++) {
			for(int j=0;j<col;j++) {
				if(temp[i][j] == '_') {
					//empty 
					temp[i][j] = 'X'; 
					int value = minimax_with_alpha_beta_prunning(temp,2,alpha,beta,depth+1);
					temp[i][j] = '_';
					best_value = max(best_value,value);
					alpha = max(alpha,best_value);
					if(alpha>=beta) {
						return best_value;
					}
				}
			}
		}
		return best_value;
	}
	else {
		int best_value = INF;
		for(int i=0;i<row;i++) {
			for(int j=0;j<col;j++) {
				if(temp[i][j] == '_') {
					//empty 
					temp[i][j] = 'O'; 
					int value = minimax_with_alpha_beta_prunning(temp,1,alpha,beta,depth+1);
					temp[i][j] = '_';
					best_value = min(best_value,value);
					beta = min(beta,best_value);
					if(alpha>=beta) {
						return best_value;
					}
				}
			}
		}
		return best_value;
	}
	
}

int count_empty(char board[MAX+1][MAX+1]){
	int count=0;
	for(int i=0;i<row;i++) {
		for(int j=0;j<col;j++) {
			if(board[i][j] == '_') count++;
		}
	}
	return count;
}

void game_play(){
	
	
	
	while(true) {
		int answer = 0;
		int res = calculate_board(board);
		int count;
		if(res == 1) {
			cout<<"First player won"<<endl;
			print_board(board);
			break;
		}
		if(res == -1) {
			cout<<"PC WON"<<endl;
			print_board(board);
			break;
		}
		for(int i=0;i<row;i++) {
			for(int j=0;j<col;j++) {
				if(board[i][j]=='_') {
					board[i][j]='X';
					int value = minimax_with_alpha_beta_prunning(board,2,-INF,INF,0);
					board[i][j] ='_';
					if(answer<value) {
						pc.x=i;
						pc.y=j;
						answer=value;
					}
	
				}
			}
		}
		count = count_empty(board);
		if(count == 0) {
			int v= calculate_board(board);
			if(v==1) {
				cout<<"You won"<<endl;
			}
			else if(v== -1) {
				cout<<"PC WIN"<<endl;
			}
			else {
				cout<<"Draw"<<endl;
			}
			break;
		}
		if(answer == 1) {
			cout<<"If you give move in this " << pc.x<<" "<<pc.y<<" there is a chance of win"<<endl;
			cout<<"do you want to give 1 For Yes 2 For No give in put then" << endl;
			int in;
			cin>>in;
			if(in==1) {
				cout<<"so you chose computer's input you have a good chance of winning " << endl;
				board[pc.x][pc.y]='X';
			}
			else {
				cout<<"so best of luck to your personal choice"<<endl;
				int x,y;
				cout<<"Give row column "<< endl;
				cin>>x;
				cin>>y;
				board[x][y]='X';
			}
			count = count_empty(board);
			if(count != 0) {
				cout<<"So there is empty space PC will give move"<<endl;
				while(true) {
					int r=rand()%3;
					int c=rand()%3;
					if(board[r][c] =='_') {
						cout<<"PC Is giving move in " <<r<<" "<<c<<endl;
						board[r][c]='O';
						break;
					}
				}
			}
		}
		else if(answer == -1) {
			cout<<"If both play optimally you don't have high hopes of winning"<<endl;
			cout<<"please give your input row column"<<endl;
			int x,y;
			cout<<"Give row column "<< endl;
			cin>>x;
			cin>>y;
			board[x][y]='X';
			count = count_empty(board);
			if(count != 0) {
				cout<<"So there is empty space PC will give move"<<endl;
				while(true) {
					int r=rand()%3;
					int c=rand()%3;
					if(board[r][c] =='_') {
						cout<<"PC Is giving move in " <<r<<" "<<c<<endl;
						board[r][c]='O';
						break;
					}
				}
			}
		}
		else {
			cout<<"there is a high chance of draw"<<endl;
			cout<<"please give your input row column"<<endl;
			int x,y;
			cout<<"Give row column "<< endl;
			cin>>x;
			cin>>y;
			board[x][y]='X';
			count = count_empty(board);
			if(count != 0) {
				cout<<"So there is empty space PC will give move"<<endl;
				while(true) {
					int r=rand()%3;
					int c=rand()%3;
					if(board[r][c] =='_') {
						cout<<"PC Is giving move in " <<r<<" "<<c<<endl;
						board[r][c]='O';
						break;
					}
				}
			}
		}
	
	}
}


int main(void) {
	input();
	game_play();
}
