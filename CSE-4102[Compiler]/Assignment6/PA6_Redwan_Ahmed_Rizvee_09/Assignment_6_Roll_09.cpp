#include <bits/stdc++.h>
using namespace std;

#define MAX 700

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



int parser_table[MAX+25][MAX+25];
int type_of_operation[MAX*2+25][MAX*2+25];/* 1 For reduce 2 For shift */


/*To take input as normal rule */
vector<char>given_rules[MAX*2+1];
int rule_count;/*Will start from 1*/
bool epsilon_rules[MAX*2+1];

/*Map structure For LR(1) Parser*/
struct Goto_Information{
	int size; 
	vector<char>temp_rules[MAX+1];
	vector<char>follow_set[MAX+1]; 
};

/*All the productions*/
struct Closure_Information{
	int size; 
	vector<char>canonical_set[MAX+1];
	vector<char>follow_set[MAX+1]; 
};
 

/*To save the node information*/
struct COMPR_NODE{
	bool operator()(const Goto_Information &a, const Goto_Information &b) const {
		if(a.size<b.size) return true;
		if(a.size>b.size) return false;
		if(a.size==b.size) {
			bool eq=false;
			for(int i=0;i<a.size;i++) {
				if(a.temp_rules[i].size()<b.temp_rules[i].size()) return true;
				if(a.temp_rules[i].size()>b.temp_rules[i].size()) return false;
				if(a.temp_rules[i].size() == b.temp_rules[i].size()) {
						for(int j=0;j<a.temp_rules[i].size();j++) {
							if(a.temp_rules[i][j]<b.temp_rules[i][j]) return true;
							if(a.temp_rules[i][j]>b.temp_rules[i][j]) return false;
							if(a.temp_rules[i][j] == b.temp_rules[i][j]) {
								eq=true;
							}
						}
				}
			}
			if(eq) {
				for(int i=0;i<a.size;i++) {
				if(a.follow_set[i].size()<b.follow_set[i].size()) return true;
				if(a.follow_set[i].size()>b.follow_set[i].size()) return false;
				if(a.follow_set[i].size() == b.follow_set[i].size()) {
					for(int j=0;j<a.follow_set[i].size();j++){
						if(a.follow_set[i][j]<b.follow_set[i][j]) return true;
						if(a.follow_set[i][j]>b.follow_set[i][j]) return false;
						if(a.follow_set[i][j] == b.follow_set[i][j]) {
							eq = true;
						}
					}
				}
			 }
			}
			return false;
		}
		return false;
	}
};

/*The Node Map*/
map<Goto_Information,int,COMPR_NODE>I;
int state;
Closure_Information saved_states[MAX*2+1];

/*Function prototype*/
int canonical_cover_LR_1_items(int size, vector<char>temp_rules[],vector<char>follow_set[]);
void goto_move(int present_state_number,vector<bool>work);



void take_input_as_simple_rule(string s){
	rule_count++;
	given_rules[rule_count].push_back(s[0]);
	bool hash=false;
	for(int i=3;i<s.size();i++) {
		given_rules[rule_count].push_back(s[i]);
		if(s[i]=='#') hash=true;
	}
	if(hash) epsilon_rules[rule_count]=true;
}

void input(){	
	freopen("in12.txt","r",stdin);
	rule_count = 0;
	string s;
	
	memset(epsilon_rules,false,sizeof(epsilon_rules));
	
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
		/*To save it as normal rule*/
		take_input_as_simple_rule(s); 
		
	}
}

