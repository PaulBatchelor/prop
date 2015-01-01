#include <stdio.h>
#include <stdlib.h>
#define PRP_MULT_SIZE 20
#define PRP_DATA_SIZE 50
#define PRP_REST 0
#define PRP_NOTE 1
#define prp_add_rest(DATA) prp_add(DATA, PRP_REST)
#define prp_add_note(DATA) prp_add(DATA, PRP_NOTE)

typedef char PRP_EVENT_TYPE;
typedef struct {
PRP_EVENT_TYPE type;
long data;
}PRP_EVENT;

typedef struct {
int foo;
long res;
int max_res;
int mult_size;
int data_size;
int bpm;
double ts;
long *mult;
long *data;
PRP_EVENT *events;
}PRP_DATA;

PRP_DATA *PRP_GD;

int prp_create(PRP_DATA **d);
int prp_destroy(PRP_DATA **d);
int prp_add(PRP_DATA *d, PRP_EVENT_TYPE type);
int prp_mul(PRP_DATA *d, int n);
int prp_return(PRP_DATA *d);
int prp_process(PRP_DATA *d);
int prp_print(PRP_DATA *d);
