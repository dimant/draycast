#include "util.h"

image image_create(const unsigned int width, const unsigned int height)
{
    image i = {width, height, (color *)malloc(width * height * sizeof(color))};
    return i;
}

void image_free(image i)
{
    free(i.pixels);
}

void ppm_write(
    FILE *file,
    const image img)
{
    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", img.width, img.height);
    fprintf(file, "255\n");

    for (int pixel = 0; pixel < img.width * img.height; pixel++)
    {
        color_write(file, img.pixels[pixel]);
    }

    fclose(file);
}

void print_progress(const unsigned int progress, const unsigned int total)
{
    const int barWidth = 70;
    const num percentage = (num)progress / total;
    const int pos = barWidth * percentage;

    printf("[");
    for (int i = 0; i < barWidth; ++i)
    {
        if (i < pos)
            printf("=");
        else if (i == pos)
            printf(">");
        else
            printf(" ");
    }
    printf("] %d%%\r", (int)(percentage * 100));
    fflush(stdout);
}

void fill_test_image(image img)
{
    for (int row = 0; row < img.height; row++)
    {
        print_progress(row, img.height);
        for (int col = 0; col < img.width; col++)
        {
            int pixel = row * img.width + col;
            double r = (double)row / (img.width - 1);
            double g = (double)col / (img.height - 1);
            double b = 0.0;

            img.pixels[pixel].r = r;
            img.pixels[pixel].g = g;
            img.pixels[pixel].b = b;
        }
    }
}