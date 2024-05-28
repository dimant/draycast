#include <stdio.h>

#include "num.h"
#include "col.h"

void write_ppm(
    const char *fname,
    const num *image,
    const unsigned int width,
    const unsigned int height)
{
    FILE *file = fopen(fname, "w");

    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "255\n");

    for (int pixel = 0; pixel < width * height; pixel++)
    {
        col *color = (col *)&image[pixel * 3];
        col_write(file, *color);
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

void fill_test_image(num *image, const unsigned int width, const unsigned int height)
{
    for (int row = 0; row < height; row++)
    {
        print_progress(row, height);
        for (int col = 0; col < width; col++)
        {
            int pixel = row * width + col;
            double r = (double)row / (width - 1);
            double g = (double)col / (height - 1);
            double b = 0.0;

            image[pixel * 3 + 0] = r;
            image[pixel * 3 + 1] = g;
            image[pixel * 3 + 2] = b;
        }
    }
}

int main(int argc, char **argv)
{
    const unsigned int width = 256;
    const unsigned int height = 256;

    num image[width * height * 3];

    fill_test_image(image, width, height);

    write_ppm("image.ppm", image, width, height);

    printf("\nDone!\n");

    fflush(stdout);

    return 0;
}
