%{
#include "main.h"
#include "parser.h"
%}

%union {
int ival;
char *sval;
}
%token<ival> NUMBER
%token LPAREN 
%token RPAREN 
%token NOTE 
%token REST 
%token LBRAC 
%token RBRAC 
%token ERROR
/* I don't know how to get rid of these otherwise */
%expect 5
%%

rhythm: init body end   ;

/* these three lines cause 5 shift/reduce conflicts, supressing with %expect 5 */
body: | divisions; 
divisions: division | divisions division; 
division: events | mul events close | mul divisions close;


events: event | events event 
;

event : event_rest | event_note 
;

mul: NUMBER LPAREN { 
    prp_mul(PRP_GD, $1); 
    if(DEBUG_BISON)
    fprintf(stderr,"MUL %d\n", $1);
};
close: RPAREN { 
    prp_return(PRP_GD); 
    if(DEBUG_BISON)
    fprintf(stderr,"RETURN\n");
};
      ;
event_rest: REST { 
    prp_add_rest(PRP_GD); 
    if(DEBUG_BISON)
    fprintf(stderr,"ADD_REST\n");
};
event_note: NOTE { 
    prp_add_note(PRP_GD); 
    if(DEBUG_BISON)
    fprintf(stderr,"ADD_NOTE\n");
};
init : LBRAC { 
    //prp_create(&PRP_GD); 
    prp_init(PRP_GD);
    prp_init_with_options(PRP_GD, &PRP_UO);
    if(DEBUG_BISON)
    fprintf(stderr,"INIT\n");
};
end : RBRAC { 
    if(DEBUG_BISON)
    fprintf(stderr,"END\n");
};

%%

void yyerror(const char *s)
{
    fprintf(stderr, "%s: sorry this can't be more useful\n", s);
    prp_destroy(&PRP_GD); 
}
