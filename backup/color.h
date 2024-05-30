#ifndef COLOR_H
#define COLOR_H

#include <stdio.h>

#include "num.h"

struct color_struct
{
    num r;
    num g;
    num b;
};

typedef struct color_struct color;

#define COL_ARR(c) ((num *)&c)

#define COL_VEC(c) *(vec *)(&c)

#define VEC_COL(v) *(color *)(&v)

color color_create(const num r, const num g, const num b);

void color_write(FILE *file, const color c);

#endif