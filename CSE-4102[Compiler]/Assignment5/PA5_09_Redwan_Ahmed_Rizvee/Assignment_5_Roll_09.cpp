#include <bits/stdc++.h>
using namespace std;

#define MAX 200

int non_terminal,terminal;

vector<int>non_terminal_nodes,terminal_nodes;
vector<char>char_non_terminal_nodes,char_terminal_nodes;
map<int,int>inserted;

struct Right_Side{
	vector<int>V; 
	vector<char>V_char;
};

vector<Right_Side>production[MAX+1]; 

vector<int>first[MAX+1];
vector<char>first_char[MAX+1];
bool cycle_in_first;
int node_color[MAX+1];

struct Position{
	int node; //left side 
	int rule; //rule number 
	int pos;  //which pos 
};

vector<Position>Place[MAX+1]; 
vector<int>temp_follow; 
vector<int>follow[MAX+1];

int parser_table[MAX+25][MAX+25];



void input(){	
	//freopen("in.txt","r",stdin);
	//freopen("in2.txt","r",stdin);
	//freopen("in3.txt","r",stdin);
	//freopen("in4.txt","r",stdin);
	//freopen("in5.txt","r",stdin);
	freopen("in5.txt","r",stdin);
	string s;
	while(getline(cin,s)) {
		if(s.size()==0) {
			break;
		}
		
		int len = s.size();
		/*Non terminal*/
		char ch = s[0];
		int int_val = ch;
		
		
		if(inserted[int_val] == 0) {
			/*this node is not inserted */
			non_terminal_nodes.push_back(int_val);
			char_non_terminal_nodes.push_back(ch); 
			inserted[int_val] = 1;
		}
		
		/*Right hand side*/
		Right_Side right_side;
		
		for(int i=3;i<len;i++){
			ch = s[i];
			int int_val = ch;
			
			if(ch>='A' && ch <='Z') {
				if(inserted[int_val] == 0) {
					/*this node is not inserted */
					non_terminal_nodes.push_back(int_val);
					char_non_terminal_nodes.push_back(ch); 
					inserted[int_val] = 1;
				} 
			}
			else {
				if(inserted[int_val] == 0) {
					/*this node is not inserted */
					terminal_nodes.push_back(int_val);
					char_terminal_nodes.push_back(ch); 
					inserted[int_val] = 1;
				}
			}
			
			right_side.V.push_back(int_val);
			right_side.V_char.push_back(ch); 
		}
		
		int_val = s[0];
		production[int_val].push_back(right_side); 
	}
}

/*Function to calculate first*/
void find_first(int working_node){
	
	if(first[working_node].size() != 0) return; 
	
	if(node_color[working_node] == 0) {
		node_color[working_node] = 1;
	}
	else {
		cycle_in_first = true;
		return; 
	}
	int size_1 = production[working_node].size();
	vector<int>result; 
	for(int i=0;i<size_1;i++){
		int base = 0;
		bool epsilon = false;
		while(true) {
			int size_2 = production[working_node][i].V.size();
			cout<<base<<endl;
			if(base>=size_2) {
				/*all done */
				if(epsilon) {
					char ch = '#';
					int ep = ch;
					result.push_back(ep);
				}
				break;
			}
			else {
				epsilon = false;
			}
			
			char ch = production[working_node][i].V_char[base];
			int int_val = ch;
			
			if(ch>='A' && ch<='Z') {
				find_first(int_val);
				char ch = '#';
				int ep = ch;
				for(int j=0;j<first[int_val].size();j++){
					if(first[int_val][j] != ep) {
						//normal terminal
						result.push_back(first[int_val][j]);
					}
					else {
						epsilon=true;
					}
				}
				if(!epsilon) {
					break; 
				}
				base++;
			}
			else {
				result.push_back(int_val);
				break;
			}
			
		}
	}
	
	int temp[500];
	memset(temp,0,sizeof(temp));
	int sz = result.size();
	for(int i=0;i<sz;i++){
		if(temp[result[i]]==0) {
			temp[result[i]] = 1;
			char ch = result[i];
			first[working_node].push_back(result[i]);
			first_char[working_node].push_back(ch);
		}
	}
	return; 
}


