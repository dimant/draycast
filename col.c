#include "col.h"

void col_write(FILE *file, const col c)
{
    int ir = (int)(((num)255.999) * c.r);
    int ig = (int)(((num)255.999) * c.g);
    int ib = (int)(((num)255.999) * c.b);

    fprintf(file, "%d %d %d\n", ir, ig, ib);
}