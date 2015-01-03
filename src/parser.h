#include <stdio.h>
#include <unistd.h>

#define PRP_PARSER_INIT prp_create_user_options(&PRP_UO)
#define PRP_PARSER_DESTROY prp_create_user_options(&PRP_UO); prp_destroy(&PRP_GD)
#define prp_setvar(var,val) PRP_UO.var = val
#define GEN_PS(var) if(PRP_UO.write_ps) prp_gen_ps(PRP_GD, var)

int yylex();
int yyparse(void);
void yyerror(const char *s);
FILE *yyin;

typedef struct {
int user_ts;
double ts;
int user_duration;
double duration;
int write_ps;
}PRP_USER_OPTIONS;

/*global data for user options, I'm sorry for this */
PRP_USER_OPTIONS PRP_UO;

int prp_create_user_options(PRP_USER_OPTIONS *u);
int prp_init_with_options(PRP_DATA *d, PRP_USER_OPTIONS *u);
