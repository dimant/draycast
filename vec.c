#include <math.h>
#include <stdio.h>

#include "vec.h"

vec vec_create(float x, float y, float z)
{
    vec v = {x, y, z};
    return v;
}

vec vec_add(vec a, vec b)
{
    vec v = {a.x + b.x, a.y + b.y, a.z + b.z};
    return v;
}

vec vec_sub(vec a, vec b)
{
    vec v = {a.x - b.x, a.y - b.y, a.z - b.z};
    return v;
}

vec vec_mul(vec a, vec b)
{
    vec v = {a.x * b.x, a.y * b.y, a.z * b.z};
    return v;
}

vec vec_mul_scalar(vec a, float scalar)
{
    vec v = {a.x * scalar, a.y * scalar, a.z * scalar};
    return v;
}

vec vec_div_scalar(vec a, float scalar)
{
    vec v = {a.x / scalar, a.y / scalar, a.z / scalar};
    return v;
}

float vec_length(vec a)
{
    return sqrt(vec_squared(a));
}

float vec_squared(vec a)
{
    return a.x * a.x + a.y * a.y + a.z * a.z;
}

float vec_dot(vec a, vec b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

void vec_print(vec a)
{
    printf("(%f %f %f)\n", a.x, a.y, a.z);
}