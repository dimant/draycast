#include <stdio.h>

#include "projectile.h"

int main(int argc, char** argv)
{
	point position = new_point(0, 1, 0);
	vec velocity = vec_norm(new_vec(1, 1.8, 0));

	vec gravity = new_vec(0, -0.1, 0);
	vec wind = new_vec(-0.01, 0, 0);

	while (position.y > 0)
	{
		projectile_tick(&position, &velocity, gravity, wind);
		printf("Position: (%f, %f, %f)\n", position.x, position.y, position.z);
	}

	return 0;
}
