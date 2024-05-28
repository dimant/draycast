#include <stdio.h>

void write_ppm(
    const char *fname,
    const double *image,
    const unsigned int width,
    const unsigned int height)
{
    FILE *file = fopen(fname, "w");

    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "255\n");

    for (int pixel = 0; pixel < width * height; pixel++)
    {
        for (int color = 0; color < 3; color++)
        {
            fprintf(file, "%f ", image[pixel * 3 + color]);
        }
    }
}

int main(int argc, char **argv)
{
    const unsigned int width = 256;
    const unsigned int height = 256;

    double image[width * height * 3];

    for (int pixel = 0; pixel < width * height; pixel++)
    {
        for (int color = 0; color < 3; color++)
        {
            image[pixel * 3 + color] = (double)pixel / (width * height);
        }
    }

    write_ppm("image.ppm", image, width, height);

    return 0;
}
