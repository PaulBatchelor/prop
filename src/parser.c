#include "main.h"
#include "parser.h"
#include "gen_ps.h"

int main(int argc, char **argv)
{
    int c;
    PRP_PS_OPTIONS p;
    prp_init_ps_options(&p);
    PRP_PARSER_INIT;
    while((c = getopt(argc, argv, "t:d:p:")) != -1 )
    {
    switch(c)
    {
    case 't':
        prp_setvar(ts,atof(optarg));
        prp_setvar(user_ts, TRUE);
    break;
    case 'd':
        prp_setvar(duration,atof(optarg));
        prp_setvar(user_ts, FALSE);
        prp_setvar(user_duration, TRUE);
    break;
    case 'p':
        prp_setvar(write_ps, TRUE);
        free(p.filename);
        p.filename = optarg;
    break;
    case '?':
        return 0;
    }
    }
    do{
        yyparse();
    }while(!feof(yyin)) ;
    prp_process(PRP_GD);
    prp_print(PRP_GD); 
    //prp_gen_ps(PRP_GD, &p);
    GEN_PS(&p);

    PRP_PARSER_DESTROY;
    return 0;
}

int prp_create_user_options(PRP_USER_OPTIONS *u)
{
    u->user_ts = FALSE;
    u->user_duration = FALSE;
    u->write_ps= FALSE;
}
int prp_init_with_options(PRP_DATA *d, PRP_USER_OPTIONS *u)
{
    if(u->user_ts == TRUE) { d->ts = u->ts; }
    if(u->user_duration == TRUE) { d->duration = u->duration; }
    return 1;
}
