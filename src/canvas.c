#include <stdlib.h>
#include <string.h>

#include "canvas.h"

canvas *new_canvas(int width, int height) {
	canvas *c = malloc(sizeof(canvas));

	c->width = width;
	c->height = height;
	c->pixels = malloc(width * height * sizeof(color));

	clear_canvas(c);

	return c;
}

void free_canvas(canvas **c) {
	free((*c)->pixels);
	free(*c);
}

void clear_canvas(canvas *c) {
	memset(c->pixels, 0, c->width * c->height * sizeof(color));
}

color canvas_pixel_at(canvas *c, int x, int y) {
	return c->pixels[y * c->width + x];
}

void canvas_write_pixel(canvas *c, int x, int y, color col) {
	c->pixels[y * c->width + x] = col;
}
