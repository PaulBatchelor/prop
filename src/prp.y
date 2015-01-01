%{
#include "prp_parser.h"
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
%expect 2

%%

main: init body end   ;

body: patterns;


patterns: pattern | patterns pattern ;
pattern: mul pattern close | events;

events: event | events event 
;

event : event_rest | event_note 
;

mul: NUMBER LPAREN { 
    prp_mul(PRP_GD, $1); 
    #ifdef DEBUG_BISON
    fprintf(stderr,"MUL %d\n", $1);
    #endif
};
close: RPAREN { 
    prp_return(PRP_GD); 
    #ifdef DEBUG_BISON
    fprintf(stderr,"RETURN\n");
    #endif
};
      ;
event_rest: REST { 
    prp_add_rest(PRP_GD); 
    #ifdef DEBUG_BISON
    fprintf(stderr,"ADD_REST\n");
    #endif
};
event_note: NOTE { 
    prp_add_note(PRP_GD); 
    #ifdef DEBUG_BISON
    fprintf(stderr,"ADD_NOTE\n");
    #endif
};
init : LBRAC { 
    prp_create(&PRP_GD); 
    #ifdef DEBUG_BISON
    fprintf(stderr,"INIT\n");
    #endif
};
end : RBRAC { 
    prp_destroy(&PRP_GD); 
    #ifdef DEBUG_BISON
    fprintf(stderr,"END\n");
    #endif
};

%%

void yyerror(const char *s)
{
    fprintf(stderr, "%s: sorry this can't be more useful\n", s);
    prp_destroy(&PRP_GD); 
}
