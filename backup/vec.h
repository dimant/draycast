#ifndef VEC_H
#define VEC_H

#include "num.h"

struct vec_struct
{
    num x;
    num y;
    num z;
};

typedef struct vec_struct vec;

typedef struct vec_struct point;

#define VEC_ARR(v) ((num *)&v)

vec vec_create(const num x, const num y, const num z);

vec vec_add(const vec a, const vec b);

vec vec_sub(const vec a, const vec b);

vec vec_mul(const vec a, const vec b);

vec vec_mul_scalar(const vec a, const num scalar);

vec vec_div_scalar(const vec a, const num scalar);

num vec_length(const vec a);

num vec_length_squared(const vec a);

num vec_dot(const vec a, const vec b);

vec vec_cross(const vec a, const vec b);

vec vec_unit(const vec a);

void vec_print(const vec a);

#endif // VEC_H