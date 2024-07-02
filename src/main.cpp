#include <iostream>

#include "matrix.h"
#include "ppm.h"

int gravity()
{
    Canvas c(900, 550);

    Tuple position(0, 1, 0, 1);
    Tuple velocity = Tuple(1, 1.8, 0, 0).norm() * 11.25;

    Tuple gravity(0, -0.1, 0, 0);
    Tuple wind(-0.01, 0, 0, 0);

    while (position.y > 0)
    {
        position = position + velocity;
        velocity = velocity + gravity + wind;
        if (position.x >= 0 && position.x < c.get_width() && (int)position.y >= 0 && c.get_height() - (int)position.y < c.get_height())
        {
            c.set_pixel((int)position.x, c.get_height() - (int)position.y, Tuple(1, 0, 0, 1));
            // std::cout << "Position: (" << position.x << ", " << position.y << ", " << position.z << ")\n";
        }
    }

    PPM ppm;
    FileOutputStream fos("output.ppm");

    ppm.write_canvas(fos, c);

    return 0;
}

int main()
{
    Canvas c(900, 550);
    Tuple red = Tuple::color(1.0f, 0.0f, 0.0f);
    Tuple green = Tuple::color(0.0f, 1.0f, 0.0f);
    Tuple center = Tuple::point(c.get_width() / 2.0f, c.get_height() / 2.0f, 0.0f);
    Tuple position = Tuple::point(center.x, center.y + (c.get_height() / 5), 0.0f);

    // when chaining, the order of operations is reversed
    Matrix<4> transform = Matrix<4>::identity()
        .translate(center.x, center.y, 0.0f)        // translate to center
        .rotate_z(M_PI / 6.0f)                      // rotate 30 degrees
        .translate(-center.x, -center.y, 0.0f);     // translate to origin

    for (int i = 0; i < 12; i++)
    {
        position = transform * position;

        c.set_pixel(position.x, position.y, red);
        c.set_pixel(position.x - 1, position.y, red);
        c.set_pixel(position.x, position.y - 1, red);
        c.set_pixel(position.x + 1, position.y, red);
        c.set_pixel(position.x, position.y + 1, red);
    }

    PPM ppm;
    FileOutputStream fos("output.ppm");

    ppm.write_canvas(fos, c);

    return 0;
}