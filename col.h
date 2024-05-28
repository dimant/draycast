#ifndef COL_H
#define COL_H

struct col_struct
{
    float r;
    float g;
    float b;
};

typedef struct col_struct col;

#define COL_ARR(c) ((float *)&c)

void col_print(const col c);

#endif