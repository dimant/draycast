#ifndef CANVAS_H
#define CANVAS_H

#include "tuple.h"

typedef struct {
    int width;
    int height;
    color* pixels;
} canvas;

canvas *new_canvas(int width, int height);

void free_canvas(canvas **c);

void clear_canvas(canvas *c);

color canvas_pixel_at(canvas *c, int x, int y);

void canvas_write_pixel(canvas *c, int x, int y, color color);

#endif
