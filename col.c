#include <stdio.h>

#include "col.h"

void col_print(const col c)
{
    int ir = (int)(255.999f * c.r);
    int ig = (int)(255.999f * c.g);
    int ib = (int)(255.999f * c.b);

    printf("%d %d %d\n", ir, ig, ib);
}