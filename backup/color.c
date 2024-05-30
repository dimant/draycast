#include "color.h"

color color_create(const num r, const num g, const num b)
{
    color c = {r, g, b};
    return c;
}

void color_write(FILE *file, const color c)
{
    int ir = (int)(((num)255.999) * c.r);
    int ig = (int)(((num)255.999) * c.g);
    int ib = (int)(((num)255.999) * c.b);

    fprintf(file, "%d %d %d\n", ir, ig, ib);
}