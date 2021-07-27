%{
#include <stdio.h>
#include <math.h>
#include <string.h>
%}

%%
[0-9]+[RE][0-9]+		{printf("R came\n");}
[=][0-9A-Za-z]*			{printf("theres been equal\n");}
[0-9]*A$			{printf("hell yeah\n");}
([R][I][Z][V][E][E]){1,4}		{printf("A man has called his name.\n");}
[\*]"AAAAB"				{printf("***\n");}
(faith|just|prevailed)		{printf("faith or just or prevailed\n");}
"AAAA"/"1"			{printf("hoice\n");}
.			{return 0;}
\n			{return 0;}
%%

int main(void){
	//freopen("input.in","r",stdin);
	//freopen("output.out","w",stdout);
	yylex();
	return 0;
}
