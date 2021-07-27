#include <bits/stdc++.h>
using namespace std;
#define MAX 50


struct Node{
	int type; 
	char symbol; 
	set<int>first_pos;
	set<int>last_pos;
	bool nullable;
	/* definition type
	 * 1->symbol
	 * 2->(
	 * 3->)
	 * 4->.
	 * 5->|
	 * 6->*
	 * 7->+
	 * 8->normal
	 * */
};

struct Dfa_Node{
	set<int>S; 
};

struct CMP{
	bool operator()(const Dfa_Node &a, const Dfa_Node &b) const{
		if(a.S.size()<b.S.size()) return true;
		if(a.S.size()>b.S.size()) return false;
		set<int>::iterator it,it2;
		for(it=a.S.begin() , it2 = b.S.begin() ; it != a.S.end() ;it++, it2++) {
			if(*it<*it2) return true;
			if(*it>*it2) return false;
		}
		return false;
	}
};

set<int>follow_pos[MAX*10+1];
string input_string;
map<Dfa_Node,int,CMP>M;
map<int,Dfa_Node>M2;
int dfa_node_counter;
Dfa_Node initial_state,final_state;
int state_transition_table[MAX*10+1][MAX*10+1];
set<int>non_terminals;
char effective_characters[MAX*10+1];


int type_selector(char ch){
	if((ch>='a' && ch<='z') || (ch >='0' && ch<='9') || (ch == '#') || (ch == '$')) return 1; //input symbol
	if(ch == '(') return 2;
	if(ch == ')') return 3;
	if(ch == '.') return 4;
	if(ch == '|') return 5;
	if(ch == '*') return 6;
	if(ch == '+') return 7;
	return 8; 
}

vector<char> merge_vector(vector<char>V, int pos, char symbol) {
	vector<char>temp;
	for(int i=0;i<pos;i++) {
		temp.push_back(V[i]);
	}
	temp.push_back(symbol);
	for(int i=pos;i<V.size();i++) {
		temp.push_back(V[i]);
	}
	return temp; 
}

int set_concat(char a, char b){
	if((a == '.') | (a == '|')) return 0;
	if((b == '.') | (b == '|')) return 0; //have an operator between two symbol
	if(a == ')' && b == '*') return 0; //(a+b)*
	if(a == ')' && b == '+') return 0; //(a+b)+
	if(a == '(' && b == '(') return 0;
	if(a == ')' && b == ')') return 0;
	if(a == '*' && b == ')') return 0;
	if(a == '+' && b == ')') return 0;
	int one = type_selector(a);
	int two = type_selector(b);
	if(one == 2 && two == 1) return 0; // ( c ...)
	if(one == 1 && two == 3) return 0; // c )
	if(one == 1 && two == 6) return 0; //c *
	if(one == 1 && two == 7) return 0; //c +
	
	return 1; //need change 
	
}

vector<char> preprocess(string s){
	vector<char>V;
	for(int i=0;i<s.size();i++) {
		V.push_back(s[i]); 
	}
	while(true) {
		bool change=false;
		for(int i=0;i<V.size();i++) {
			if((i+1)<V.size()) {
				int a=V[i];
				int b=V[i+1];
				int v = set_concat(a,b);
				if(v == 1) {
					change=true;
					V = merge_vector(V,i+1,'.');
					break;
				}
				
			}
		}
		if(!change) break; 
	}
	/*for(int i=0;i<V.size();i++) {
		cout<<V[i]<<" ";
	}
	cout<<endl; */
	return V;
}

vector<char> input(){
	freopen("in14.txt","r",stdin);
	string s;
	getline(cin,s);
	s=s+'$';
	input_string = s;
	vector<char> V = preprocess(s);
	return V;
}

vector<Node> combine_vector(vector<Node>V, int first_copy_en, int last_copy_start, Node special){
	vector<Node>temp;
	for(int i=0;i<=first_copy_en;i++) {
		temp.push_back(V[i]);
	}
	temp.push_back(special);
	for(int i=last_copy_start; i<V.size();i++) {
		temp.push_back(V[i]);
	}
	return temp; 
}


void print_state(vector<Node>V){
	cout<<"printing " <<V.size()<< endl;
	for(int i=0;i<V.size();i++) {
		cout<<V[i].type<<" "<<V[i].symbol<<endl; 
	}
	//cout<<"done"<<endl;
	return;
}

set<int> set_return(set<int>S){
	set<int>temp;
	set<int>::iterator it;
	for(it = S.begin();it != S.end();it++) {
		temp.insert(*it);
	}
	return temp;
}