void print_rules(){
	int size = non_terminal_nodes.size();
	for(int i=0;i<size;i++){
		int val = non_terminal_nodes[i];
		cout<<" left side " << char_non_terminal_nodes[i]<< endl;
		int sec_size = production[val].size();
		for(int j=0;j<sec_size;j++){
			int th_size = production[val][j].V.size();
			for(int k=0;k<th_size;k++){
				cout<<production[val][j].V_char[k];
			}
			cout<<endl;
		}
	}
}

void calculate_first(){
	int size = non_terminal_nodes.size();
	for(int i=0;i<size;i++){
		memset(node_color,0,sizeof(node_color));
		find_first(non_terminal_nodes[i]);
		if(cycle_in_first) {
			cout<<"grammer is not free from left recursion"<<endl;
			char ch = non_terminal_nodes[i];
			cout<<"left recursion exists in production of " << ch << endl;
			exit(0);
		}
	}
	
	/*Left factored or not*/
	for(int i=0;i<non_terminal_nodes.size();i++) {
		sort(first[non_terminal_nodes[i]].begin(),first[non_terminal_nodes[i]].end());
		bool repeat=false;
		for(int j=1;j<first[non_terminal_nodes[i]].size();j++) {
			if(first[non_terminal_nodes[i]][j] == first[non_terminal_nodes[i]][j-1]) {
				repeat=true;
				break;
			}
		}
		
	}
	
	
	cout<<"First Generated " << endl;
	for(int i=0;i<size;i++){
		int size_2 =first_char[non_terminal_nodes[i]].size();
		cout<<char_non_terminal_nodes[i]<<": ";
		for(int j=0;j<size_2;j++){
			cout<<first_char[non_terminal_nodes[i]][j];
		}
		cout<<endl;
	}
}

void find_positions(int node){
	int sz = non_terminal_nodes.size();
	for(int i=0;i<sz;i++){
		int var = non_terminal_nodes[i];
		int sz_2 = production[var].size();
		for(int j=0;j<sz_2;j++) {
			int sz_3 = production[var][j].V.size();
			for(int k=0;k<sz_3;k++){
				if(production[var][j].V[k] == node) {
					Position p;
					p.node = var;
					p.rule = j;
					p.pos = k; 
					Place[node].push_back(p);
				}
			}
		}
	}
}

void find_follow(int node){
	int sz = Place[node].size();
	for(int i=0;i<sz;i++) {
		int left_side = Place[node][i].node;
		int rule = Place[node][i].rule;
		int pos = Place[node][i].pos;
		int sz_2 = production[left_side][rule].V.size();
		pos++;
		while(true) {
			if(pos>=sz_2) {
					//need to add the follow of left side
					for(int j=0;j<follow[left_side].size();j++) {
						bool exist=false;
						for(int k=0;k<temp_follow.size();k++) {
							if(temp_follow[k] == follow[left_side][j]) {
								exist=true;
								break;
							}
						}
						if(!exist) {
							temp_follow.push_back(follow[left_side][j]);
						}
					}
					break;
			}
			int int_val = production[left_side][rule].V[pos];
			if(int_val >=65 && int_val <= 90) {
				vector<int>temp_first;
				vector<int>ase_na_nai;
				int sz_3 = first[int_val].size();
				bool epsilon = false;
				int ep = '#';
				for(int j=0;j<sz_3;j++) {
					/*epsilon: Need to go forward */
					if(first[int_val][j] == ep) {
						epsilon = true;
					}
					else {
						temp_first.push_back(first[int_val][j]);
						ase_na_nai.push_back(0); //because no one is pushed 
					}
				}
				/*seeing which already exists */
				for(int j=0;j<temp_first.size();j++) {
					bool exist = false;
					for(int k=0;k<temp_follow.size();k++) {
						if(temp_follow[k] == temp_first[j]) {
							exist = true;
							break;
						}
					}
					if(!exist) {
						ase_na_nai[j] = 1;
					}
				}
				/*New character pushed*/
				for(int j=0;j<temp_first.size();j++) {
					if(ase_na_nai[j]==1) {
						temp_follow.push_back(temp_first[j]);
					}
				}
				
				/*if epsilon check next*/
				if(epsilon) {
					pos++;
					continue;
				}	
				else {
					break;
				}
				
				
			}
			else {
				//terminal
				temp_follow.push_back(int_val);
				break; 
			}
		}
		
	}
	return;
}

