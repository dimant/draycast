#include "test_framework.h"

#include "../src/canvas.h"

TEST(canvas_test)
{
    Canvas c(10, 20);

    ASSERT_EQ(c.get_width(), 10);
    ASSERT_EQ(c.get_height(), 20);

    c.clear();

    for (int y = 0; y < c.get_height(); y++)
    {
        for (int x = 0; x < c.get_width(); x++)
        {
            ASSERT_FLOAT_EQ(c.get_pixel(x, y).x, Tuple(0, 0, 0, 0).x);
            ASSERT_FLOAT_EQ(c.get_pixel(x, y).y, Tuple(0, 0, 0, 0).y);
            ASSERT_FLOAT_EQ(c.get_pixel(x, y).z, Tuple(0, 0, 0, 0).z);
            ASSERT_FLOAT_EQ(c.get_pixel(x, y).w, Tuple(0, 0, 0, 0).w);
        }
    }

    return true;
}

TEST(canvas_set_pixel_test)
{
    Canvas c(10, 20);

    c.set_pixel(2, 3, Tuple(1.0, 0.0, 0.0, 0.0));

    ASSERT_FLOAT_EQ(c.get_pixel(2, 3).x, Tuple(1.0, 0.0, 0.0, 0.0).x);
    ASSERT_FLOAT_EQ(c.get_pixel(2, 3).y, Tuple(1.0, 0.0, 0.0, 0.0).y);
    ASSERT_FLOAT_EQ(c.get_pixel(2, 3).z, Tuple(1.0, 0.0, 0.0, 0.0).z);
    ASSERT_FLOAT_EQ(c.get_pixel(2, 3).w, Tuple(1.0, 0.0, 0.0, 0.0).w);

    return true;
}