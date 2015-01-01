%{
#include <stdio.h>
#define YY_DECL int yylex()

%}

%%
[ \n\t]                  ;
[0-9]* {
printf("NUMBER\n");
}

\( {
printf("LPAREN\n");
}

\) {
printf("RPAREN\n");
}
\+ {
printf("NOTE\n");
}

\- {
printf("REST\n");
}

\{ {
printf("LBRAC\n");
}
\} {
printf("RBRAC\n");
}
. {
printf("ERROR\n");
}
%%
