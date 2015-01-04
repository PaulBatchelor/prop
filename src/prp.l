%{
#include <stdio.h>
#define YY_DECL int yylex()
#include "prp.tab.h"
%}
%option noyywrap
%%
[ \n\t]                  ;
[0-9]* {
//printf("NUMBER\n");
prplval.ival = atoi(yytext);
return NUMBER;
}

\( {
//printf("LPAREN\n");
return LPAREN;

}

\) {
//printf("RPAREN\n");
return RPAREN;
}
\+ {
//printf("NOTE\n");
return NOTE;
}

\- {
//printf("REST\n");
return REST;
}

[{] {
//printf("LBRAC\n");
return LBRAC;
}
[}] {
//printf("RBRAC\n");
return RBRAC;
}
. {
//printf("ERROR\n");
return ERROR;
}
%%
