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
    ASSERT_FALSE(is_vec(p));
}

TEST(is_vec_test)
{
    tuple v = new_vec(4.3, -4.2, 3.1);
    ASSERT_FLOAT_EQ(v.x, 4.3);
    ASSERT_FLOAT_EQ(v.y, -4.2);
    ASSERT_FLOAT_EQ(v.z, 3.1);
    ASSERT_FLOAT_EQ(v.w, 0.0);
    ASSERT_FALSE(is_point(v));
    ASSERT_TRUE(is_vec(v));
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
    tuple b = new_vec(-2.0, 3.0, 1.0);
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
    tuple expected = new_vec(-2.0, -4.0, -6.0);
    ASSERT_TRUE(tuple_eq(c, expected));
    ASSERT_TRUE(is_vec(c));
}

TEST(tuple_neg_test)
{
    tuple a = new_point(1.0, -2.0, 3.0);
    tuple b = tuple_neg(a);
    tuple expected = new_point(-1.0, 2.0, -3.0);
    expected.w = -expected.w;
    ASSERT_TRUE(tuple_eq(b, expected));
}

TEST(tuple_mul_scalar_test)
{
    tuple a = new_point(1.0, -2.0, 3.0);
    tuple b = tuple_mul_scalar(a, 3.5);
    tuple expected = new_point(3.5, -7.0, 10.5);
    expected.w = 3.5;
    ASSERT_TRUE(tuple_eq(b, expected));
}

TEST(tuple_div_scalar_test)
{
    tuple a = new_point(1.0, -2.0, 3.0);
    tuple b = tuple_div_scalar(a, 2.0);
    tuple expected = new_point(0.5, -1.0, 1.5);
    expected.w = 0.5;
    ASSERT_TRUE(tuple_eq(b, expected));
}

TEST(vec_mag_test)
{
    tuple a = new_vec(1.0, 0.0, 0.0);
    tuple b = new_vec(0.0, 1.0, 0.0);
    tuple c = new_vec(0.0, 0.0, 1.0);
    ASSERT_FLOAT_EQ(1.0, vec_mag(a));
    ASSERT_FLOAT_EQ(1.0, vec_mag(b));
    ASSERT_FLOAT_EQ(1.0, vec_mag(c));
}

TEST(vec_norm_test)
{
    tuple a = new_vec(4.0, 0.0, 0.0);
    tuple b = new_vec(1.0, 2.0, 3.0);
    tuple c = vec_norm(b);
    ASSERT_FLOAT_EQ(1.0, vec_mag(c));
    ASSERT_FLOAT_EQ(1.0, vec_mag(vec_norm(a)));
}

TEST(vec_dot_test)
{
    tuple a = new_vec(1.0, 2.0, 3.0);
    tuple b = new_vec(2.0, 3.0, 4.0);
    ASSERT_FLOAT_EQ(20.0, vec_dot(a, b));
}

TEST(vec_cross_test)
{
    tuple a = new_vec(1.0, 2.0, 3.0);
    tuple b = new_vec(2.0, 3.0, 4.0);
    tuple actual1 = vec_cross(a, b);
    tuple expected1 = new_vec(-1.0, 2.0, -1.0);
    ASSERT_TRUE(tuple_eq(actual1, expected1));

    tuple actual2 = vec_cross(b, a);
    tuple expected2 = new_vec(1.0, -2.0, 1.0);
    ASSERT_TRUE(tuple_eq(actual2, expected2));
}

TEST(color_mul_test)
{
    color a = new_color(1.0, 0.2, 0.4);
    color b = new_color(0.9, 1.0, 0.1);
    color c = color_mul(a, b);
    color expected = new_color(0.9, 0.2, 0.04);
    ASSERT_TRUE(tuple_eq(c, expected));
}
