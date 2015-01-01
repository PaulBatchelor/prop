#include "prp_parser.h"

int main(int argc, char **argv)
{
    //printf("Prop version 0.1\n");
    //yylex();
    int c;
    //while((c = getopt(argc, argv, "t:")) != -1 )
    //{
    //    switch(c)
    //    {
    //        case 't':
    //            PRP_GD->ts = atof(optarg);
    //        break;
    //    }
    //}
    do{
        yyparse();
    }while(!feof(yyin)) ;
    prp_process(PRP_GD);
    prp_print(PRP_GD);    
    return 0;
}
