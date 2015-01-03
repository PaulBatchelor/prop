#include <stdio.h>
#include <unistd.h>
int yylex();
int yyparse(void);
void yyerror(const char *s);
FILE *yyin;
