#include "test_framework.h"

#include "../src/tuple.h"

TEST(is_point_test)
{
    tuple p = new_point(4.3, -4.2, 3.1);
    ASSERT_FLOAT_EQ(p.x, 4.3);
    ASSERT_FLOAT_EQ(p.y, -4.2);
    ASSERT_FLOAT_EQ(p.z, 3.1);
    ASSERT_FLOAT_EQ(p.w, 1.0);
    ASSERT_TRUE(is_point(p));
    ASSERT_FALSE(is_vector(p));
}

TEST(is_vector_test)
{
    tuple v = new_vector(4.3, -4.2, 3.1);
    ASSERT_FLOAT_EQ(v.x, 4.3);
    ASSERT_FLOAT_EQ(v.y, -4.2);
    ASSERT_FLOAT_EQ(v.z, 3.1);
    ASSERT_FLOAT_EQ(v.w, 0.0);
    ASSERT_FALSE(is_point(v));
    ASSERT_TRUE(is_vector(v));
}
