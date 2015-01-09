#include <stdio.h>
#include "../main.h"
#include "../gen_ps.h"
#include "../testing.h"

#define TEST(var,varstr,val) if(var != val){\
        asprintf(&ERROR_STRING, "Error! %s should be initialized at %d, but it is %d\n", \
                varstr, val, var);\
        prp_error(ERROR_STRING);\
        free(ERROR_STRING);\
        return 0;\
    }

char *ERROR_STRING;


int test_prp_init_ps_options(PRP_PS_OPTIONS *p)
{
    prp_init_ps_options(p);
    TEST(p->h,"p->h (height)",100);
    TEST(p->w,"p->w (width)",400);
    TEST(p->border,"p->border (border)",10);
    return 1;
}

int main()
{
    PRP_PS_OPTIONS p;
    if(test_prp_init_ps_options(&p))
    {
        prp_success("test_prp_init test passed!\n");
    }else{
        prp_error("test_prp_init test failed:(\n");
    }
    return 0;
}