void calculate_follow(){
	int sz = non_terminal_nodes.size();
	cycle_in_first = false;
	/*Finding where the nodes are in the right side*/
	for(int i=0;i<sz;i++){
		find_positions(non_terminal_nodes[i]);
	}
	
	/*$ pushing*/
	follow[non_terminal_nodes[0]].push_back('$');
	terminal_nodes.push_back('$');
	char_terminal_nodes.push_back('$');
	
	int move = 0;
	while(true) {
		int cnt=0;
		move++;
		for(int i=0;i<non_terminal_nodes.size();i++) {
			temp_follow.clear();
			find_follow(non_terminal_nodes[i]);
			bool added = false;
			for(int j=0;j<temp_follow.size();j++) {
				bool found=false;
				for(int k=0;k<follow[non_terminal_nodes[i]].size();k++) {
					if(follow[non_terminal_nodes[i]][k] == temp_follow[j]) {
						found=true;
						break;
					}
				}
				if(!found) {
					//need to insert
					follow[non_terminal_nodes[i]].push_back(temp_follow[j]);
					added=true;
				}
			}
			if(added) {
				cnt++;
			}
		}
		if(cnt==0) {
			cout<<"finding follow is completed"<<endl;
			break;
		}
	}
	

	for(int i=0;i<non_terminal_nodes.size();i++) {
		char ch = non_terminal_nodes[i];
		cout<<"ch = " << ch << endl;
		for(int j=0;j<follow[non_terminal_nodes[i]].size();j++) {
			ch=follow[non_terminal_nodes[i]][j];
			cout<<ch;
		}
		cout<<endl;
	}
}


void parser(){
	memset(parser_table,-1,sizeof(parser_table));
	for(int i=0;i<non_terminal_nodes.size();i++) {
		for(int j=0;j<production[non_terminal_nodes[i]].size();j++){
			int base = 0;
			bool epsilon=false;
			while(true){
				
				if(base >= production[non_terminal_nodes[i]][j].V.size()) {
					//so need to check follow 
					for(int k=0;k<follow[non_terminal_nodes[i]].size();k++) {
						if(parser_table[non_terminal_nodes[i]][follow[non_terminal_nodes[i]][k]] == -1) {
							//okay 
							parser_table[non_terminal_nodes[i]][follow[non_terminal_nodes[i]][k]] = j;
						}
						else {
								cout<<"Grammer is not left factored " << endl;
								cout<<" Rules are Conflicting " << endl;
								char ch = non_terminal_nodes[i];
								cout<<ch<<"->";
								int rule = parser_table[non_terminal_nodes[i]][follow[non_terminal_nodes[i]][k]];
								for(int l=0;l<production[non_terminal_nodes[i]][rule].V.size();l++) {
									ch = production[non_terminal_nodes[i]][rule].V[l];
									cout<<ch;
								}
								cout<<endl;
								cout<<"->";
								for(int l=0;l<production[non_terminal_nodes[i]][j].V.size();l++) {
									ch = production[non_terminal_nodes[i]][j].V[l];
									cout<<ch;
								}
								cout<<endl;
								exit(0);
						}
					}
					break;
				}
				
				int int_val = production[non_terminal_nodes[i]][j].V[base];
				if(int_val>='A' && int_val <='Z') {
					epsilon = false;
					for(int k=0;k<first[int_val].size();k++) {
						int ep = '#';
						if(first[int_val][k] == ep) {
							//epsilon found need to check next 
							epsilon = true;
						}
						else {
							//bosaye dibo just
							if(parser_table[non_terminal_nodes[i]][first[int_val][k]] == -1) {
								//no conflit
								parser_table[non_terminal_nodes[i]][first[int_val][k]] = j;
							}
							else {
								cout<<"Grammer is not left factored " << endl;
								cout<<" Rules are Conflicting " << endl;
								char ch = non_terminal_nodes[i];
								cout<<ch<<"->";
								int rule = parser_table[non_terminal_nodes[i]][first[int_val][k]];
								for(int l=0;l<production[non_terminal_nodes[i]][rule].V.size();l++) {
									ch = production[non_terminal_nodes[i]][rule].V[l];
									cout<<ch;
								}
								cout<<endl;
								cout<<"->";
								for(int l=0;l<production[non_terminal_nodes[i]][j].V.size();l++) {
									ch = production[non_terminal_nodes[i]][j].V[l];
									cout<<ch;
								}
								cout<<endl;
								exit(0);
							}	
						}
					}
					if(epsilon) {
						base++;
						continue; //need to check forward
					}
					else {
						break;
					}
				}
				else {
					int ep = '#';
					if(int_val != ep) {
						//normal terminal
						if(parser_table[non_terminal_nodes[i]][int_val] == -1) {
							//no error 
							parser_table[non_terminal_nodes[i]][int_val] = j;
							break;
						}
						else {
							//Error found 
							//Left factored error
							cout<<"Grammer is not left factored " << endl;
							cout<<" Rules are Conflicting " << endl;
							char ch = non_terminal_nodes[i];
							cout<<ch<<"->";
							int rule = parser_table[non_terminal_nodes[i]][int_val];
							for(int k=0;k<production[non_terminal_nodes[i]][rule].V.size();k++) {
									ch = production[non_terminal_nodes[i]][rule].V[k];
									cout<<ch;
							}
							cout<<endl;
							cout<<"->";
							for(int k=0;k<production[non_terminal_nodes[i]][j].V.size();k++) {
								ch = production[non_terminal_nodes[i]][j].V[k];
								cout<<ch;
							}
							cout<<endl;
							exit(0);
						}
					}
					else {
						//A-># rules so will be used in follow of A
						for(int k=0;k<follow[non_terminal_nodes[i]].size();k++) {
							if(parser_table[non_terminal_nodes[i]][follow[non_terminal_nodes[i]][k]] == -1) {
									//no conflit
									parser_table[non_terminal_nodes[i]][follow[non_terminal_nodes[i]][k]]=j;
							}
							else {
								//Conflit 
								cout<<"Grammer is not left factored " << endl;
								cout<<" Rules are Conflicting " << endl;
								char ch = non_terminal_nodes[i];
								cout<<ch<<"->";
								int rule = parser_table[non_terminal_nodes[i]][follow[non_terminal_nodes[i]][k]];
								for(int l=0;l<production[non_terminal_nodes[i]][rule].V.size();l++) {
									ch = production[non_terminal_nodes[i]][rule].V[l];
									cout<<ch;
								}
								cout<<endl;
								cout<<"->#";
								exit(0);
							}
						}
						break;
					}
				}
			}
		}
	}
}


