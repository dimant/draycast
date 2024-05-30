#include <math.h>
#include "tuple.h"

tuple tuple_new(num x, num y, num z, num w) {
    tuple t = {x, y, z, w};
    return t;
}

tuple new_point(num x, num y, num z) {
	return tuple_new(x, y, z, 1.0);
}

tuple new_vec(num x, num y, num z) {
	return tuple_new(x, y, z, 0.0);
}

color new_color(num r, num g, num b) {
	return tuple_new(r, g, b, 0.0);
}

bool is_point(tuple t) {
    return t.w == 1.0;
}

bool is_vec(tuple t) {
    return t.w == 0.0;
}

inline bool num_eq(num a, num b) {
    return fabs(a - b) < EPSILON;
}

bool tuple_eq(tuple a, tuple b) {
    return num_eq(a.x, b.x) && num_eq(a.y, b.y) && num_eq(a.z, b.z) && num_eq(a.w, b.w);
}

tuple tuple_add(tuple a, tuple b) {
    return tuple_new(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

tuple tuple_sub(tuple a, tuple b) {
    return tuple_new(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

tuple tuple_neg(tuple a) {
    return tuple_new(-a.x, -a.y, -a.z, -a.w);
}

tuple tuple_mul_scalar(tuple a, num b) {
    return tuple_new(a.x * b, a.y * b, a.z * b, a.w * b);
}

tuple tuple_div_scalar(tuple a, num b) {
    return tuple_new(a.x / b, a.y / b, a.z / b, a.w / b);
}

num vec_mag(vec a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}

vec vec_norm(vec a) {
    num mag = vec_mag(a);
    return tuple_div_scalar(a, mag);
}

num vec_dot(vec a, vec b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

vec vec_cross(vec a, vec b) {
    return new_vec(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x);
}

color color_mul(color a, color b) {
	return tuple_new(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}
