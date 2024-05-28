#ifndef VEC_H
#define VEC_H

struct vec_struct
{
    float x;
    float y;
    float z;
};

typedef struct vec_struct vec;

typedef struct vec_struct point;

#define VEC_ARR(v) ((float *)&v)

vec vec_create(const float x, const float y, const float z);

vec vec_add(const vec a, const vec b);

vec vec_sub(const vec a, const vec b);

vec vec_mul(const vec a, const vec b);

vec vec_mul_scalar(const vec a, const float scalar);

vec vec_div_scalar(const vec a, const float scalar);

float vec_length(const vec a);

float vec_squared(const vec a);

float vec_dot(const vec a, const vec b);

vec vec_cross(const vec a, const vec b);

vec vec_unit(const vec a);

void vec_print(const vec a);

#endif // VEC_H