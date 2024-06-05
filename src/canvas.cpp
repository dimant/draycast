#include "canvas.h"

Canvas::Canvas(int width, int height)
{
    this->width = width;
    this->height = height;
    this->pixels = new Tuple[width * height];
}

Canvas::~Canvas()
{
    delete[] pixels;
}

void Canvas::clear()
{
    for (int i = 0; i < width * height; i++)
    {
        pixels[i] = Tuple(0, 0, 0, 0);
    }
}

void Canvas::set_pixel(int x, int y, const Tuple &c)
{
    pixels[y * width + x] = Tuple(c.x, c.y, c.z, c.w);
}

Tuple Canvas::get_pixel(int x, int y) const
{
    return pixels[y * width + x];
}