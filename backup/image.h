#ifndef IMAGE_H
#define IMAGE_H

#include <stdlib.h>

#include "color.h"

struct image_struct
{
    unsigned int width;
    unsigned int height;
    color *pixels;
};

typedef struct image_struct image;

image image_create(const unsigned int width, const unsigned int height);

void image_free(image i);

#endif