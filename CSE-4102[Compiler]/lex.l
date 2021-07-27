/*
Author : Tushark Bansal
Email : tusharkbansal@gmail.com
*/


%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

char c;

%}

INTEGER  [0-9]+
ID [a-zA-Z_][0-9a-zA-Z_]*
REAL [0-9]+[.][0-9]*

ARITHMETIC_OPERATORS ['+' '\-' '*' '/']
OTHER_CHARACTERS ['=' ';' '(' ')' ',']


%%
[ \t] ;
[\n] ;



"true"	{yylval.sval = strdup(yytext);
		return (TRUE);}
"false"	{yylval.sval = strdup(yytext);
		return (FALSE);}

{INTEGER}  { yylval.sval = strdup(yytext);
	   printf("input: integer value now %s\n",yylval.sval);
	   return INTEGER; }

{REAL}  {  yylval.sval = strdup(yytext);
	   printf("input: floating value now %s\n",yylval.sval);
	   return REAL; }

{ID} {
	    yylval.sval = strdup(yytext);
	    printf("input: id now %s\n",yylval.sval);
	    return ID; 
}
{ARITHMETIC_OPERATORS}   {
            	c = yytext[0];
		printf("input: character now %c\n",c);
                return(c);
              }

{OTHER_CHARACTERS}   {
                 c = yytext[0];
		 printf("input: character now %c\n",c);
                 return(c);
              }

%%
