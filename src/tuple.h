#ifndef TUPLE_H
#define TUPLE_H

#include <stdbool.h>

typedef float num;

typedef struct {
    num x;
    num y;
    num z;
	num w;
} tuple;

tuple new_point(num x, num y, num z);

tuple new_vector(num x, num y, num z);

bool is_point(tuple t);

bool is_vector(tuple t);

#endif
