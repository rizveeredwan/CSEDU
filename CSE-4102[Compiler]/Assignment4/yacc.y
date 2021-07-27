%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int t=0;

%}

%start start_state

%union{
	char* sval;//for string type things
}

%token <sval> INTEGER
%token <sval> REAL
%token <sval> ID TRUE FALSE
%token <sval> '+' '-' '*' '/' '=' ',' '(' ')' ';'

%type <sval> assignment vars exprs expr sum term factor start_state


%right '='
%left '+' '-'
%left '*' '/'

%%
	
factor : TRUE
	{
		printf("factor from true.\n");
		printf("desired values in stack now: %s\n",$1);
		$$ = $1; //stack: factor  true
		
	}
	| 
	FALSE 
	{
		printf("factor from false.\n");
		printf("desired values in stack now: %s\n",$1);
		$$ = $1; //stack : factor false
	
	}
	|
	INTEGER
	{
		printf("factor from integer.\n");
		printf("desired values in stack now: %s\n",$1);
		$$ = $1; //stack : factor false
	}
	|
	REAL
	{
		printf("factor from real.\n");
		printf("desired values in stack now: %s\n",$1);
		$$ = $1; //stack : factor false
	}
	|
	'(' expr ')'
	{
		printf("factor from ( expr ).\n");
		printf("desired values in stack now: %s\n",$2);
		$$ = $2; //stack : factor generation_from_expr 
	}	
	| ID 
	{
		printf("factor from id.\n");
		printf("desired values in stack now: %s\n",$1);
		$$ = $1; //stack : factor generation_from_expr 
	}
	;
	
term 	: factor
	{
		printf("term from factor.\n");
		printf("desired values in stack now: %s\n",$1);		
		$$ = $1; //stack : factor value_of_factor 
		
	}
	|
	term '*' factor 
	{
		printf("term from term * factor.\n");
		printf("desired values in stack now: %s %s\n",$1,$3);
		t++;
		char *address_code;
		char test[]="t";
		address_code = strdup(test); //copying t 

		
		char rem;
		int step=0;
		int number=t; 
		char num_string[100];
		while(number!=0){ //integer to string conversion 
			rem=number%10+'0';
			number /= 10;
			num_string[step]=rem;
			step++;
		}
		num_string[step]='\0';
		//string reverse 
		int length=strlen(num_string);
		for(int i=0;i<length/2;i++) {
			char c=num_string[i];
			num_string[i]=num_string[length-(i+1)];
			num_string[length-(i+1)]=c;
		}
		//string cat
		strcat(address_code,num_string); //t1
		printf("%s = %s * %s\n",address_code,$1,$3); //printing t1 = t2 * t3 

		//stack push 
		$$ = address_code; // stack: term t1 				
	}
	|
	term '/' factor
	{
		printf("term from term / factor.\n");
		printf("desired values in stack now: %s %s\n",$1,$3);
		t++;
		char *address_code;
		char test[]="t";
		address_code = strdup(test); //copying t 

		
		char rem;
		int step=0;
		int number=t; 
		char num_string[100];
		while(number!=0){ //integer to string conversion 
			rem=number%10+'0';
			number /= 10;
			num_string[step]=rem;
			step++;
		}
		num_string[step]='\0';
		//string reverse 
		int length=strlen(num_string);
		for(int i=0;i<length/2;i++) {
			char c=num_string[i];
			num_string[i]=num_string[length-(i+1)];
			num_string[length-(i+1)]=c;
		}
		//string cat
		strcat(address_code,num_string); //t1
		printf("%s = %s / %s\n",address_code,$1,$3); //printing t1 = t2 / t3 

		//stack push 
		$$ = address_code; // stack: term t1 	
	}	
	;
	
sum     :term
	{
		printf("sum from term.\n");
		printf("desired values in stack now: %s\n",$1);
		$$ = $1; //stack: sum t1
	}
	|
	'-' term
	{
		printf("sum from  - term.\n");
		printf("desired values in stack now: %s\n",$2);
		t++;
		char *address_code;
		char test[]="t";
		address_code = strdup(test); //copying t 

		char rem;
		int step=0;
		int number=t; 
		char num_string[100];
		while(number!=0){ //integer to string conversion 
			rem=number%10+'0';
			number /= 10;
			num_string[step]=rem;
			step++;
		}
		num_string[step]='\0';
		//string reverse 
		int length=strlen(num_string);
		for(int i=0;i<length/2;i++) {
			char c=num_string[i];
			num_string[i]=num_string[length-(i+1)];
			num_string[length-(i+1)]=c;
		}
		//string cat
		strcat(address_code,num_string); //t1
		printf("%s = -%s\n",address_code,$2); //printing t1 = -t2 

		//stack push 
		$$ = address_code; // stack: sum t1 	

		
	}
	|
	sum '+' term
	{
		printf("sum from sum + term.\n");
		printf("desired values in stack now: %s %s\n",$1,$3);
		t++;
		char *address_code;
		char test[]="t";
		address_code = strdup(test); //copying t 

		char rem;
		int step=0;
		int number=t; 
		char num_string[100];
		while(number!=0){ //integer to string conversion 
			rem=number%10+'0';
			number /= 10;
			num_string[step]=rem;
			step++;
		}
		num_string[step]='\0';
		//string reverse 
		int length=strlen(num_string);
		for(int i=0;i<length/2;i++) {
			char c=num_string[i];
			num_string[i]=num_string[length-(i+1)];
			num_string[length-(i+1)]=c;
		}
		//string cat
		strcat(address_code,num_string); //t1
		printf("%s = %s + %s\n",address_code,$1,$3); //printing t1 = t2 + t3 

		//stack push 
		$$ = address_code; // stack: sum t1 	

	}
	|
	sum '-' term
	{
		printf("sum from sum - term.\n");
		printf("desired values in stack now: %s %s\n",$1,$3);
		t++;
		char *address_code;
		char test[]="t";
		address_code = strdup(test); //copying t 

		char rem;
		int step=0;
		int number=t; 
		char num_string[100];
		while(number!=0){ //integer to string conversion 
			rem=number%10+'0';
			number /= 10;
			num_string[step]=rem;
			step++;
		}
		num_string[step]='\0';
		//string reverse 
		int length=strlen(num_string);
		for(int i=0;i<length/2;i++) {
			char c=num_string[i];
			num_string[i]=num_string[length-(i+1)];
			num_string[length-(i+1)]=c;
		}
		//string cat
		strcat(address_code,num_string); //t1
		printf("%s = %s - %s\n",address_code,$1,$3); //printing t1 = t2 - t3 

		//stack push 
		$$ = address_code; // stack: sum t1 	
	}
	;
	//expr → sum
