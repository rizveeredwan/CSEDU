#include <bits/stdc++.h>
using namespace std;

//Name: Redwan Ahmed Rizvee
//Roll : 09 

//grammar
//goal -> expr 
//expr -> term expr2
//expr2-> + term expr2 | - term expr2 | epsilon
//term -> factor term2 
//term2 -> * factor term2 | / factor term2 | epsilon
//factor -> number | id | (expr) 


bool syntax_error;
bool grammer_error;
int idx;
int number;
vector<bool>flag;

//prototype
bool goal(vector<string>S,vector<string>answer,int choice);
bool expr(vector<string>S,vector<string>answer,int choice);
bool term(vector<string>S,vector<string>answer,int choice);
bool expr2(vector<string>S,vector<string>answer,int choice);
bool term2(vector<string>S,vector<string>answer,int choice);
bool factor(vector<string>S,vector<string>answer,int choice);

bool avaiable_token(string s){
	if(s=="number" || s == "+" || s == "-" || s == "*" || s == "/" || s == "id" || s == "(" || s == ")") return true;
	return false; 
}


void paranthesis_check(vector<string>S){
	stack<int>sta;
	int counter=0;
	for(int i=0;i<S.size();i++){
		if(S[i]=="("){
			counter++;
			sta.push(i);
		}
		else if(S[i] ==")"){
			counter++;
			if(sta.empty()){
				printf("inappropriate ) found at %d th bracket\n",counter);
				syntax_error=true;
				return;
			}
			else{
				sta.pop();
			}
		}
	}
	if(sta.empty() != true){
		printf("paranthesis not balanced\n");
		return;
	}
}

void wrong_token(vector<string>S){
	for(int i=0;i<S.size();i++){
		bool ok=avaiable_token(S[i]);
		if(!ok){
			syntax_error=true;
			cout << "unrecognised keyword found " << "'" << S[i]<< "'"<<endl;
		}
	}
	return; 
}

void operator_missing(vector<string>S){
	for(int i=0;i<S.size();i++){
		if(S[i] == "number" || S[i] == "id") {
			if((i+1)<S.size()) {
				if(S[i+1]=="number" || S[i+1] == "id") {
					cout<<"operating missing error " << endl;
					syntax_error=true;
				}
			}
		}
	}
	return;
}

void operator_work_failed(vector<string>S){
	for(int i=0;i<S.size();i++){
		if(S[i] == "*" || S[i] == "/" || S[i] == "+" || S[i] == "-") {
			if((i+1)<S.size() && (i-1)>=0) {
				
			}
			else {
				syntax_error = true;
				cout<<"operator " << S[i] << " can't function properly due to insufficient number of operand " << endl;
			}
		}
		if(S[i] == "*" || S[i] == "/" || S[i] == "+" || S[i] == "-") {
			if((i+1)<S.size()) {
				if(S[i+1] == "*" || S[i+1] == "/" || S[i+1] == "+" || S[i+1] == "-") {
					syntax_error = true;
					cout<<"double operator problem " <<S[i] <<" "<<S[i+1]<< endl;
				} 
				continue;
			}
		}

	}
	return;
}

void write_expression(vector<string>S){
	cout<<"Expression : "; 
	for(int i=0;i<S.size();i++){
		cout<<S[i]<<" ";
	}
	cout<<endl;
}


//functions 
//factor -> number | id | (expr) 
bool factor(vector<string>S,vector<string>answer,int choice){
	if(choice == 0) {
		if(idx<S.size() && S[idx] == "number") {
			idx++;
			number++;
			int c1=number;
			flag.push_back(true);
			return true;
		}
		
		else if(idx<S.size() && S[idx] == "id") {
			idx++;
			number++;
			int c1=number;
			flag.push_back(true);
			return true;
		}
		
		else if(idx<S.size() && S[idx] == "(") {
			idx++;
			number++;
			int c1=number;
			bool ok = factor(S,answer,choice);
			flag.push_back(ok);
			
			if(idx<S.size() && S[idx] == ")") {
				flag.push_back(true);
				return true;
			}
			else {
				return false;
			}
			
		}
		return false;
	}
	else{
		
	}
}

