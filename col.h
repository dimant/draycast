#ifndef COL_H
#define COL_H

#include <stdio.h>

struct col_struct
{
    float r;
    float g;
    float b;
};

typedef struct col_struct col;

#define COL_ARR(c) ((float *)&c)

void col_write(FILE *file, const col c);

#endif