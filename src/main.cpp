#include <iostream>

#include "ppm.h"

int main()
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