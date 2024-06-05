#include "test_framework.h"

#include "../src/tuple.h"

TEST(is_point_test)
{
    Tuple p(4.3, -4.2, 3.1, 1.0);

    ASSERT_FLOAT_EQ(p.x, 4.3);
    ASSERT_FLOAT_EQ(p.y, -4.2);
    ASSERT_FLOAT_EQ(p.z, 3.1);
    ASSERT_FLOAT_EQ(p.w, 1.0);
    ASSERT_TRUE(p.is_point());
    ASSERT_FALSE(p.is_vec());

    return true;
}

TEST(is_vec_test)
{
    Tuple v(4.3, -4.2, 3.1, 0.0);

    ASSERT_FLOAT_EQ(v.x, 4.3);
    ASSERT_FLOAT_EQ(v.y, -4.2);
    ASSERT_FLOAT_EQ(v.z, 3.1);
    ASSERT_FLOAT_EQ(v.w, 0.0);
    ASSERT_TRUE(v.is_vec());
    ASSERT_FALSE(v.is_point());

    return true;
}

TEST(tuple_eq_test)
{
    Tuple a(1.0, 2.0, 3.0, 1.0);
    Tuple b(1.0, 2.0, 3.0, 1.0);

    ASSERT_TRUE(a == b);
    b = Tuple(1.0, 2.0, 3.1, 1.0);
    ASSERT_FALSE(a == b);

    return true;
}

TEST(tuple_add_test)
{
    Tuple a(3.0, -2.0, 5.0, 1.0);
    Tuple b(-2.0, 3.0, 1.0, 0.0);
    Tuple c = a + b;
    Tuple expected(1.0, 1.0, 6.0, 1.0);

    ASSERT_TRUE(c == expected);
    ASSERT_TRUE(c.is_point());

    return true;
}

TEST(tuple_sub_test)
{
    Tuple a(3.0, 2.0, 1.0, 1.0);
    Tuple b(5.0, 6.0, 7.0, 1.0);
    Tuple c = a - b;
    Tuple expected(-2.0, -4.0, -6.0, 0.0);

    ASSERT_TRUE(c == expected);
    ASSERT_TRUE(c.is_vec());

    return true;
}

TEST(tuple_neg_test)
{
    Tuple a(1.0, -2.0, 3.0, -4.0);
    Tuple b = -a;
    Tuple expected(-1.0, 2.0, -3.0, 4.0);

    ASSERT_TRUE(b == expected);

    return true;
}

TEST(tuple_mul_scalar_test)
{
    Tuple a(1.0, -2.0, 3.0, -4.0);
    Tuple b = a * 3.5;
    Tuple expected(3.5, -7.0, 10.5, -14.0);

    ASSERT_TRUE(b == expected);

    return true;
}

TEST(tuple_div_scalar_test)
{
    Tuple a(1.0, -2.0, 3.0, -4.0);
    Tuple b = a / 2;
    Tuple expected(0.5, -1.0, 1.5, -2.0);

    ASSERT_TRUE(b == expected);

    return true;
}

TEST(tuple_mag_test)
{
    Tuple v(1.0, 0.0, 0.0, 0.0);
    ASSERT_FLOAT_EQ(v.mag(), 1.0);

    v = Tuple(0.0, 1.0, 0.0, 0.0);
    ASSERT_FLOAT_EQ(v.mag(), 1.0);

    v = Tuple(0.0, 0.0, 1.0, 0.0);
    ASSERT_FLOAT_EQ(v.mag(), 1.0);

    v = Tuple(1.0, 2.0, 3.0, 0.0);
    ASSERT_FLOAT_EQ(v.mag(), sqrt(14));

    v = Tuple(-1.0, -2.0, -3.0, 0.0);
    ASSERT_FLOAT_EQ(v.mag(), sqrt(14));

    return true;
}

TEST(tuple_norm_test)
{
    Tuple v(4.0, 0.0, 0.0, 0.0);
    Tuple n = v.norm();
    Tuple expected(1.0, 0.0, 0.0, 0.0);

    ASSERT_TRUE(n == expected);

    v = Tuple(1.0, 2.0, 3.0, 0.0);
    n = v.norm();
    expected = Tuple(0.26726, 0.53452, 0.80178, 0.0);

    ASSERT_TRUE(n == expected);

    return true;
}

TEST(tuple_dot_test)
{
    Tuple a(1.0, 2.0, 3.0, 0.0);
    Tuple b(2.0, 3.0, 4.0, 0.0);

    ASSERT_FLOAT_EQ(a.dot(b), 20.0);

    return true;
}

TEST(tuple_cross_test)
{
    Tuple a(1.0, 2.0, 3.0, 0.0);
    Tuple b(2.0, 3.0, 4.0, 0.0);
    Tuple c = a.cross(b);
    Tuple expected(-1.0, 2.0, -1.0, 0.0);

    ASSERT_TRUE(c == expected);

    c = b.cross(a);
    expected = Tuple(1.0, -2.0, 1.0, 0.0);

    ASSERT_TRUE(c == expected);

    return true;
}

TEST(tuple_hadamard_test)
{
    Tuple a(1.0, 2.0, 3.0, 0.0);
    Tuple b(2.0, 3.0, 4.0, 0.0);
    Tuple c = a.hadamard(b);
    Tuple expected(2.0, 6.0, 12.0, 0.0);

    ASSERT_TRUE(c == expected);

    return true;
}