//term2 -> * factor term2 | / factor term2 | epsilon
bool term2(vector<string>S,vector<string>answer,int choice){
	
	if(choice == 0) {
		if(idx <S.size() && S[idx]=="*"){
			idx++;
			number++;
			int c1=number;
			bool ok = factor(S,answer,choice);
			flag.push_back(ok);
			
			number++;
			int c2=number;
			bool ok1 = term2(S,answer,choice);
			flag.push_back(ok1);
			
			if(ok && ok1) return true;
			else{
				idx--;
				return false;
			}
			
		}
		else if(idx <S.size() && S[idx]=="/"){
			idx++;
			number++;
			int c1=number;
			bool ok = factor(S,answer,choice);
			flag.push_back(ok);
			
			number++;
			int c2=number;
			bool ok1 = term2(S,answer,choice);
			flag.push_back(ok1);
			
			if(ok && ok1) return true;
			else{
				idx--;
				return false;
			}
		}
		else if(idx <=S.size()){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		
	}
}


//expr2-> + term expr2 | - term expr2 | epsilon
bool expr2(vector<string>S,vector<string>answer,int choice){
	
	if(choice == 0) {
		if(idx <S.size() && S[idx]=="+"){
			idx++;
			number++;
			int c1=number;
			bool ok = term(S,answer,choice);
			flag.push_back(ok);
			
			number++;
			int c2=number;
			bool ok1 = expr2(S,answer,choice);
			flag.push_back(ok1);
			
			if(ok && ok1) return true;
			else{
				idx--;
				return false;
			}
			
		}
		else if(idx <S.size() && S[idx]=="-"){
			idx++;
			number++;
			int c1=number;
			bool ok = term(S,answer,choice);
			flag.push_back(ok);
			
			number++;
			int c2=number;
			bool ok1 = expr2(S,answer,choice);
			flag.push_back(ok1);
			
			if(ok && ok1) return true;
			else{
				idx--;
				return false;
			}
		}
		else if(idx <=S.size()){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		
	}
}

//term -> factor term2
bool term(vector<string>S,vector<string>answer,int choice){
	 
	if(choice==0){
		number++;
		int c1=number;
		bool ok = factor(S,answer,choice);
		flag.push_back(ok);
		
		number++;
		int c2=number;
		bool ok1 = term2(S,answer,choice);
		flag.push_back(ok1);
		
		if(ok && ok1) return true;
		else return false;
	}
	else{
		//printing purpose 
	}
}

//expr -> term expr2
bool expr(vector<string>S,vector<string>answer,int choice){
	
	if(choice == 0) {
		number++;
		int c1=number;
		bool ok = term(S,answer,choice);
		flag.push_back(ok);
		
		number++;
		int c2=number;
		bool ok1= expr2(S,answer,choice);
		flag.push_back(ok1);
		if(ok && ok1) {
			return true;
		}
		else{
			return false;
		}
	}
	else{
		
	}
	
}

//goal -> expr 
bool goal(vector<string>S,vector<string>answer,int choice){
	number=0;
	int c1=number;
	bool ok = expr(S,answer,choice); 
	flag.push_back(ok);
	return ok;
}

           
void input(){
	freopen("in2.txt","r",stdin);
	//freopen("out2.txt","w",stdout);
	string s;
	while(getline(cin,s)){
		string temp="";
		vector<string>S;
		for(int i=0;i<s.length();i++){
			while(s[i] != ' '){
				if(i>=s.size()) break;
				temp=temp+""+s[i];
				i++;
			}
			//cout<<temp<<endl;
			if(temp != "" && temp != " ")S.push_back(temp);
			temp="";
		}
		syntax_error=false;
		write_expression(S);
		wrong_token(S);
		paranthesis_check(S);
		operator_missing(S);
		operator_work_failed(S);
		if(!syntax_error) {
			grammer_error=true;
			idx = 0;
			vector<string>answer;
			bool ok = goal(S,answer,0);
			printf("ok %d\n",ok);
			//recursive_descent_parsing(S,0,derivation,-1);
			S.clear();
		}
		cout<<endl;
	}
}



int main(int argc,char **argv){
	input();
}
