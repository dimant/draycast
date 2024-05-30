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

TEST(num_eq_test)
{
	ASSERT_TRUE(num_eq(1.0, 1.0));
	ASSERT_FALSE(num_eq(1.0, 1.1));
}

TEST(tuple_eq_test)
{
    tuple a = new_point(1.0, 2.0, 3.0);
    tuple b = new_point(1.0, 2.0, 3.0);
    ASSERT_TRUE(tuple_eq(a, b));
    b = new_point(1.0, 2.0, 3.1);
    ASSERT_FALSE(tuple_eq(a, b));
}

TEST(tuple_add_test)
{
    tuple a = new_point(3.0, -2.0, 5.0);
    tuple b = new_vector(-2.0, 3.0, 1.0);
    tuple c = tuple_add(a, b);
    tuple expected = new_point(1.0, 1.0, 6.0);
    ASSERT_TRUE(tuple_eq(c, expected));
	ASSERT_TRUE(is_point(c));
}

TEST(tuple_sub_test)
{
    tuple a = new_point(3.0, 2.0, 1.0);
    tuple b = new_point(5.0, 6.0, 7.0);
    tuple c = tuple_sub(a, b);
    tuple expected = new_vector(-2.0, -4.0, -6.0);
    ASSERT_TRUE(tuple_eq(c, expected));
	ASSERT_TRUE(is_vector(c));
}

TEST(tuple_neg_test)
{
    tuple a = new_point(1.0, -2.0, 3.0);
    tuple b = tuple_neg(a);
    tuple expected = new_point(-1.0, 2.0, -3.0);
	expected.w = -expected.w;
    ASSERT_TRUE(tuple_eq(b, expected));
}

