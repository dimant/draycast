#include "test_framework.h"

#include "../src/canvas.h"

TEST(canvas_test)
{
    Canvas c(10, 20);

    ASSERT_EQ(c.get_width(), 10);
    ASSERT_EQ(c.get_height(), 20);

    c.clear();

    Tuple expected = Tuple(0, 0, 0, 0);

    for (int y = 0; y < c.get_height(); y++)
    {
        for (int x = 0; x < c.get_width(); x++)
        {
            ASSERT_FLOAT_EQ(expected.x, c.get_pixel(x, y).x);
            ASSERT_FLOAT_EQ(expected.y, c.get_pixel(x, y).y);
            ASSERT_FLOAT_EQ(expected.z, c.get_pixel(x, y).z);
            ASSERT_FLOAT_EQ(expected.w, c.get_pixel(x, y).w);
        }
    }

    return true;
}

TEST(canvas_set_pixel_test)
{
    Canvas c(10, 20);

    c.set_pixel(2, 3, Tuple(1.0, 0.0, 0.0, 0.0));

    Tuple expected = Tuple(1.0, 0.0, 0.0, 0.0);

    ASSERT_FLOAT_EQ(expected.x, c.get_pixel(2, 3).x);
    ASSERT_FLOAT_EQ(expected.y, c.get_pixel(2, 3).y);
    ASSERT_FLOAT_EQ(expected.z, c.get_pixel(2, 3).z);
    ASSERT_FLOAT_EQ(expected.w, c.get_pixel(2, 3).w);

    return true;
}