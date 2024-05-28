#include <math.h>
#include <stdio.h>

#include "vec.h"

vec vec_create(const num x, const num y, const num z)
{
    vec v = {x, y, z};
    return v;
}

vec vec_add(const vec a, const vec b)
{
    vec v = {a.x + b.x, a.y + b.y, a.z + b.z};
    return v;
}

vec vec_sub(const vec a, const vec b)
{
    vec v = {a.x - b.x, a.y - b.y, a.z - b.z};
    return v;
}

vec vec_mul(const vec a, const vec b)
{
    vec v = {a.x * b.x, a.y * b.y, a.z * b.z};
    return v;
}

vec vec_mul_scalar(const vec a, const num scalar)
{
    vec v = {a.x * scalar, a.y * scalar, a.z * scalar};
    return v;
}

vec vec_div_scalar(const vec a, const num scalar)
{
    vec v = {a.x / scalar, a.y / scalar, a.z / scalar};
    return v;
}

num vec_length(const vec a)
{
    return sqrt(vec_squared(a));
}

num vec_squared(const vec a)
{
    return a.x * a.x + a.y * a.y + a.z * a.z;
}

num vec_dot(const vec a, const vec b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec vec_cross(const vec a, const vec b)
{
    vec v = {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x};

    return v;
}

vec vec_unit(const vec a)
{
    return vec_div_scalar(a, vec_length(a));
}

void vec_print(const vec a)
{
    printf("(%f %f %f)\n", a.x, a.y, a.z);
}