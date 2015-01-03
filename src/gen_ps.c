#include <math.h>
#include "main.h"
#include "gen_ps.h"


void prp_set_rgb(PRP_COLOR *c, char r, char g, char b)
{
    c->r = (r == 0) ? 0 : r / 255.0; 
    c->g = (g == 0) ? 0 : g / 255.0; 
    c->b = (b == 0) ? 0 : b / 255.0; 
}

int prp_init_ps_options(PRP_PS_OPTIONS *p)
{
    prp_set_rgb(&p->line_color, 0, 0, 0);
    prp_set_rgb(&p->line_faded_color, 220, 220, 220);
    prp_set_rgb(&p->bg_color, 255, 255, 255);
    /* TODO be sure to free this */
    asprintf(&p->filename, "out.ps");
    p->h = 100;
    p->w = 400;
    p->border = 10;
    return 1;
}


/* TODO finish this function */
int prp_gen_ps(PRP_DATA *d, PRP_PS_OPTIONS *p)
{
    FILE *fp = fopen(p->filename, "w");
    int lwidth = p->h - 2 * p->border;
    double incr;
    int i;
    if(d->total_dur > 0)
    {
        incr = 1.0 * (p->w - 2 * p->border) / d->total_dur;
    }else
    {
        fprintf(stderr, "WARNING: total_dur is zero!\n");
    }

    fprintf(fp,"%!PS\n");
    fprintf(fp,"%%BoundingBox: 0 0 %d %d\n", p->w, p->h);
    fprintf(fp,"/lineWidth %d def\n", lwidth);
    fprintf(fp,"/line\n");
    fprintf(fp,"newpath\n");
    fprintf(fp,"0 0 moveto\n");
    fprintf(fp,"0 lineWidth lineto\n");
    fprintf(fp,"}def \n");
    fprintf(fp,"2 setlinewidth \n");
    fprintf(fp,"%d %d translate\n", p->border, p->border);
    /* TODO (maybe?) build an interator function for the array*/
    for(i = 0; i < d->data_size; i++)
    {
        if(d->events[i].type == PRP_NOTE) {
            fprintf(fp, "%d %g %g %g setrgbcolor\n", d->events[i].type,
                    p->line_color.r, p->line_color.g, p->line_color.b);
        }else{
            fprintf(fp, "%d %g %g %g setrgbcolor\n", d->events[i].type,
                    p->line_faded_color.r, p->line_faded_color.g, 
                    p->line_faded_color.b);
        }
       
    }

    fclose(fp);
    return 1;
}
