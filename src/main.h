#include <stdio.h>
#include <stdlib.h>
typedef struct {
int foo;
long res;
int max_res;
int mult_size;
int data_size;
long *mult;
long *data;
}PRP_DATA;

int prp_create(PRP_DATA **d);
int prp_destroy(PRP_DATA **d);
int prp_add(PRP_DATA *d);
int prp_mul(PRP_DATA *d, int n);
int prp_return(PRP_DATA *d);
int prp_process(PRP_DATA *d);
