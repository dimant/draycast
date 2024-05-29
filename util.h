#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

#include "image.h"

#define BOOL char
#define TRUE 1
#define FALSE 0

void ppm_write(
    FILE *file,
    const image img);

void print_progress(
    const unsigned int progress,
    const unsigned int total);

void fill_test_image(image img);

#endif