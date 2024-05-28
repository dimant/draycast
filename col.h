#ifndef COL_H
#define COL_H

#include <stdio.h>

#include "num.h"

struct col_struct
{
    num r;
    num g;
    num b;
};

typedef struct col_struct col;

#define COL_ARR(c) ((num *)&c)

void col_write(FILE *file, const col c);

#endif