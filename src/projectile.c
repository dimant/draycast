#include "projectile.h"

void projectile_tick(point *position, vec *velocity, vec gravity, vec wind) {

	*position = tuple_add(*position, *velocity);
	*velocity = tuple_add(tuple_add(*velocity, gravity), wind);
}
