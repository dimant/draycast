#include <stdio.h>

#include "num.h"
#include "vec.h"
#include "ray.h"
#include "color.h"
#include "image.h"

void write_ppm(
    const char *fname,
    const image img)
{
    FILE *file = fopen(fname, "w");

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

color ray_color(const ray r)
{
    return color_create(0, 0, 0);
}

void render()
{
    num aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    int image_height = (int)(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    num viewport_height = 2.0;
    num viewport_width = viewport_height * (((num)image_width) / image_height);

    num focal_length = 1.0;
    point camera_center = vec_create(0.0, 0.0, 0.0);

    vec viewport_u = vec_create(viewport_width, 0.0, 0.0);
    vec viewport_v = vec_create(0.0, -viewport_height, 0.0);

    vec pixel_delta_u = vec_div_scalar(viewport_u, image_width);
    vec pixel_delta_v = vec_div_scalar(viewport_v, image_height);

    point viewport_upper_left =
        vec_sub(
            vec_sub(
                vec_sub(camera_center,
                        vec_create(0.0, 0.0, focal_length)), // camera_center - focal_length
                vec_div_scalar(viewport_u, 2.0)),            // - viewport_u / 2
            vec_div_scalar(viewport_v, 2.0));                // - viewport_v / 2

    // pixel_00_loc = viewport_upper_left + (pixel_delta_u + pixel_delta_v) / 2
    point pixel_00_loc = vec_add(viewport_upper_left, vec_div_scalar(vec_add(pixel_delta_u, pixel_delta_v), 2.0));

    // render

    for (int row = 0; row < image_height; row++)
    {
        for (int col = 0; col < image_width; col++)
        {
            vec delta_u = vec_mul_scalar(pixel_delta_u, row);
            vec delta_v = vec_mul_scalar(pixel_delta_v, col);

            // pixel_center = pixel_00_loc + row * pixel_delta_u + col * pixel_delta_v
            point pixel_center = vec_add(vec_add(pixel_00_loc, delta_u), delta_v);
            vec ray_direction = vec_sub(pixel_center, camera_center);
            ray r = ray_create(camera_center, ray_direction);
            color pixel_color = ray_color(r);
        }
    }
}

int main(int argc, char **argv)
{
    const unsigned int width = 256;
    const unsigned int height = 256;

    image img = image_create(width, height);

    fill_test_image(img);

    write_ppm("image.ppm", img);

    printf("\nDone!\n");

    fflush(stdout);

    return 0;
}
