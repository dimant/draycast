#include <stdio.h>
#include <math.h>

#include "util.h"
#include "image.h"
#include "num.h"
#include "vec.h"
#include "ray.h"
#include "color.h"

num hit_sphere(const point center, const num radius, const ray r)
{
    const vec oc = vec_sub(center, r.origin);
    const num a = vec_length_squared(r.direction);
    const num h = vec_dot(r.direction, oc);
    const num c = vec_length_squared(oc) - radius * radius;
    const num discriminant = h * h - a * c;

    if (discriminant < 0.0)
    {
        return -1.0;
    }
    else
    {
        return (h - sqrt(discriminant)) / a;
    }
}

color ray_color(const ray r)
{
    const point sphere_center = vec_create(0.0, 0.0, -1.0);
    const num sphere_radius = 0.5;
    const num t = hit_sphere(sphere_center, sphere_radius, r);
    if (t > 0.0)
    {
        const vec p = ray_point_at(r, t);
        const vec d = vec_sub(p, sphere_center);
        const vec n = vec_unit(d);

        return color_create(
            (n.x + 1.0) / 2.0,
            (n.y + 1.0) / 2.0,
            (n.z + 1.0) / 2.0);
    }

    const vec unit_direction = vec_unit(r.direction);
    const num a = 0.5 * (unit_direction.y + 1.0);
    const color start = color_create(1.0, 1.0, 1.0);
    const color end = color_create(0.5, 0.7, 1.0);

    const vec start_v = vec_mul_scalar(COL_VEC(start), 1.0 - a);
    const vec end_v = vec_mul_scalar(COL_VEC(end), a);
    const vec result = vec_add(start_v, end_v);

    return VEC_COL(result);
}

void render(image *img)
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

    vec viewport_u_2 = vec_div_scalar(viewport_u, 2.0);
    vec viewport_v_2 = vec_div_scalar(viewport_v, 2.0);

    point viewport_upper_left =
        vec_sub(
            vec_sub(
                vec_sub(camera_center, vec_create(0.0, 0.0, focal_length)), // camera_center - focal_length
                viewport_u_2),                                              // - viewport_u / 2
            viewport_v_2);                                                  // - viewport_v / 2

    // pixel_00_loc = viewport_upper_left + (pixel_delta_u + pixel_delta_v) / 2
    vec pixel_delta_uv = vec_add(pixel_delta_u, pixel_delta_v);
    vec pixel_delta_uv_2 = vec_div_scalar(pixel_delta_uv, 2.0);
    point pixel_00_loc = vec_add(viewport_upper_left, pixel_delta_uv_2);

    // render
    img->width = image_width;
    img->height = image_height;
    img->pixels = (color *)malloc(image_width * image_height * sizeof(color));

    for (int row = 0; row < image_height; row++)
    {
        print_progress(row, image_height);

        for (int col = 0; col < image_width; col++)
        {
            const vec delta_u = vec_mul_scalar(pixel_delta_u, col);
            const vec delta_v = vec_mul_scalar(pixel_delta_v, row);

            // pixel_center = pixel_00_loc + row * pixel_delta_u + col * pixel_delta_v
            const point pixel_center = vec_add(vec_add(pixel_00_loc, delta_u), delta_v);
            const vec ray_direction = vec_sub(pixel_center, camera_center);
            const ray r = ray_create(camera_center, ray_direction);
            const color pixel_color = ray_color(r);

            int pixel = row * image_width + col;
            img->pixels[pixel] = pixel_color;
        }
    }
}

void render_test_image()
{
    const unsigned int width = 256;
    const unsigned int height = 256;
    FILE *file = fopen("image.ppm", "w");

    image img = image_create(width, height);

    fill_test_image(img);

    ppm_write(file, img);

    image_free(img);
}

int main(int argc, char **argv)
{
    FILE *file = fopen("image.ppm", "w");
    image img;

    render(&img);
    ppm_write(file, img);

    printf("\nDone!\n");

    fflush(stdout);

    return 0;
}
