#ifdef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

struct hit_struct
{
    point p;
    vec normal;
    num t;
};

struct hittable_struct
{
    void *object;
    num (*hit)(void *object, const ray r, const num t_min, const num t_max, hit *h);
};

#endif