/*Function to calculate first*/
void find_first(int working_node){
	
	
	int size_1 = production[working_node].size();
	vector<int>result; 
	for(int i=0;i<size_1;i++){
		int base = 0;
		bool epsilon = false;
		while(true) {
			int size_2 = production[working_node][i].V.size();
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
	for(int i=0;i<first[working_node].size();i++) {
		temp[first[working_node][i]]=1;
	}
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
	
	while(true) {
		int size = non_terminal_nodes.size();
		int guni=0;
		for(int i=0;i<size;i++){
			int sz = first[non_terminal_nodes[i]].size();
			find_first(non_terminal_nodes[i]);
			int sz_new = first[non_terminal_nodes[i]].size();
			if(sz != sz_new) guni++;
		}
		if(guni==0) break;
	}
	cout<<"First Generated " << endl;
	int size = non_terminal_nodes.size();
	for(int i=0;i<size;i++){
		int size_2 =first_char[non_terminal_nodes[i]].size();
		cout<<char_non_terminal_nodes[i]<<": ";
		for(int j=0;j<size_2;j++){
			cout<<first_char[non_terminal_nodes[i]][j];
		}
		cout<<endl;
	}
}


bool checking_node_new_or_old(int size, vector<char>temp_rules[],vector<char>follow_set[]){
	Goto_Information temp;
	temp.size = size;
	for(int i=0;i<temp.size;i++){
		for(int j=0;j<temp_rules[i].size();j++) {
			temp.temp_rules[i].push_back(temp_rules[i][j]);
		}
		for(int j=0;j<follow_set[i].size();j++) {
			temp.follow_set[i].push_back(follow_set[i][j]);
		}
		
	}
	if(I[temp] == 0) {
		state++;
		I[temp]=state;
		return true;
	}
	return false;
}

int find_node_number(int size, vector<char>temp_rules[],vector<char>follow_set[]) {
	Goto_Information temp;
	temp.size = size;
	for(int i=0;i<temp.size;i++){
		for(int j=0;j<temp_rules[i].size();j++) {
			temp.temp_rules[i].push_back(temp_rules[i][j]);
		}
		for(int j=0;j<follow_set[i].size();j++) {
			temp.follow_set[i].push_back(follow_set[i][j]);
		}
	}
	return I[temp];
}

/*Find dot position*/
int find_dot_position(int idx,vector<char>temp_rules[]){
	for(int i=0;i<temp_rules[idx].size();i++){
		if(temp_rules[idx][i] == '.') return i;
	}
	return -1;
}


/*Function to generate look ahead*/
vector<char> generate_look_ahead(int idx,int dot_position,vector<char>temp_rules[],vector<char>follow_set[]){
	vector<char>look_aheads;
	int already_present[MAX*2+1];
	memset(already_present,0,sizeof(already_present)); 
	while(true){
		if((dot_position+2)>=temp_rules[idx].size()) {
			/*normal production string completed*/
			for(int i=0;i<follow_set[idx].size();i++) {
				if(already_present[follow_set[idx][i]] == 0) {
					already_present[follow_set[idx][i]] = 1;
					look_aheads.push_back(follow_set[idx][i]);
				}
			}
			break;
		}
		else if(temp_rules[idx][dot_position+2]>='A' && temp_rules[idx][dot_position+2]<=90) {
				/*NT,need to add the first*/
				bool hash=false;
				for(int i=0;i<first[temp_rules[idx][dot_position+2]].size();i++) {
					if(first[temp_rules[idx][dot_position+2]][i] == '#') hash = true;
					else {
						if(already_present[first[temp_rules[idx][dot_position+2]][i]] == 0) {
							already_present[first[temp_rules[idx][dot_position+2]][i]] = 1;
							char ch = first[temp_rules[idx][dot_position+2]][i];
							look_aheads.push_back(ch);
						}
					}
				}
				if(!hash) {
					break;
				}
				else {
					dot_position++;
					continue;
				}
		}
		else {
			/*direct terminal*/
			int int_val = temp_rules[idx][dot_position+2];
			if(already_present[temp_rules[idx][dot_position+2]]==0) {
				already_present[temp_rules[idx][dot_position+2]] = 1;
				char ch = int_val;
				look_aheads.push_back(ch);
			}
			
			break;
		}
		
	}
	return look_aheads;
}

/*Function to merge with dot*/
vector<char> merge_with_dot(int rule_number){
	vector<char>temp;
	temp.push_back(given_rules[rule_number][0]); //left side
	temp.push_back('.'); //dot
	for(int i=1;i<given_rules[rule_number].size();i++) {
		temp.push_back(given_rules[rule_number][i]);
	}
	return temp;
}

/*Function to add the closures*/
vector<vector<char> > generate_closure(char variable){
	
	vector<vector<char> > closure_productions;
	for(int i=1;i<=rule_count;i++) {
		if(given_rules[i][0] == variable) {
			/*Need to add productions*/
			vector<char>temp = merge_with_dot(i);
			closure_productions.push_back(temp);
		}
	}
	return closure_productions;
}

/*Function to check equality of vectors*/
bool checking_equality_of_vectors(vector<char>a, vector<char>b){
	if(a.size() != b.size()) return false; /*didn't match*/
	for(int i=0;i<a.size();i++) {
		if(a[i] == b[i]) continue;
		else return false;
	}
	return true;
}

/*Will modify the look aheads which are actually necessary to add in the closure and in combine the total production*/
vector<bool> adding_new_production(int size,vector<char>temp_rules[],vector<char>follow_set[],vector<char>closure_production,vector<char>look_aheads){
	vector<bool>needed_look_aheads;
	for(int i=0;i<look_aheads.size();i++) {
		needed_look_aheads.push_back(true);
	}
	for(int i=0;i<size;i++) {
		bool same = checking_equality_of_vectors(closure_production,temp_rules[i]);
		if(!same) continue;
		else {
			/*same*/
			/*might not need to add all the look aheads*/
			for(int j=0;j<needed_look_aheads.size();j++) {
				bool exist = false; /*nai*/
				for(int k=0;k<follow_set[i].size();k++) {
					if(look_aheads[j] == follow_set[i][k]) {
						exist = true; /*present so will automatically work*/
						needed_look_aheads[j] = false;
						break;
					}
				}
			}
		}
	}
	return needed_look_aheads;
}

bool vector_contains_all_false(vector<bool>a) {
	for(int i=0;i<a.size();i++) {
		if(a[i] == true) return false; 
	}
	return true; //all entry is false
}

void canonical_state_print(int size,vector<char>temp_rules[],vector<char>follow_set[]) {
	for(int i=0;i<size;i++) {
		cout<<temp_rules[i][0]<<" -> ";
		for(int j=1;j<temp_rules[i].size();j++) {
			cout<<temp_rules[i][j];
		}
		cout<<",";
		for(int j=0;j<follow_set[i].size();j++) {
			cout<<follow_set[i][j]<<"/";
		}
		cout<<endl;
	}
}

void save_state_print(int present_state_number){
	for(int i=0;i<saved_states[present_state_number].size;i++) {
		cout<<saved_states[present_state_number].canonical_set[i][0]<<" -> ";
		for(int j=1;j<saved_states[present_state_number].canonical_set[i].size();j++) {
			cout<<saved_states[present_state_number].canonical_set[i][j];
		}
		cout<<",";
		for(int j=0;j<saved_states[present_state_number].follow_set[i].size();j++) {
			cout<<saved_states[present_state_number].follow_set[i][j]<<"/";
		}
		cout<<endl;
	}
}

/*Function to save nodes*/
void save_state(int size, vector<char>temp_rules[],vector<char>follow_set[],int present_state_number){
	saved_states[present_state_number].size = size;
	for(int i=0;i<size;i++) {
		for(int j=0;j<temp_rules[i].size();j++) {
			saved_states[present_state_number].canonical_set[i].push_back(temp_rules[i][j]);
		}
		for(int j=0;j<follow_set[i].size();j++) {
			saved_states[present_state_number].follow_set[i].push_back(follow_set[i][j]);
		}
	}
	return; 
}

/*need to check which rule is been seen*/
int find_rule_number(vector<char>a){
	for(int i=0;i<=rule_count;i++) {
		int sz = given_rules[i].size();
		int sz_2 = a.size();
		sz_2--; //for not counting dot 
		if(sz == sz_2) {
			bool ok=true;
			for(int j=0;j<sz;j++) {
				if(a[j] != given_rules[i][j]) {
					ok=false;
					break;
				}
			}
			if(ok) {
				cout<<endl;
				return i; 
			}
		}
	}
}

/*Function to save reduction rules*/
vector<bool> save_reduction_rule(int present_state_number,vector<bool>worked){
	for(int i=0;i<saved_states[present_state_number].size;i++) {
		int sz = saved_states[present_state_number].canonical_set[i].size();
		if(saved_states[present_state_number].canonical_set[i][sz-1] == '.') {
			//rule number
			int rule_number = find_rule_number(saved_states[present_state_number].canonical_set[i]);
			worked[i] = true;
			for(int j=0;j<saved_states[present_state_number].follow_set[i].size();j++) {
				if(parser_table[present_state_number][saved_states[present_state_number].follow_set[i][j]] == -1) {
					/* normal insert */
					parser_table[present_state_number][saved_states[present_state_number].follow_set[i][j]] =rule_number;
					type_of_operation[present_state_number][saved_states[present_state_number].follow_set[i][j]] = 1;
				}
				else {
					cout<<"ERROR OCCURED"<<endl;
					save_state_print(present_state_number);
					if(type_of_operation[present_state_number][saved_states[present_state_number].follow_set[i][j]] == 1) {
						cout<<"Reduce Reduce Error" << endl;
					}
					else {
						cout<<"Shift Reduce Error"<<endl;
					}
					exit(0);
				}
			}
		}
	}
	return worked;
}

int find_dot_in_a_vector(vector<char>a) {
	for(int i=0;i<a.size();i++) {
		if(a[i] == '.') return i;
	}
}

/*This function will create the go to moves*/
void goto_move(int present_state_number,vector<bool>work) {
	cout<<"what "<<present_state_number<<endl;
	
	for(int i=0;i<saved_states[present_state_number].size;i++) {
		if(work[i]==false) {
			int dot_position = find_dot_in_a_vector(saved_states[present_state_number].canonical_set[i]);
			char ch = saved_states[present_state_number].canonical_set[i][dot_position+1];
			int size=0;
			vector<char>temp_rules[MAX*2+1];
			vector<char>follow_set[MAX*2+1];
			for(int j=i;j<saved_states[present_state_number].size;j++) {
				if(work[j]==false) {
					int dot_position2 = find_dot_in_a_vector(saved_states[present_state_number].canonical_set[j]);
					char ch2 = saved_states[present_state_number].canonical_set[j][dot_position2+1];
					if(ch==ch2) {
						for(int k=0;k<saved_states[present_state_number].canonical_set[j].size();k++) {
							temp_rules[size].push_back(saved_states[present_state_number].canonical_set[j][k]);
						}
						swap(temp_rules[size][dot_position2],temp_rules[size][dot_position2+1]);
						for(int k=0;k<saved_states[present_state_number].canonical_set[j].size();k++) {
							cout<<temp_rules[size][k];
						}
						cout<<",";
						for(int k=0;k<saved_states[present_state_number].follow_set[j].size();k++) {
							follow_set[size].push_back(saved_states[present_state_number].follow_set[j][k]);
							cout<<follow_set[size][k];
						}
						cout<<endl;
						work[j]=true;
						size++;
					}
					
				}
			}
			int node = canonical_cover_LR_1_items(size,temp_rules,follow_set);
			cout<<"done " << node <<" "<<ch<<endl;
			if(parser_table[present_state_number][ch] == -1) {
				parser_table[present_state_number][ch] = node;
				type_of_operation[present_state_number][ch] = 2; //shift 
			}
			else {
				cout<<"ERROR OCCURED "<<present_state_number<<endl;
				save_state_print(present_state_number);
				if(type_of_operation[present_state_number][ch] == 1) {
					cout<<"Shift Reduce Error" << endl;
				}
				else {
					cout<<"Reduce Reduce Error"<<endl;
				}
				exit(0);
			}
		}
	}
}

int canonical_cover_LR_1_items(int size, vector<char>temp_rules[],vector<char>follow_set[]){
	/*Need to check new node or not*/
	cout<<"called "<<endl;
	bool check = checking_node_new_or_old(size,temp_rules,follow_set);
	if(check) {
		int present_state_number = find_node_number(size,temp_rules,follow_set); 
		/*calculation of new node*/
		/*find the closures*/
		for(int i=0;i<size;i++){
			/*find the dot*/
			int dot_position = find_dot_position(i,temp_rules);
			/*the character after the node*/
			if(dot_position == (temp_rules[i].size()-1)) {
				/*reduction rule*/
				/*nothing to do*/
			}
			else if(temp_rules[i][dot_position+1]>=65 && temp_rules[i][dot_position+1]<=90) {
				/*non terminal need to add prodcuctions*/
				
				/*Generate the look ahead*/
				vector<char>look_aheads;
				look_aheads = generate_look_ahead(i,dot_position,temp_rules,follow_set);
				
				/*Now need to add the closures*/
				vector<vector<char> > closure_productions = generate_closure(temp_rules[i][dot_position+1]);
				for(int j=0;j<closure_productions.size();j++) {
					vector<bool> needed_look_aheads = adding_new_production(size,temp_rules,follow_set,closure_productions[j],look_aheads);
					bool all_false = vector_contains_all_false(needed_look_aheads);
					if(all_false) {
							/*all entry is false no need to add*/
					}
					else {
						/*New production will be added*/
						for(int k=0;k<closure_productions[j].size();k++) {
							temp_rules[size].push_back(closure_productions[j][k]);
						}
						/*Adding Look Aheads*/
						for(int k=0;k<look_aheads.size();k++) {
							if(needed_look_aheads[k] == true) {
								follow_set[size].push_back(look_aheads[k]);
							}
						}
						size++;
					}
				}
				
			}
			else {
				/*terminals*/
				/*no extra productions*/
			}
		}
		
		/*Correcting Hash closures*/
		for(int i=0;i<size;i++) {
			if(temp_rules[i][2] == '#') {
				temp_rules[i][1] ='#';
				temp_rules[i][2] = '.';
			}
		}
		
		/*saving the state*/
		save_state(size,temp_rules,follow_set,present_state_number);
		/*Reduction rules saving*/
		vector<bool>worked;
		for(int i=0;i<size;i++) {
			worked.push_back(false);
		}
		worked = save_reduction_rule(present_state_number,worked);
		/*Now goto move*/
		save_state_print(present_state_number);
		cout<<"present state "<<present_state_number<<" "<<worked.size()<<" "<<worked[0]<<" "<<worked[1]<<" "<<worked[2]<<endl;
		cout<<"going " << endl;
		goto_move(present_state_number,worked); 
		return present_state_number;
	}
	else {
		/*this node is already calculated*/
		int state_number = find_node_number(size,temp_rules,follow_set);
		cout<<"already calculated "<<state_number<<endl;
		return state_number;
	}	
}


void print_parser_table(){
	cout<<state<<endl;
	for(int i=1;i<=state;i++){
		cout<<"i: "<<i<<endl;
		cout<<"non terminal " << endl;
		for(int j=0;j<non_terminal_nodes.size();j++) {
			cout<<char_non_terminal_nodes[j]<< " : "<< parser_table[i][non_terminal_nodes[j]]<<" " << type_of_operation[i][non_terminal_nodes[j]] <<endl;
		}
		cout<<"terminal " << endl;
		bool hash=false;
		for(int j=0;j<terminal_nodes.size();j++) {
			cout<<char_terminal_nodes[j]<< " : "<< parser_table[i][terminal_nodes[j]]<<" "<< type_of_operation[i][terminal_nodes[j]] << endl;
			if(char_non_terminal_nodes[j] == '#') {
				if(parser_table[i][terminal_nodes[j]] != -1) {
					hash=true;
				}
			}
		}
		cout<<"$ "<<parser_table[i]['$']<<" "<< type_of_operation[i]['$']<<endl;
		if(type_of_operation[i]['$'] != -1) {
			save_state_print(i);
		}
		if(hash) {
			cout<<"YES"<<endl;
		}
		
	}
}



void string_parse(string s){
	stack<int>S;
	S.push(1); //the starting
	int ptr=0;
	cout<<s<<endl;
	while(S.empty() != true) {
		int new_state = parser_table[S.top()][s[ptr]];
		//cout<<new_state<<" stack top "<<S.top()<<endl;
		if(new_state == -1) {
			cout<<"This string doesn't belong to this grammer" << endl;
			exit(0);
		}
		else {
			if(type_of_operation[S.top()][s[ptr]] == 1) {
				/*reduce*/
				int rule_number = parser_table[S.top()][s[ptr]];
				cout<<given_rules[rule_number][0]<<"->";
				for(int i=1;i<given_rules[rule_number].size();i++) {
					cout<<given_rules[rule_number][i];
				}
				cout<<endl;
				int sz = given_rules[rule_number].size()-1;
				if(!epsilon_rules[rule_number]) {
						for(int i=1;i<=sz*2;i++) {
							S.pop();
						}
				}
				int notun_state = parser_table[S.top()][given_rules[rule_number][0]];
				S.push(given_rules[rule_number][0]);
				if(given_rules[rule_number][0] == '^') {
					if(ptr==(s.size()-1)) {
						printf("Accepted\n");
						exit(0);
					}
				}
				S.push(notun_state); 
				
			}
			else {
				/*shift*/
				int int_val = s[ptr];
				int v = S.top();
				S.push(int_val);
				S.push(parser_table[v][s[ptr]]);
				ptr++;
			}
		}
	}
}

void initialize(){
	memset(parser_table,-1,sizeof(parser_table));
	memset(type_of_operation,-1,sizeof(type_of_operation));
}

void start(){
	vector<char>temp_rules[25];
	vector<char>follow_set[25];
	state=0;
	int size=1;
	temp_rules[0].push_back('^'); //Starting speacial symbol
	temp_rules[0].push_back('.'); 
	char ch = non_terminal_nodes[0];
	temp_rules[0].push_back(ch); //Starting symbol
	follow_set[0].push_back('$');
	
	given_rules[0].push_back('^');
	given_rules[0].push_back(ch);
	
	canonical_cover_LR_1_items(size,temp_rules,follow_set);
}


int main(void){
	input();
	initialize();
	calculate_first();
	start();
	
	print_parser_table();
	
	string s;
	cin>>s;
	s=s+'$';
	string_parse(s);
	return 0;
}
