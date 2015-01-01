#include "main.h"

#define PRP_MULT_SIZE 20
#define PRP_DATA_SIZE 50

int prp_create(PRP_DATA **d)
{
    *d = (PRP_DATA *)malloc(sizeof(PRP_DATA));
    PRP_DATA *data;
    data = *d;
    data->res = 1;
    data->mult_size = 1;
    data->data_size = 0;
    data->mult = (long*)malloc(sizeof(long) * PRP_MULT_SIZE);
    data->mult[0] = 1;
    data->data = (long*)malloc(sizeof(long) * PRP_DATA_SIZE);
    data->data[0] = -1;
    data->max_res = 1;
    return 1;
}
int prp_destroy(PRP_DATA **d)
{
    free((*d)->mult);
    free(*d);
    return 1;
}
int prp_add(PRP_DATA *d)
{
    /*Check and see if there is space on stack */
    if(d->data_size > PRP_DATA_SIZE) 
    {
        fprintf(stderr, "ERROR: stack overflow\n");
        return 0;
    }
   
    d->data_size++;

    d->data[d->data_size - 1] = d->res;

    return 1;
}
int prp_mul(PRP_DATA *d, int n)
{
    if(d->mult_size > PRP_MULT_SIZE) 
    {
        fprintf(stderr, "ERROR: stack overflow\n");
        return 0;
    }
    d->mult_size++;
    d->mult[d->mult_size - 1] = n;

    if(d->res % n != 0) {
        prp_genres(d);
    }
    return 1;
}
int prp_return(PRP_DATA *d)
{
    d->mult_size--;
    prp_genres(d);
    return 1;
}

int prp_genres(PRP_DATA *d)
{
    int i;
    if(d->res > d->max_res) d->max_res = d->res;
    d->res = 1;
    for(i = 0; i < d->mult_size; i++)
    {
        d->res *= d->mult[i];
    }
    return 1;
}

int prp_process(PRP_DATA *d)
{
    int i;
    for(i = 0; i < d->data_size; i++)
    {
        d->data[i] = d->max_res / d->data[i];
    }
    return 1;
}
