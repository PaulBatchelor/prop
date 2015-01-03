typedef struct
{
double r, g, b;
}PRP_COLOR;
typedef struct 
{
PRP_COLOR line_color;
PRP_COLOR line_faded_color;
PRP_COLOR bg_color;
char *filename;
int h, w, border;
}PRP_PS_OPTIONS;


int prp_init_ps_options(PRP_PS_OPTIONS *p);
int prp_gen_ps(PRP_DATA *d, PRP_PS_OPTIONS *p);

