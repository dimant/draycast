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

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int pixel = row * width + col;
            double r = (double)row / (width - 1);
            double g = (double)col / (height - 1);
            double b = 0.0;

            int ir = (int)255.999 * r;
            int ig = (int)255.999 * g;
            int ib = (int)255.999 * b;

            image[pixel * 3 + 0] = ir;
            image[pixel * 3 + 1] = ig;
            image[pixel * 3 + 2] = ib;
        }
    }

    write_ppm("image.ppm", image, width, height);

    return 0;
}
