#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "test_framework.h"
#include "../src/ppm.h"

TEST(ppm_write_header_test)
{
    size_t size = 256;
    char buffer[size];

    memset(buffer, 0, size);

    FILE *stream = fmemopen(buffer, size, "w");
    if (stream == 0)
    {
        ASSERT_FALSE(true);
    }

    ppm_write_header(stream, 10, 20);

    const char *expected = "P3\n10 20\n255\n";

    fflush(stream);

    ASSERT_EQ(0, strcmp(expected, buffer));
}

TEST(ppm_write_pixel_test)
{
    size_t size = 256;
    char buffer[size];

    memset(buffer, 0, size);

    FILE *stream = fmemopen(buffer, size, "w");
    if (stream == 0)
    {
        ASSERT_FALSE(true);
    }

    color c = {0.1, 0.2, 0.3};

    ppm_reset_line();

    ppm_write_pixel(stream, c);

    const char *expected = "25 51 76";

    fflush(stream);

    ASSERT_EQ(0, strcmp(expected, buffer));
}

TEST(ppm_write_pixel_line_test)
{
    size_t size = 256;
    char buffer[size];

    memset(buffer, 0, size);

    FILE *stream = fmemopen(buffer, size, "w");
    if (stream == 0)
    {
        ASSERT_FALSE(true);
    }

    color c = {0.1, 0.2, 0.3};

    ppm_reset_line();

    ppm_write_pixel(stream, c);
    ppm_write_pixel(stream, c);
    ppm_write_pixel(stream, c);
    ppm_write_pixel(stream, c);
    ppm_write_pixel(stream, c);
    fflush(stream);

    const char *expected = "25 51 76 25 51 76 25 51 76 25 51 76\n25 51 76";

    ASSERT_EQ(0, strcmp(expected, buffer));
}

TEST(ppm_write_pixel_lines_test)
{
    size_t size = 1024;
    char buffer[size];

    memset(buffer, 0, size);

    FILE *stream = fmemopen(buffer, size, "w");
    if (stream == 0)
    {
        ASSERT_FALSE(true);
    }

    color c = {0.1, 0.2, 0.3};

    ppm_reset_line();

    ppm_write_pixel(stream, c); // 1
    ppm_write_pixel(stream, c); // 2
    ppm_write_pixel(stream, c); // 3
    ppm_write_pixel(stream, c); // 4
    ppm_write_pixel(stream, c); // 5
    ppm_write_pixel(stream, c); // 6
    ppm_write_pixel(stream, c); // 7
    ppm_write_pixel(stream, c); // 8
    ppm_write_pixel(stream, c); // 9
    ppm_write_pixel(stream, c); // 10

    fflush(stream);

    const char *expected = "25 51 76 25 51 76 25 51 76 25 51 76\n25 51 76 25 51 76 25 51 76 25 51 76\n25 51 76 25 51 76";

    ASSERT_EQ(0, strcmp(expected, buffer));
}

TEST(ppm_write_footer_test)
{
    size_t size = 256;
    char buffer[size];

    memset(buffer, 0, size);

    FILE *stream = fmemopen(buffer, size, "w");
    if (stream == 0)
    {
        ASSERT_FALSE(true);
    }

    ppm_write_footer(stream);

    const char *expected = "\n";

    fflush(stream);

    ASSERT_EQ(0, strcmp(expected, buffer));
}

TEST(ppm_write_canvas_test)
{
    size_t size = 1024;
    char buffer[size];

    memset(buffer, 0, size);

    FILE *stream = fmemopen(buffer, size, "w");
    if (stream == 0)
    {
        ASSERT_FALSE(true);
    }

    canvas *c = new_canvas(1, 2);
    color red = {1, 0, 0};

    for (int y = 0; y < c->height; y++)
    {
        for (int x = 0; x < c->width; x++)
        {
            canvas_write_pixel(c, x, y, red);
        }
    }

    ppm_write_canvas(stream, c);

    free_canvas(&c);

    const char *expected = "P3\n1 2\n255\n255 0 0 255 0 0\n";

    ASSERT_EQ(0, strcmp(expected, buffer));
}