void print_parser_table(){
	for(int i=0;i<non_terminal_nodes.size();i++) {
		char ch = non_terminal_nodes[i];
		cout<<ch<<":"<<endl;
		for(int j=0;j<terminal_nodes.size();j++) {
			char ch2 = terminal_nodes[j];
			if(parser_table[non_terminal_nodes[i]][terminal_nodes[j]] != -1) {
				cout<<"terminal here " << ch2<<":"<<endl;
				cout<<"rule number " << parser_table[non_terminal_nodes[i]][terminal_nodes[j]]<<endl;
			}
		}
	}
}

void string_parse(string s){
	
	stack<int>S;
	S.push('$');
	S.push(non_terminal_nodes[0]);
	
	for(int i=0;i<s.size();i++) {
		int top = S.top();
		S.pop();
		if(top>='A' && top <='Z') {
			//non terminal 
			int ch = s[i];
			if(parser_table[top][ch] == -1) {
				cout<<"This string doesn't belong to this grammer" << endl;
				cout<<"Black entry detected"<<endl;
				exit(0);
			}
			else {
				int rule = parser_table[top][ch];
				vector<int>temp;
				char ch = top;
				cout<<"rule used " << ch<<"->";
				for(int j=0;j<production[top][rule].V.size();j++) {
					ch = production[top][rule].V[j];
					cout<<ch;
					temp.push_back(production[top][rule].V[j]);
				}
				reverse(temp.begin(),temp.end());
				for(int j=0;j<temp.size();j++) {
					int ep = '#';
					if(ep != temp[j]) {
						S.push(temp[j]);
					}
				}
				i--;
				cout<<endl;
			}
			
		}
		else {
			//terminal
			int int_val = s[i];
			if(s[i] == top) {
				continue;
			}
			else {
				cout<<"Error exists in grammer"<<endl;
				exit(0);
			}
		}
	}
}

int main(void){
	input();
	calculate_first();
	calculate_follow();
	parser();
	
	string s;
	cin>>s;
	s=s+'$';
	string_parse(s);
	return 0;
}
