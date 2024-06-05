#ifndef CANVAS_H
#define CANVAS_H

#include "tuple.h"

class Canvas
{
private:
    int width;
    int height;
    Tuple *pixels;

public:
    Canvas(int width, int height);
    ~Canvas();

    int get_width() const { return width; }
    int get_height() const { return height; }

    void clear();
    void set_pixel(int x, int y, float r, float g, float b);
    Tuple get_pixel(int x, int y) const;
};

#endif