void calculate_follow(set<int>first, set<int>second){
	set<int>::iterator it,it2;
	for(it = first.begin(); it != first.end(); it++) {
		int value = *it; 
		for(it2 = second.begin(); it2 != second.end(); it2++) {
			follow_pos[value].insert(*it2);
		}
	}
}

void set_print(set<int>S){
	set<int>::iterator it;
	for(it = S.begin(); it != S.end() ;it++) {
		cout<<*it<<" ";
	}
	cout<<endl;
}

void print_table(){
	set<int>::iterator it;
	cout<<" ";
	for(it = non_terminals.begin(); it != non_terminals.end() ; it++) {
			char ch = *it;
			cout<<ch<<" ";
	}
	cout<<endl;
	for(int i=1;i<=dfa_node_counter;i++){
		cout<<i<<" ";
		for(it = non_terminals.begin(); it != non_terminals.end() ; it++) {
			char ch = *it;
			cout<<state_transition_table[i][*it]<<" ";
		}
		cout<<endl;
	}
}

void print_dfa_nodes(){
	for(int i=1;i<=dfa_node_counter;i++) {
		cout<<"node " << i<<" "<< endl;
		set<int>::iterator it;
		for(it = M2[i].S.begin(); it != M2[i].S.end() ; it++) {
			cout<<*it<<" ";
		}
		cout<<endl;
	}
}


void construct_dfa(int start, int end){
	queue<int>Q;
	int visit[MAX*10+1];
	memset(visit,0,sizeof(visit));
	visit[start]=1;
	Q.push(start);
	while(Q.empty() != true) {
		int u = Q.front();
		cout<<"u = " << u << endl;
		Q.pop();
		set<int>character_set;
		set<int>grouping[MAX*10+1];
		set<int>::iterator it,it2,it3;
		for(it = M2[u].S.begin() ; it != M2[u].S.end() ; it++) {
			int value = *it;
			char ch = effective_characters[value];
			cout<<"value " << value<<" "<<ch<<endl;
			character_set.insert(ch);
			grouping[ch].insert(value);
		}
		for(it=character_set.begin(); it != character_set.end(); it++) {
			int int_val = *it;
			set<int>temp;
			for(it2 = grouping[int_val].begin() ; it2 != grouping[int_val].end() ;it2++) {
				int value = *it2;
				for(it3 = follow_pos[value].begin(); it3 != follow_pos[value].end(); it3++) {
					temp.insert(*it3);
				}
			}
			Dfa_Node notun;
			notun.S.insert(temp.begin(),temp.end());
			if(M[notun] == 0) {
				dfa_node_counter++;
				M[notun]=dfa_node_counter;
				M2[dfa_node_counter]=notun;
				set_print(notun.S);
			}
			state_transition_table[u][int_val] = M[notun];
			if(visit[M[notun]]==0) {
				Q.push(M[notun]);
				visit[M[notun]]=1;
			}
			non_terminals.insert(int_val);
		}
	}
	print_dfa_nodes();
	print_table();
}

