#include "ppm.h"

void PPM::write_header(OutputStream &str, const int &width, const int &height)
{
    str << "P3\n"
        << std::to_string(width) << " " << std::to_string(height) << "\n"
        << "255\n";
}

void PPM::write_pixel(OutputStream &str, const Tuple &c)
{
    int ir = (int)((255.999) * c.x);
    int ig = (int)((255.999) * c.y);
    int ib = (int)((255.999) * c.z);

    if (pixels_on_line < 4)
    {
        if (pixels_on_line > 0)
        {
            str << " ";
        }

        str << std::to_string(ir) << " "
            << std::to_string(ig) << " "
            << std::to_string(ib);
        pixels_on_line++;
    }
    else
    {
        str << "\n"
            << std::to_string(ir) << " "
            << std::to_string(ig) << " "
            << std::to_string(ib);
        pixels_on_line = 1;
    }
}

void PPM::write_footer(OutputStream &str)
{
    str << "\n";
}

void PPM::write_canvas(OutputStream &str, const Canvas &c)
{
    write_header(str, c.get_width(), c.get_height());

    for (int j = 0; j < c.get_height(); j++)
    {
        for (int i = 0; i < c.get_width(); i++)
        {
            write_pixel(str, c.get_pixel(i, j));
        }
    }

    write_footer(str);
}