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


map<string,int>M;
map<int,string>M2;

struct info{
	vector<int>right_side;
};

vector<info>left_side[20];
vector<string>in,given_string; 

bool syntax_error;
bool grammer_error;


void make_map(){
	M["goal"] = 1;
	M["expr"] = 2;
	M["term"] = 3;
	M["expr2"] = 4;
	M["epsilon"] = 5;
	M["factor"] = 6;
	M["number"] = 7;
	M["id"] = 8;
	M["("] = 9;
	M[")"] = 10;
	M["+"] = 11;
	M["-"] = 12;
	M["*"] = 13;
	M["/"] = 14;
	M["term2"]=15;
	
	M2[1] = "goal";
	M2[2] = "expr";
	M2[3] = "term";
	M2[4] = "expr2";
	M2[5] = "epsilon";
	M2[6] = "factor";
	M2[7] = "number";
	M2[8] = "id";
	M2[9] = "(";
	M2[10] = ")";
	M2[11] = "+";
	M2[12] = "-";
	M2[13] = "*";
	M2[14] = "/";
	M2[15]="term2";
} 

bool avaiable_token(string s){
	if(s=="number" || s == "+" || s == "-" || s == "*" || s == "/" || s == "id" || s == "(" || s == ")") return true;
	return false; 
}

void make_graph(){
	//goal -> expr 
	info temp;
	temp.right_side.push_back(M["expr"]);
	left_side[M["goal"]].push_back(temp);
	temp.right_side.clear();
	
	//expr -> term expr2
	temp.right_side.push_back(M["term"]);
	temp.right_side.push_back(M["expr2"]);
	left_side[M["expr"]].push_back(temp);
	temp.right_side.clear();
	
	//expr2-> + term expr2 | - term expr2 | epsilon
	temp.right_side.push_back(M["+"]);
	temp.right_side.push_back(M["term"]);
	temp.right_side.push_back(M["expr2"]);
	left_side[M["expr2"]].push_back(temp);
	temp.right_side.clear();
	
	temp.right_side.push_back(M["-"]);
	temp.right_side.push_back(M["term"]);
	temp.right_side.push_back(M["expr2"]);
	left_side[M["expr2"]].push_back(temp);
	temp.right_side.clear();
	
	temp.right_side.push_back(M["epsilon"]);
	left_side[M["expr2"]].push_back(temp);
	temp.right_side.clear();
	
	//term -> factor term2 
	temp.right_side.push_back(M["factor"]);
	temp.right_side.push_back(M["term2"]);
	left_side[M["term"]].push_back(temp);
	/*for(int i=0;i<left_side[M["term"]].size();i++){
		info check=left_side[M["term"]][i];
		for(int j=0;j<check.right_side.size();j++){
			cout<<M2[check.right_side[j]]<<" ";
		}
		cout<<endl;
	}*/
	temp.right_side.clear();
	
	//term2 -> * factor term2 | / factor term2 | epsilon
	temp.right_side.push_back(M["*"]);
	temp.right_side.push_back(M["factor"]);
	temp.right_side.push_back(M["term2"]);
	left_side[M["term2"]].push_back(temp);
	temp.right_side.clear();
	
	temp.right_side.push_back(M["/"]);
	temp.right_side.push_back(M["factor"]);
	temp.right_side.push_back(M["term2"]);
	left_side[M["term2"]].push_back(temp);
	temp.right_side.clear();
	
	temp.right_side.push_back(M["epsilon"]);
	left_side[M["term2"]].push_back(temp);
	temp.right_side.clear();
	
	//factor -> number | id | (expr)
	temp.right_side.push_back(M["number"]);
	left_side[M["factor"]].push_back(temp);
	temp.right_side.clear();
	
	temp.right_side.push_back(M["id"]);
	left_side[M["factor"]].push_back(temp);
	temp.right_side.clear();
	
	temp.right_side.push_back(M["("]);
	temp.right_side.push_back(M["expr"]);
	temp.right_side.push_back(M[")"]);
	left_side[M["factor"]].push_back(temp);
	temp.right_side.clear();
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
		cout<<given_string[i]<<" ";
	}
	cout<<endl;
}