expr	:sum
	{
		printf("expr from sum.\n");
		printf("desired values in stack now: %s\n",$1);
		$$ = $1; //stack: expr t1
	}
	;
	//vars → id |vars , id
vars	: ID
	{
		printf("vars from id.\n");
		printf("desired values in stack now: %s\n",$1);
		$$ = $1; //stack: vars t1
		
	}
	|
	vars ',' ID
	{
		printf("vars from vars , id.\n");
		printf("desired values in stack now: %s %s\n",$1,$3);
		char *temp1,*temp2;
		temp1 = strdup($1);
		temp2 = strdup($3);

		strcat(temp1,",");
		strcat(temp1,temp2);

		$$=temp1;  	
	}
	;
	//exprs → expr | exprs , expr	
exprs	: expr
	{
		printf("exprs from expr.\n");
		printf("desired values in stack now: %s\n",$1);
		printf("value = %s\n",$1);
		$$=$1; //stack exprs value_of_expr 	
	}
	|
	exprs ',' expr
	{
		printf("exprs from exprs , expr .\n");
		printf("desired values in stack now: %s %s\n",$1,$3);
		char *temp1,*temp2;
		temp1 = strdup($1);
		temp2 = strdup($3);

		strcat(temp1,",");
		strcat(temp1,temp2);

		$$=temp1;  
	}
	;
	//assignment → vars := exprs;
assignment:vars '=' exprs ';'
	{
		printf("assignment from vars = exprs.\n");
		printf("desired values in stack now: %s %s\n",$1,$3);
		char *variable,*ex;
		ex = strdup($3);
		variable = strdup($1);
		
		char var_names[200][200];
		char ex_des[200][200];
		
		int cnt_var=-1,cnt_ex=-1;
		int str_ptr=-1;
		char temp[200];
		for(int i=0;i<strlen(variable);i++){ //separation of variables 
			str_ptr++;
			if(variable[i]==','){
				temp[str_ptr]='\0';
				cnt_var++;
				strcpy(var_names[cnt_var],temp); 
				str_ptr=-1;
			}
			else if(i==strlen(variable)-1){
				temp[str_ptr]=variable[i];
				temp[str_ptr+1]='\0';
				cnt_var++;
				strcpy(var_names[cnt_var],temp); 
				str_ptr=-1;
			}
			else {
				temp[str_ptr]=variable[i];	//normal string add 
			}		
		}
		str_ptr=-1;
		char temp2[150];
		printf("ex = %s\n",ex);
		for(int i=0;i<strlen(ex);i++){ //separation of expressions
			str_ptr++;
			if(ex[i]==','){
				temp[str_ptr]='\0';
				cnt_ex++;
				strcpy(ex_des[cnt_ex],temp); 
				str_ptr=-1;
			}
			else if(i==(strlen(ex)-1)){
				temp[str_ptr]=ex[i];
				temp[str_ptr+1]='\0';
				printf("special %s\n",temp);
				cnt_ex++;
				strcpy(ex_des[cnt_ex],temp); 
				str_ptr=-1;
			}
			else {
				temp[str_ptr]=ex[i];	//normal string add 
			}		
		}
		//printing
		
		for(int i=0;i<=cnt_var;i++) {
			printf("%s = %s\n",var_names[i],ex_des[i]);
		}
		/*char *test;
		test = strdup(variable);
		printf("desired values in stack now: %s %s notun %s\n",$1,$3,test);*/
	
		$$ = "done";						
	};	

start_state : assignment
	{
		printf("start_state from assignment.\n");
		printf("desired values in stack now: %s\n",$1);
		char arr[]="3-Address Code generated.";
		printf("%s\n",arr);
		$$=arr;
	};
	
		
%%

extern int yylex();
extern int yyparse();


int main(){
	freopen("in.txt","r",stdin);
	int n;
	n=1;
	char input[150];
	for(int i=0;i<n;i++){
		yyparse();	
	}
}



