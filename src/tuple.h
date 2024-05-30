#ifndef TUPLE_H
#define TUPLE_H

#include <stdbool.h>

#define EPSILON 0.00001

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

bool num_eq(num a, num b);

bool tuple_eq(tuple a, tuple b);

tuple tuple_add(tuple a, tuple b);

tuple tuple_sub(tuple a, tuple b);

tuple tuple_neg(tuple a);

tuple tuple_mul_scalar(tuple a, num b);

tuple tuple_div_scalar(tuple a, num b);

num vector_mag(tuple a);

tuple vector_norm(tuple a);

#endif
