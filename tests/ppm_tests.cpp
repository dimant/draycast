#include "test_framework.h"

#include "../src/ppm.h"

TEST(ppm_write_header_test)
{
    PPM ppm;

    MemoryOutputStream stream;

    ppm.write_header(stream, 10, 20);

    std::string expected = "P3\n10 20\n255\n";

    ASSERT_EQ(expected, stream.str());

    return true;
}

TEST(ppm_write_pixel_test)
{
    PPM ppm;

    MemoryOutputStream stream;

    Tuple c(0.1, 0.2, 0.3, 0.0);

    ppm.write_pixel(stream, c);

    std::string expected = "25 51 76";

    ASSERT_EQ(expected, stream.str());

    return true;
}

TEST(ppm_write_pixel_line_test)
{
    PPM ppm;

    MemoryOutputStream stream;

    Tuple c(0.1, 0.2, 0.3, 0.0);

    for (int i = 0; i < 5; i++)
    {
        ppm.write_pixel(stream, c);
    }

    std::string expected = "25 51 76 25 51 76 25 51 76 25 51 76\n25 51 76";

    ASSERT_EQ(expected, stream.str());

    return true;
}

TEST(ppm_write_pixel_lines_test)
{
    PPM ppm;

    MemoryOutputStream stream;

    Tuple c(0.1, 0.2, 0.3, 0.0);

    for (int i = 0; i < 10; i++)
    {
        ppm.write_pixel(stream, c);
    }

    std::string expected = "25 51 76 25 51 76 25 51 76 25 51 76\n25 51 76 25 51 76 25 51 76 25 51 76\n25 51 76 25 51 76";

    ASSERT_EQ(expected, stream.str());

    return true;
}

TEST(ppm_write_footer_test)
{
    PPM ppm;

    MemoryOutputStream stream;

    ppm.write_footer(stream);

    std::string expected = "\n";

    ASSERT_EQ(expected, stream.str());

    return true;
}

TEST(ppm_write_canvas_test)
{
    PPM ppm;

    MemoryOutputStream stream;

    Canvas c(1, 2);

    for (int y = 0; y < c.get_height(); y++)
    {
        for (int x = 0; x < c.get_width(); x++)
        {
            c.set_pixel(x, y, Tuple(1.0, 0.0, 0.0, 0.0));
        }
    }

    ppm.write_canvas(stream, c);

    std::string expected = "P3\n1 2\n255\n255 0 0 255 0 0\n";

    ASSERT_EQ(expected, stream.str());

    return true;
}