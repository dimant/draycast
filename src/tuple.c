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
