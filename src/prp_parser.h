#include <stdio.h>
#include <unistd.h>
#include "main.h"
int yylex();
int yyparse(void);
void yyerror(const char *s);
FILE *yyin;
