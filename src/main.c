#include <stdio.h>

#include "projectile.h"
#include "canvas.h"
#include "ppm.h"

int main(int argc, char **argv)
{
    canvas *c = new_canvas(900, 550);

    point position = new_point(0, 1, 0);
    vec velocity = tuple_mul_scalar(vec_norm(new_vec(1, 1.8, 0)), 11.25);

    vec gravity = new_vec(0, -0.1, 0);
    vec wind = new_vec(-0.01, 0, 0);

    while (position.y > 0)
    {
        projectile_tick(&position, &velocity, gravity, wind);
        if (position.x >= 0 && position.x < c->width && (int)position.y >= 0 && c->height - (int)position.y < c->height)
        {
            canvas_write_pixel(c, (int)position.x, c->height - (int)position.y, new_color(1, 0, 0));
            printf("Position: (%f, %f, %f)\n", position.x, position.y, position.z);
        }
    }

    FILE *f = fopen("output.ppm", "w");

    ppm_write_canvas(f, c);

    return 0;
}
