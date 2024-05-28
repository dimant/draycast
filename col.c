#include "col.h"

void col_write(FILE *file, const col c)
{
    int ir = (int)(255.999f * c.r);
    int ig = (int)(255.999f * c.g);
    int ib = (int)(255.999f * c.b);

    fprintf(file, "%d %d %d\n", ir, ig, ib);
}