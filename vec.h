#ifndef VEC_H
#define VEC_H

struct vec_struct
{
    float x;
    float y;
    float z;
};

typedef struct vec_struct vec;

#define VEC_ARR(v) ((float *)&v)

vec vec_create(float x, float y, float z);

vec vec_add(vec a, vec b);

vec vec_sub(vec a, vec b);

vec vec_mul(vec a, vec b);

vec vec_mul_scalar(vec a, float scalar);

vec vec_div_scalar(vec a, float scalar);

float vec_length(vec a);

float vec_squared(vec a);

float vec_dot(vec a, vec b);

void vec_print(vec a);

#endif // VEC_H