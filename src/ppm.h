#ifndef PPM_H
#define PPM_H

#include <stdio.h>
#include <stdarg.h>

#include "canvas.h"
#include "tuple.h"

void ppm_write_header(FILE *file, int width, int height);

void ppm_reset_line();

void ppm_write_pixel(FILE *file, color c);

void ppm_write_footer(FILE *file);

void ppm_write_canvas(FILE *file, canvas *c);

#endif
