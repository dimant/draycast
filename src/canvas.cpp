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

void Canvas::set_pixel(int x, int y, float r, float g, float b)
{
    pixels[y * width + x] = Tuple(r, g, b, 0);
}

Tuple Canvas::get_pixel(int x, int y) const
{
    return pixels[y * width + x];
}