void print_follow(int counter){
	cout<<"printing follow " << endl;
	for(int i=1;i<=counter;i++) {
		set<int>:: iterator it;
		cout<<i<<" = ";
		for(it=follow_pos[i].begin(); it != follow_pos[i].end() ; it++) {
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	cout<<"follow print complete " << endl;
}

void algorithm(vector<char>V){
	int node_counter=0;
	vector<Node>states;
	int counter=0;
	for(int i=0;i<V.size();i++) {
		Node temp;
		cout<<"char = " << V[i]<<endl;
		temp.type = type_selector(V[i]);
		temp.symbol = V[i];
		if(V[i] == '#') {
			temp.nullable = true; 
		}
		else {
			temp.nullable = false;
			if(temp.type == 1) {
				counter++;
				effective_characters[counter] = V[i];
				temp.first_pos.insert(counter);
				temp.last_pos.insert(counter);
				//debug: cout<<"counter " << V[i]<<endl;
			}
		}
		states.push_back(temp); 
	}
	
	while(states.size() != 1) {
		bool change=false;
		//first reduce ( something ) 
		for(int i=0;i<states.size();i++) {
			if(states[i].type == 2) {
				if((i+2)<states.size()) {
					if(states[i+2].type == 3) {
						change=true;
						states = combine_vector(states,i-1,i+3,states[i+1]);
						break;
					}
				}
			}
		}
		if(change) continue; 
		//Now need to remove c * 
		for(int i=0;i<states.size();i++) {
			if(states[i].type == 6) {
				if((i-1)>=0) {
					if((states[i-1].type == 1) || (states[i-1].type == 8)){
						//will be pushed as simple node
						change = true;
						Node temp;
						temp.type = 8; 
						temp.nullable = true;
						//first pos , last_pos 
						temp.first_pos = set_return(states[i-1].first_pos);
						temp.last_pos = set_return(states[i-1].last_pos); 
						//calculation of follow pos 
						calculate_follow(states[i-1].last_pos,states[i-1].first_pos);
						states = combine_vector(states,i-2,i+1,temp);
						break;
					}
				}
			}
		}
		if(change) continue; 
		//Now need to remove c +
		for(int i=0;i<states.size();i++) {
			if(states[i].type == 7) {
				if((i-1)>=0) {
					if((states[i-1].type == 1) || (states[i-1].type == 8)){
						//will be pushed as simple node
						change = true;
						Node temp;
						temp.type = 8; 
						temp.nullable = false;
						//first pos , last_pos 
						temp.first_pos = set_return(states[i-1].first_pos);
						temp.last_pos = set_return(states[i-1].last_pos); 
						//calculation of follow pos 
						calculate_follow(states[i-1].last_pos,states[i-1].first_pos);
						states = combine_vector(states,i-2,i+1,temp);
						break;
					}
				}
			}
		}
		if(change) continue;
		//now need to remove cat a.b
		for(int i=0;i<states.size();i++) {
			if(states[i].type == 4) {
				if((i-1)>=0 && (i+1)<states.size()) {
					int one = states[i-1].type;
					int two = states[i+1].type;
					if((one==1 || one == 8) && (two == 1 || two == 8)) {
						change = true;
						Node temp;
						temp.type = 8;
						if(states[i-1].nullable == true && states[i+1].nullable == true) {
							temp.nullable = true;
						}
						else temp.nullable = false;
						//calculating first pos
						if(states[i-1].nullable == true) {
							temp.first_pos.insert(states[i-1].first_pos.begin(),states[i-1].first_pos.end());
							temp.first_pos.insert(states[i+1].first_pos.begin(),states[i+1].first_pos.end());
						}
						else {
							temp.first_pos.insert(states[i-1].first_pos.begin(),states[i-1].first_pos.end());
						}
						//calculating last pos
						if(states[i+1].nullable == true) {
							temp.last_pos.insert(states[i-1].last_pos.begin(),states[i-1].last_pos.end());
							temp.last_pos.insert(states[i+1].last_pos.begin(),states[i+1].last_pos.end());
						}
						else {
							temp.last_pos.insert(states[i+1].last_pos.begin(),states[i+1].last_pos.end());
						}
						//calculating follow set
						calculate_follow(states[i-1].last_pos,states[i+1].first_pos);
						states = combine_vector(states,i-2,i+2,temp);
						break;
						
					}
				}
			}
		}
		if(change) continue;
		//now for or node a | b
		for(int i=0;i<states.size();i++) {
			if(states[i].type == 5) {
				if((i-1)>=0 && (i+1)<states.size()) {
					int one = states[i-1].type;
					int two = states[i+1].type;
					if((one==1 || one == 8) && (two == 1 || two == 8)) {
						change = true;
						Node temp;
						temp.type = 8;
						if(states[i-1].nullable == true || states[i+1].nullable == true) {
							temp.nullable = true;
						}
						else temp.nullable = false;
						//calculating first pos
						temp.first_pos.insert(states[i-1].first_pos.begin(),states[i-1].first_pos.end());
						temp.first_pos.insert(states[i+1].first_pos.begin(),states[i+1].first_pos.end());
						//calculating last pos
						temp.last_pos.insert(states[i-1].last_pos.begin(),states[i-1].last_pos.end());
						temp.last_pos.insert(states[i+1].last_pos.begin(),states[i+1].last_pos.end());
						states = combine_vector(states,i-2,i+2,temp);
						break;
					}
				}
			}
		}
		if(change) continue;	
	}
	
	//printing follow
	print_follow(counter);
	
	set_print(states[0].first_pos); 
	cout<<"first done " << endl;
	initial_state.S.insert(states[0].first_pos.begin(),states[0].first_pos.end());
	final_state.S.insert(states[0].last_pos.begin(),states[0].last_pos.end());
	dfa_node_counter = 0;
	if(M[initial_state] == 0) {
		dfa_node_counter++;
		M[initial_state] = dfa_node_counter;
		M2[dfa_node_counter]=initial_state;
	}
	if(M[final_state] == 0) {
		dfa_node_counter++;
		M[final_state] = dfa_node_counter;
		M2[dfa_node_counter]=final_state;
	}
	construct_dfa(M[initial_state],M[final_state]);
}

void initialize(){
	memset(effective_characters,'0',sizeof(effective_characters));
}

int main(void){
	vector<char>V;
	V = input();
	algorithm(V); 
}
