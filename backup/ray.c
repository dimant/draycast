#include "ray.h"

ray ray_create(const vec origin, const vec direction)
{
    ray r = {origin, direction};
    return r;
}

point ray_point_at(const ray r, const float t)
{
    return vec_add(r.origin, vec_mul_scalar(r.direction, t));
}