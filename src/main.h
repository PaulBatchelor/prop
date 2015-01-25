#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

#define PRP_MULT_SIZE 20
#define PRP_DATA_SIZE 100



#define PRP_REST 0
#define PRP_NOTE 1
#define prp_add_note(DATA) prp_add(DATA, PRP_NOTE)
#define prp_add_rest(DATA) prp_add(DATA, PRP_REST)


typedef char PRP_EVENT_TYPE;
typedef struct {
PRP_EVENT_TYPE type;
long data;
}PRP_EVENT;


typedef struct {
int foo;
long mul;
long lcm;
int mult_size;
int data_size;
int bpm;
double duration;
double ts;
long *mult;
PRP_EVENT *events;
/*TODO change the name of total_dur to something more relevant*/
double total_dur;
}PRP_DATA;

PRP_DATA *PRP_GD;


int prp_create(PRP_DATA **d);
int prp_init(PRP_DATA *d);
int prp_destroy(PRP_DATA **d);
int prp_add(PRP_DATA *d, PRP_EVENT_TYPE type);
int prp_mul(PRP_DATA *d, int n);
int prp_return(PRP_DATA *d);
int prp_process(PRP_DATA *d);
int prp_print(PRP_DATA *d);
int prp_calc_totaldur(PRP_DATA *d);
