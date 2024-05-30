#include <math.h>
#include "tuple.h"

tuple tuple_new(num x, num y, num z, num w) {
    tuple t = {x, y, z, w};
    return t;
}

tuple new_point(num x, num y, num z) {
	return tuple_new(x, y, z, 1.0);
}

tuple new_vector(num x, num y, num z) {
	return tuple_new(x, y, z, 0.0);
}

bool is_point(tuple t) {
    return t.w == 1.0;
}

bool is_vector(tuple t) {
    return t.w == 0.0;
}

bool num_eq(num a, num b) {
    return fabs(a - b) < EPSILON;
}

bool tuple_eq(tuple a, tuple b) {
    return num_eq(a.x, b.x) && num_eq(a.y, b.y) && num_eq(a.z, b.z) && num_eq(a.w, b.w);
}
