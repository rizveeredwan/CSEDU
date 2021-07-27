%{
#include <stdio.h>
#include <math.h>
#include <string.h>
%}

%%
"abc"{1,4}[ \n\t] 	{printf("saklain \n");}
[0-9]{1,4}[ \n\t]	{int value=atoi(yytext);
						if((value%4)==0)printf("DIV_4* %s\n",yytext);
					}
[-+][0-9]+[ \n\t]	{printf("Signed %s\n",yytext);}
[0-9]+[.][0-9]+[ \n\t] 	{printf("Decimal %s\n",yytext);}
(([-+][0-9]+)|([0-9]+\.[0-9]+))(E|e)[-+][0-9]+[ \n\t] {printf("Scientific %s\n",yytext);}
0x[0-9A-F]{1,4}[ \n\t] 	{printf("Hex %s\n",yytext);}
[0-9A-F]{4}[0-9A-F]+[ \n\t] {printf("Overflow %s\n",yytext);}
[A-Za-z]([A-Za-z0-9])+[ \n\t] {printf("Id %s\n",yytext);}
=[ \n\t]		{printf("AssignOp %s\n",yytext);}
"+"[ \n\t]		{printf("AddOp %s\n",yytext);}
"*"[ \n\t]		{printf("MultOP %s\n",yytext);}
((<)|(>=)|(>)|(<=))[ \n\t]	{printf("Relop %s\n",yytext);}
.			{return 0;}
\n			{return 0;}
%%

int main(void){
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	yylex();
	return 0;
}