void left_most_derivation(vector<info>derivation){
		vector<info>answer;
		//repeating line cancel
		for(int i=0;i<derivation.size();i++){
				info temp=derivation[i];
				if(i==0) {
					answer.push_back(temp);
				}
				else{
					bool ok=true;
					for(int j=0;j<temp.right_side.size();j++){
						if(temp.right_side[j] == derivation[i-1].right_side[j]) continue;
						ok=false;
					}
					if(ok && temp.right_side.size() == derivation[i-1].right_side.size()){
						continue;
					}
					else{
						answer.push_back(temp);
					}
					
				}
		}
		//now print 
		printf("goal => expr\n");
		int pnt=0;
		for(int i=1;i<answer.size();i++){
			info temp = answer[i];
			printf("     => ");
			int guni = -1;
			bool barabo = false;
			for(int j=0;j<temp.right_side.size();j++){
				bool bosaisi = false;
				if(M2[temp.right_side[j]] == "epsilon") continue;
				else {
					string var =M2[temp.right_side[j]]; 
					if(var == "number" ||  var == "id") {
						guni++;
						if(guni == pnt) {
							barabo = true;
						}
						if(guni<=pnt){
							var = in[guni];
						}
					}
					cout<<var<<" ";
					if(barabo) {
						pnt++;
					}
					//cout<<M2[temp.right_side[j]]<<" ";
				}
			}	
			printf("\n");
		}
		info temp = answer[answer.size()-1];
		for(int i=0;i<temp.right_side.size();i++){
			if(M2[temp.right_side[i]] == "term2" || M2[temp.right_side[i]] == "expr2"){
				printf("     => ");
				temp.right_side[i] =M["epsilon"];
				int guni = -1;
				for(int j=0;j<temp.right_side.size();j++){
					if(M2[temp.right_side[j]] == "epsilon") continue;
					string var = M2[temp.right_side[j]];
					if(var == "epsilon") continue;
					if(var == "number" ||  var == "id"){
						guni++;
						var = in[guni];
					}
					cout<<var<<" ";
				}
				cout<<endl;
			}
		}
}

void recursive_descent_parsing(vector<string> s,int idx,vector<info>derivation,int matched_upto){
	
	
	if(idx>=s.size()){
		int length=derivation.size();
		info temp=derivation[length-1];
		bool complete=true;
		for(int i=matched_upto+1;i<temp.right_side.size();i++){
			
			if(left_side[temp.right_side[i]].size() != 0) {
				if(M2[temp.right_side[i]] == "expr2"|| M2[temp.right_side[i]] == "term2"){
					continue;
				}
				else{
					complete=false;
					break;
				}
			}
			
		}
		if(complete){
			//cout<<"milse"<<endl;
			grammer_error=false;
			left_most_derivation(derivation);
			
		}
		return;
	}
	int length=derivation.size();
	if(length==0){
		//starting
		info temp;
		temp.right_side.push_back(M["expr"]);
		derivation.push_back(temp);
		recursive_descent_parsing(s,0,derivation,-1); 
		derivation.pop_back();
	}
	else{
		//choice
		//aABCD
		info temp=derivation[length-1];
		int node=temp.right_side[matched_upto+1]; //A
		if(node<=0 || node>15) return;
		bool terminal=true;
		for(int i=0;i<left_side[node].size();i++){ 
			terminal=false; 
			info per_rule=left_side[node][i]; //A->PQR
			
			info sent;
			for(int k=0;k<=matched_upto;k++){
				sent.right_side.push_back(temp.right_side[k]); //a
			}
			for(int k=0;k<per_rule.right_side.size();k++){
				sent.right_side.push_back(per_rule.right_side[k]);//aPQR
			}
			
			for(int k=matched_upto+2;k<temp.right_side.size();k++){
				sent.right_side.push_back(temp.right_side[k]);//aPQRBCD
			}
			//now previous aABCD
			//now aBCD, aPQRBCD
			derivation.push_back(sent);
			recursive_descent_parsing(s,idx,derivation,matched_upto);
			if(!grammer_error) return;
			derivation.pop_back();
		}
		if(terminal) {
			//no outgoing edges 
			if(s[idx]==M2[node]) {
				//number,id,(,),+,-,*,/
				info sent=temp;
				derivation.push_back(sent);
				recursive_descent_parsing(s,idx+1,derivation,matched_upto+1);
				if(!grammer_error) return;
				derivation.pop_back();
				return;
			 }
			 else{
				if(M2[node]=="epsilon"){
					info sent=temp;
					derivation.push_back(sent);
					recursive_descent_parsing(s,idx,derivation,matched_upto+1);
					if(!grammer_error) return;
					derivation.pop_back();
					return;
				}
				else{
					return;
				}
			 }
		  }
		}
}

void input(){
	freopen("in.txt","r",stdin);
	freopen("out2.txt","w",stdout);
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
			if(temp != "" && temp != " ") {
				given_string.push_back(temp);
				if(temp >= "0" && temp <= "9") {
					in.push_back(temp);
					temp="number"; 
				}
				else if(temp == "+" || temp == "-" || temp == "*" || temp == "/" || temp == ")" || temp == "("){
					//in.push_back(temp);
				}
				else if(temp>="a" && temp <= "z"){
					in.push_back(temp);
					temp = "id"; 
				}
				//cout<<"temp = " << temp << endl;
				S.push_back(temp);
				
			}
			temp="";
		}
		/*for(int i=0;i<S.size();i++) {
			cout<<S[i]<<" ";
		}*/
		cout<<endl;
		//cout<<"done"<<endl;
		syntax_error=false;
		write_expression(S);
		//cout<<"done 1 " << endl;
		wrong_token(S);
		paranthesis_check(S);
		operator_missing(S);
		operator_work_failed(S);
		if(!syntax_error) {
			//cout<<"check starts"<<endl;
			grammer_error=true;
			vector<info>derivation;
			recursive_descent_parsing(S,0,derivation,-1);
			S.clear();
			in.clear();
			given_string.clear();
		}
		cout<<endl;
		in.clear();
		S.clear();
		given_string.clear();
	}
}

int main(int argc, char **argv){
	
	make_map();
	make_graph();
	input();
	return 0;
}


