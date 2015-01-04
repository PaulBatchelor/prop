#include "main.h"


int prp_create(PRP_DATA **d)
{
    *d = (PRP_DATA *)malloc(sizeof(PRP_DATA));
    return 1;
}

int prp_init(PRP_DATA *d)
{
    d->mul = 1;
    d->mult_size = 1;
    d->data_size = 0;
    d->mult = (long*)malloc(sizeof(long) * PRP_MULT_SIZE);
    d->mult[0] = 1;
    d->events = (PRP_EVENT*)malloc(sizeof(PRP_EVENT) * PRP_DATA_SIZE);
    d->events[0].data = -1;
    d->lcm = 1;
    d->ts = 1.0;
    d->bpm = 120;
    d->duration = 5.0;
    d->total_dur = 0.0;
    return 1;
}

int prp_destroy(PRP_DATA **d)
{
    free((*d)->mult);
    //free((*d)->data);
    free((*d)->events);
    free(*d);
    return 1;
}
int prp_add(PRP_DATA *d, PRP_EVENT_TYPE type)
{
    /*Check and see if there is space on stack */
    if(d->data_size > PRP_DATA_SIZE) 
    {
        fprintf(stderr, "ERROR: stack overflow\n");
        return 0;
    }
   
    d->data_size++;

    d->events[d->data_size - 1].data = d->mul;
    d->events[d->data_size - 1].type = type;

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

    /*TODO fix LCM algorithm issue */
    //if(d->mul % n != 0) {
        prp_genres(d);
    //}
    if(d->lcm % d->mul != 0){
        d->lcm *= n;
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
    d->mul = 1;
    for(i = 0; i < d->mult_size; i++)
    {
        d->mul *= d->mult[i];
    }
    if(d->mul > d->lcm) d->lcm = d->mul;
    return 1;
}

int prp_process(PRP_DATA *d)
{
    int i;
    for(i = 0; i < d->data_size; i++)
    {
        d->events[i].data = d->lcm / d->events[i].data;
    }
    return 1;
}

int prp_calc_totaldur(PRP_DATA *d)
{
    d->total_dur = 0;
    int i;
    for(i = 0; i < d->data_size; i++)
    {
        d->total_dur += d->events[i].data;
    }
    return 1;
}

int prp_print(PRP_DATA *d)
{
    double t = 0;
    int i;
    double dur;

    prp_calc_totaldur(d); /* call this function before calculating timescale */
    if(d->total_dur > 0)
    {
    d->ts = d->duration / d->total_dur;
    }else
    {
    fprintf(stderr, "WARNING: total_dur is zero!\n");
    }
    for(i = 0; i < d->data_size; i++)
    {
        dur = d->events[i].data * d->ts;
        if(d->events[i].type != PRP_REST) {
            fprintf(stdout, "%g %g\n", t, dur);
        }
        t += dur;
    }
}
