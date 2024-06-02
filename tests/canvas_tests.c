#include "test_framework.h"
#include "../src/canvas.h"

TEST(new_canvas_test)
{
    canvas *c = new_canvas(10, 20);
    ASSERT_EQ(10, c->width);
    ASSERT_EQ(20, c->height);

	color black = new_color(0.0, 0.0, 0.0);

	for (int i = 0; i < c->width; i++)
	{
		for (int j = 0; j < c->height; j++)
		{
			ASSERT_TRUE(tuple_eq(canvas_pixel_at(c, 2, 3), black));
		}
	}

    free_canvas(&c);
}

TEST(write_pixel_test)
{
    canvas *c = new_canvas(10, 20);
    color red = new_color(1.0, 0.0, 0.0);
    canvas_write_pixel(c, 2, 3, red);
    ASSERT_TRUE(tuple_eq(canvas_pixel_at(c, 2, 3), red));
    free_canvas(&c);
}
