#ifndef RAY_H
#define RAY_H

#include "vec.h"

struct ray_struct
{
    vec origin;
    vec direction;
};

typedef struct ray_struct ray;

ray ray_create(const vec origin, const vec direction);

point ray_point_at(const ray r, const float t);

#endif // RAY_H