#include "main.h"
#include "parser.h"
#include "gen_ps.h"

int main(int argc, char **argv)
{
    int c;
    PRP_PS_OPTIONS p;
    prp_init_ps_options(&p);
    PRP_PARSER_INIT;
    while((c = getopt(argc, argv, "t:d:")) != -1 )
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
    }
    }
    do{
        yyparse();
    }while(!feof(yyin)) ;
    prp_process(PRP_GD);
    prp_print(PRP_GD); 
 
    //prp_gen_ps(PRP_GD, &p);

    /*TODO: figure out how to free PRP_GD */
    //free(PRP_GD);
    return 0;
}
