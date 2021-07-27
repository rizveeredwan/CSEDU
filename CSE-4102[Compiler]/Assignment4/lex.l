/*
	Name: Redwan Ahmed Rizvee
	Roll:09
*/

%{
#include<stdio.h>
#include<string.h>
#include "y.tab.h"

char ch;

%}

REAL    [0-9]+[.][0-9]+
INTEGER [0-9]+
ID	[a-zA-Z_][0-9a-zA-Z_]*
ARITHMETIC_OPERATORS ['+' '\-' '*' '/']
OTHER_CHARACTERS	['=' ',' '(' ')' ';']


%%
[ \t] ;
[\n]  ;

"true" {yylval.sval=strdup(yytext);
	return(TRUE);	
	}

"false" {yylval.sval=strdup(yytext);
	return(FALSE);	
	}
{INTEGER} { yylval.sval=strdup(yytext);
	    printf("integer value = %s\n",yylval.sval);
	  return INTEGER;
	}
{REAL}  { yylval.sval=strdup(yytext);
	  printf("real value = %s\n",yylval.sval);
	  return REAL;
	}
{ID}    {yylval.sval=strdup(yytext);
	  printf("value here id = %s\n",yylval.sval);
	 return ID;
	}

{ARITHMETIC_OPERATORS} {
			 ch=yytext[0];
			 printf("arith character = %c\n",ch);
			 return (ch);
		       }

{OTHER_CHARACTERS} {ch=yytext[0];
		    printf("other character = %c\n",ch);
		    return (ch);
		   }

%%
