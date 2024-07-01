#include "test_framework.h"

#include "../src/tuple.h"
#include "../src/matrix.h"

TEST(matrix4_access_test)
{
    Matrix<4> m;

    for (size_t row = 0; row < 4; row++)
    {
        for (size_t col = 0; col < 4; col++)
        {
            m.set(row, col, 1.0f);
            ASSERT_FLOAT_EQ(m.get(row, col), 1.0f);
        }
    }

    return true;
}

TEST(matrix3_access_test)
{
    Matrix<3> m;

    for (size_t row = 0; row < 3; row++)
    {
        for (size_t col = 0; col < 3; col++)
        {
            m.set(row, col, 1.0f);
            ASSERT_FLOAT_EQ(m.get(row, col), 1.0f);
        }
    }

    return true;
}

TEST(matrix2_access_test)
{
    Matrix<2> m;

    for (size_t row = 0; row < 2; row++)
    {
        for (size_t col = 0; col < 2; col++)
        {
            m.set(row, col, 1.0f);
            ASSERT_FLOAT_EQ(m.get(row, col), 1.0f);
        }
    }

    return true;
}

TEST(matrix4_eq_test)
{
    Matrix<4> m1;
    Matrix<4> m2;


    for (size_t row = 0; row < 2; row++)
    {
        for (size_t col = 0; col < 2; col++)
        {
            m1.set(row, col, (float) row * 4 + col);
            m2.set(row, col, (float) row * 4 + col);
        }
    }

    ASSERT_TRUE(m1 == m2);

    m2.set(0, 0, -3.0f);

    ASSERT_FALSE(m1 == m2);

    return true;
}

TEST(matrix4_neq_test)
{
    Matrix<4> m1;
    Matrix<4> m2;

    for (size_t row = 0; row < 2; row++)
    {
        for (size_t col = 0; col < 2; col++)
        {
            m1.set(row, col, (float) row * 4 + col);
            m2.set(row, col, (float) row * 4 + col);
        }
    }

    ASSERT_FALSE(m1 != m2);

    m2.set(0, 0, -3.0f);

    ASSERT_TRUE(m1 != m2);

    return true;
}

TEST(matrix4_mul_test)
{
    Matrix<4> m1;
    Matrix<4> m2;

    for (size_t row = 0; row < 4; row++)
    {
        for (size_t col = 0; col < 4; col++)
        {
            m1.set(row, col, (float) row * 4 + col);
            m2.set(row, col, (float) row * 4 + col);
        }
    }

    Matrix<4> result = m1 * m2;

    ASSERT_FLOAT_EQ(56.0f, result.get(0, 0));
    ASSERT_FLOAT_EQ(62.0f, result.get(0, 1));
    ASSERT_FLOAT_EQ(68.0f, result.get(0, 2));
    ASSERT_FLOAT_EQ(74.0f, result.get(0, 3));

    ASSERT_FLOAT_EQ(152.0f, result.get(1, 0));
    ASSERT_FLOAT_EQ(174.0f, result.get(1, 1));
    ASSERT_FLOAT_EQ(196.0f, result.get(1, 2));
    ASSERT_FLOAT_EQ(218.0f, result.get(1, 3));

    ASSERT_FLOAT_EQ(248.0f, result.get(2, 0));
    ASSERT_FLOAT_EQ(286.0f, result.get(2, 1));
    ASSERT_FLOAT_EQ(324.0f, result.get(2, 2));
    ASSERT_FLOAT_EQ(362.0f, result.get(2, 3));

    ASSERT_FLOAT_EQ(344.0f, result.get(3, 0));
    ASSERT_FLOAT_EQ(398.0f, result.get(3, 1));
    ASSERT_FLOAT_EQ(452.0f, result.get(3, 2));
    ASSERT_FLOAT_EQ(506.0f, result.get(3, 3));

    return true;
}

TEST(matrix4_identity_test)
{
    Matrix<4> m;
    Matrix<4> identity;

    for (size_t row = 0; row < 4; row++)
    {
        for (size_t col = 0; col < 4; col++)
        {
            m.set(row, col, (float) row * 4 + col);

        }

        identity.set(row, row, 1.0f);
    }

    Matrix<4> result = m * identity;

    ASSERT_TRUE(result == m);

    return true;
}

TEST(matrix4_transpose_test)
{
    Matrix<4> m;

    for (size_t row = 0; row < 4; row++)
    {
        for (size_t col = 0; col < 4; col++)
        {
            m.set(row, col, (float) row * 4 + col);
        }
    }

    m.transpose();

    ASSERT_FLOAT_EQ(0.0,   m.get(0,0));
    ASSERT_FLOAT_EQ(4.0,   m.get(0,1));
    ASSERT_FLOAT_EQ(8.0,   m.get(0,2));
    ASSERT_FLOAT_EQ(12.0,  m.get(0,3));

    ASSERT_FLOAT_EQ(1.0,   m.get(1,0));
    ASSERT_FLOAT_EQ(5.0,   m.get(1,1));
    ASSERT_FLOAT_EQ(9.0,   m.get(1,2));
    ASSERT_FLOAT_EQ(13.0,  m.get(1,3));

    ASSERT_FLOAT_EQ(2.0,   m.get(2,0));
    ASSERT_FLOAT_EQ(6.0,   m.get(2,1));
    ASSERT_FLOAT_EQ(10.0,  m.get(2,2));
    ASSERT_FLOAT_EQ(14.0,  m.get(2,3));

    ASSERT_FLOAT_EQ(3.0,   m.get(3,0));
    ASSERT_FLOAT_EQ(7.0,   m.get(3,1));
    ASSERT_FLOAT_EQ(11.0,  m.get(3,2));
    ASSERT_FLOAT_EQ(15.0,  m.get(3,3));

    return true;
}

TEST(matrix2_determinant)
{
    Matrix<2> m;

    m.set(0, 0, 1.0f);
    m.set(0, 1, 5.0f);
    m.set(1, 0, -3.0f);
    m.set(1, 1, 2.0f);

    ASSERT_FLOAT_EQ(17.0f, m.determinant());

    return true;
}

TEST(matrix3_submatrix)
{
    Matrix<3> m;

    for (size_t row = 0; row < 3; row++)
    {
        for (size_t col = 0; col < 3; col++)
        {
            m.set(row, col, (float) row * 3 + col);
        }
    }

    Matrix<2> sub = m.submatrix(1, 2);

    ASSERT_FLOAT_EQ(0.0f, sub.get(0, 0));
    ASSERT_FLOAT_EQ(1.0f, sub.get(0, 1));

    ASSERT_FLOAT_EQ(6.0f, sub.get(1, 0));
    ASSERT_FLOAT_EQ(7.0f, sub.get(1, 1));

    return true;
}

TEST(matrix4_submatrix)
{
    Matrix<4> m;

    for (size_t row = 0; row < 4; row++)
    {
        for (size_t col = 0; col < 4; col++)
        {
            m.set(row, col, (float) row * 4 + col);
        }
    }

    Matrix<3> sub = m.submatrix(1, 2);

    ASSERT_FLOAT_EQ(0.0f, sub.get(0, 0));
    ASSERT_FLOAT_EQ(1.0f, sub.get(0, 1));
    ASSERT_FLOAT_EQ(3.0f, sub.get(0, 2));

    ASSERT_FLOAT_EQ(8.0f, sub.get(1, 0));
    ASSERT_FLOAT_EQ(9.0f, sub.get(1, 1));
    ASSERT_FLOAT_EQ(11.0f, sub.get(1, 2));

    ASSERT_FLOAT_EQ(12.0f, sub.get(2, 0));
    ASSERT_FLOAT_EQ(13.0f, sub.get(2, 1));
    ASSERT_FLOAT_EQ(15.0f, sub.get(2, 2));

    return true;
}

TEST(matrix3_minor)
{
    Matrix<3> m;

    m.set(0, 0, 3.0f);
    m.set(0, 1, 5.0f);
    m.set(0, 2, 0.0f);

    m.set(1, 0, 2.0f);
    m.set(1, 1, -1.0f);
    m.set(1, 2, -7.0f);

    m.set(2, 0, 6.0f);
    m.set(2, 1, -1.0f);
    m.set(2, 2, 5.0f);

    Matrix<2> sub = m.submatrix(0, 0);

    ASSERT_FLOAT_EQ(25.0f, m.minor(1, 0));

    return true;
}

TEST(matrix3_cofactor)
{
    Matrix<3> m;

    m.set(0, 0, 3.0f);
    m.set(0, 1, 5.0f);
    m.set(0, 2, 0.0f);

    m.set(1, 0, 2.0f);
    m.set(1, 1, -1.0f);
    m.set(1, 2, -7.0f);

    m.set(2, 0, 6.0f);
    m.set(2, 1, -1.0f);
    m.set(2, 2, 5.0f);

    ASSERT_FLOAT_EQ(-12.0f, m.minor(0, 0));
    ASSERT_FLOAT_EQ(-12.0f, m.cofactor(0, 0));

    ASSERT_FLOAT_EQ(25.0f, m.minor(1, 0));
    ASSERT_FLOAT_EQ(-25.0f, m.cofactor(1, 0));

    return true;
}

TEST(matrix3_determinant_test)
{
    Matrix<3> m;

    m.set(0, 0, 1.0f);
    m.set(0, 1, 2.0f);
    m.set(0, 2, 6.0f);

    m.set(1, 0, -5.0f);
    m.set(1, 1, 8.0f);
    m.set(1, 2, -4.0f);

    m.set(2, 0, 2.0f);
    m.set(2, 1, 6.0f);
    m.set(2, 2, 4.0f);

    ASSERT_FLOAT_EQ(56.0f, m.cofactor(0, 0));
    ASSERT_FLOAT_EQ(12.0f, m.cofactor(0, 1));
    ASSERT_FLOAT_EQ(-46.0f, m.cofactor(0, 2));

    ASSERT_FLOAT_EQ(-196.0f, m.determinant());

    return true;
}

TEST(matrix4_determinant_test)
{
    Matrix<4> m;

    m.set(0, 0, -2.0f);
    m.set(0, 1, -8.0f);
    m.set(0, 2, 3.0f);
    m.set(0, 3, 5.0f);

    m.set(1, 0, -3.0f);
    m.set(1, 1, 1.0f);
    m.set(1, 2, 7.0f);
    m.set(1, 3, 3.0f);

    m.set(2, 0, 1.0f);
    m.set(2, 1, 2.0f);
    m.set(2, 2, -9.0f);
    m.set(2, 3, 6.0f);

    m.set(3, 0, -6.0f);
    m.set(3, 1, 7.0f);
    m.set(3, 2, 7.0f);
    m.set(3, 3, -9.0f);

    ASSERT_FLOAT_EQ(690.0f, m.cofactor(0, 0));
    ASSERT_FLOAT_EQ(447.0f, m.cofactor(0, 1));
    ASSERT_FLOAT_EQ(210.0f, m.cofactor(0, 2));
    ASSERT_FLOAT_EQ(51.0f, m.cofactor(0, 3));

    ASSERT_FLOAT_EQ(-4071.0f, m.determinant());

    return true;
}

TEST(matrix4_invertible_test)
{
    Matrix<4> m;

    m.set(0, 0, 6.0f);
    m.set(0, 1, 4.0f);
    m.set(0, 2, 4.0f);
    m.set(0, 3, 4.0f);

    m.set(1, 0, 5.0f);
    m.set(1, 1, 5.0f);
    m.set(1, 2, 7.0f);
    m.set(1, 3, 6.0f);

    m.set(2, 0, 4.0f);
    m.set(2, 1, -9.0f);
    m.set(2, 2, 3.0f);
    m.set(2, 3, -7.0f);

    m.set(3, 0, 9.0f);
    m.set(3, 1, 1.0f);
    m.set(3, 2, 7.0f);
    m.set(3, 3, -6.0f);

    ASSERT_TRUE(m.invertible());

    return true;
}

TEST(matrix4_not_invertible_test)
{
    Matrix<4> m;

    m.set(0, 0, -4.0f);
    m.set(0, 1, 2.0f);
    m.set(0, 2, -2.0f);
    m.set(0, 3, 3.0f);

    m.set(1, 0, 9.0f);
    m.set(1, 1, 6.0f);
    m.set(1, 2, 2.0f);
    m.set(1, 3, 6.0f);

    m.set(2, 0, 0.0f);
    m.set(2, 1, -5.0f);
    m.set(2, 2, 1.0f);
    m.set(2, 3, -5.0f);

    m.set(3, 0, 0.0f);
    m.set(3, 1, 0.0f);
    m.set(3, 2, 0.0f);
    m.set(3, 3, 0.0f);

    ASSERT_FALSE(m.invertible());

    return true;
}

TEST(matrix4_inverse_test1)
{
    Matrix<4> m;

    m.set(0, 0, -5.0f);
    m.set(0, 1, 2.0f);
    m.set(0, 2, 6.0f);
    m.set(0, 3, -8.0f);

    m.set(1, 0, 1.0f);
    m.set(1, 1, -5.0f);
    m.set(1, 2, 1.0f);
    m.set(1, 3, 8.0f);

    m.set(2, 0, 7.0f);
    m.set(2, 1, 7.0f);
    m.set(2, 2, -6.0f);
    m.set(2, 3, -7.0f);

    m.set(3, 0, 1.0f);
    m.set(3, 1, -3.0f);
    m.set(3, 2, 7.0f);
    m.set(3, 3, 4.0f);

    Matrix<4> inverse = m.inverse();

    ASSERT_FLOAT_EQ(0.21805f, inverse.get(0, 0));
    ASSERT_FLOAT_EQ(0.45113f, inverse.get(0, 1));
    ASSERT_FLOAT_EQ(0.24060f, inverse.get(0, 2));
    ASSERT_FLOAT_EQ(-0.04511f, inverse.get(0, 3));

    ASSERT_FLOAT_EQ(-0.80827f, inverse.get(1, 0));
    ASSERT_FLOAT_EQ(-1.45677f, inverse.get(1, 1));
    ASSERT_FLOAT_EQ(-0.44361f, inverse.get(1, 2));
    ASSERT_FLOAT_EQ(0.52068f, inverse.get(1, 3));

    ASSERT_FLOAT_EQ(-0.07895f, inverse.get(2, 0));
    ASSERT_FLOAT_EQ(-0.22368f, inverse.get(2, 1));
    ASSERT_FLOAT_EQ(-0.05263f, inverse.get(2, 2));
    ASSERT_FLOAT_EQ(0.19737f, inverse.get(2, 3));

    ASSERT_FLOAT_EQ(-0.52256f, inverse.get(3, 0));
    ASSERT_FLOAT_EQ(-0.81391f, inverse.get(3, 1));
    ASSERT_FLOAT_EQ(-0.30075f, inverse.get(3, 2));
    ASSERT_FLOAT_EQ(0.30639f, inverse.get(3, 3));

    return true;
}

TEST(matrix4_inverse_test2)
{
    Matrix<4> m;

    m.set(0, 0, 8.0f);
    m.set(0, 1, -5.0f);
    m.set(0, 2, 9.0f);
    m.set(0, 3, 2.0f);

    m.set(1, 0, 7.0f);
    m.set(1, 1, 5.0f);
    m.set(1, 2, 6.0f);
    m.set(1, 3, 1.0f);

    m.set(2, 0, -6.0f);
    m.set(2, 1, 0.0f);
    m.set(2, 2, 9.0f);
    m.set(2, 3, 6.0f);

    m.set(3, 0, -3.0f);
    m.set(3, 1, 0.0f);
    m.set(3, 2, -9.0f);
    m.set(3, 3, -4.0f);

    Matrix<4> inverse = m.inverse();

    ASSERT_FLOAT_EQ(-0.15385f, inverse.get(0, 0));
    ASSERT_FLOAT_EQ(-0.15385f, inverse.get(0, 1));
    ASSERT_FLOAT_EQ(-0.28205f, inverse.get(0, 2));
    ASSERT_FLOAT_EQ(-0.53846f, inverse.get(0, 3));

    ASSERT_FLOAT_EQ(-0.07692f, inverse.get(1, 0));
    ASSERT_FLOAT_EQ(0.12308f, inverse.get(1, 1));
    ASSERT_FLOAT_EQ(0.02564f, inverse.get(1, 2));
    ASSERT_FLOAT_EQ(0.03077f, inverse.get(1, 3));

    ASSERT_FLOAT_EQ(0.35897f, inverse.get(2, 0));
    ASSERT_FLOAT_EQ(0.35897f, inverse.get(2, 1));
    ASSERT_FLOAT_EQ(0.43590f, inverse.get(2, 2));
    ASSERT_FLOAT_EQ(0.92308f, inverse.get(2, 3));

    ASSERT_FLOAT_EQ(-0.69231f, inverse.get(3, 0));
    ASSERT_FLOAT_EQ(-0.69231f, inverse.get(3, 1));
    ASSERT_FLOAT_EQ(-0.76923f, inverse.get(3, 2));
    ASSERT_FLOAT_EQ(-1.92308f, inverse.get(3, 3));

    return true;
}

TEST(matrix4_inverse_test3)
{
    Matrix<4> m;

    m.set(0, 0, 9.0f);
    m.set(0, 1, 3.0f);
    m.set(0, 2, 0.0f);
    m.set(0, 3, 9.0f);

    m.set(1, 0, -5.0f);
    m.set(1, 1, -2.0f);
    m.set(1, 2, -6.0f);
    m.set(1, 3, -3.0f);

    m.set(2, 0, -4.0f);
    m.set(2, 1, 9.0f);
    m.set(2, 2, 6.0f);
    m.set(2, 3, 4.0f);

    m.set(3, 0, -7.0f);
    m.set(3, 1, 6.0f);
    m.set(3, 2, 6.0f);
    m.set(3, 3, 2.0f);

    Matrix<4> inverse = m.inverse();

    ASSERT_FLOAT_EQ(-0.04074f, inverse.get(0, 0));
    ASSERT_FLOAT_EQ(-0.07778f, inverse.get(0, 1));
    ASSERT_FLOAT_EQ(0.14444f, inverse.get(0, 2));
    ASSERT_FLOAT_EQ(-0.22222f, inverse.get(0, 3));

    ASSERT_FLOAT_EQ(-0.07778f, inverse.get(1, 0));
    ASSERT_FLOAT_EQ(0.03333f, inverse.get(1, 1));
    ASSERT_FLOAT_EQ(0.36667f, inverse.get(1, 2));
    ASSERT_FLOAT_EQ(-0.33333f, inverse.get(1, 3));

    ASSERT_FLOAT_EQ(-0.02901f, inverse.get(2, 0));
    ASSERT_FLOAT_EQ(-0.14630f, inverse.get(2, 1));
    ASSERT_FLOAT_EQ(-0.10926f, inverse.get(2, 2));
    ASSERT_FLOAT_EQ(0.12963f, inverse.get(2, 3));

    ASSERT_FLOAT_EQ(0.17778f, inverse.get(3, 0));
    ASSERT_FLOAT_EQ(0.06667f, inverse.get(3, 1));
    ASSERT_FLOAT_EQ(-0.26667f, inverse.get(3, 2));
    ASSERT_FLOAT_EQ(0.33333f, inverse.get(3, 3));

    return true;
}

TEST(matrix4_inverse_mul_test)
{
    Matrix<4> a;

    a.set(0, 0, 3.0f);
    a.set(0, 1, -9.0f);
    a.set(0, 2, 7.0f);
    a.set(0, 3, 3.0f);

    a.set(1, 0, 3.0f);
    a.set(1, 1, -8.0f);
    a.set(1, 2, 2.0f);
    a.set(1, 3, -9.0f);

    a.set(2, 0, -4.0f);
    a.set(2, 1, 4.0f);
    a.set(2, 2, 4.0f);
    a.set(2, 3, 1.0f);

    a.set(3, 0, -6.0f);
    a.set(3, 1, 5.0f);
    a.set(3, 2, 1.0f);
    a.set(3, 3, 1.0f);

    Matrix<4> b;

    b.set(0, 0, 8.0f);
    b.set(0, 1, 2.0f);
    b.set(0, 2, 2.0f);
    b.set(0, 3, 2.0f);

    b.set(1, 0, 3.0f);
    b.set(1, 1, -1.0f);
    b.set(1, 2, 7.0f);
    b.set(1, 3, 0.0f);

    b.set(2, 0, 7.0f);
    b.set(2, 1, 0.0f);
    b.set(2, 2, 5.0f);
    b.set(2, 3, 4.0f);

    b.set(3, 0, 6.0f);
    b.set(3, 1, -2.0f);
    b.set(3, 2, 0.0f);
    b.set(3, 3, 5.0f);

    Matrix<4> c = a * b;

    Matrix<4> d = c * b.inverse();

    ASSERT_TRUE(a == d);

    return true;
}

TEST(transform_point_scale)
{
    Matrix<4> transform = Matrix<4>().scale(2.0f, 3.0f, 4.0f);

    Tuple p = Tuple::point(-4.0f, 6.0f, 8.0f);

    Tuple result = transform * p;

    ASSERT_TRUE(result == Tuple::point(-8.0f, 18.0f, 32.0f));

    return true;
}

TEST(transform_vector_scale)
{
    Matrix<4> transform = Matrix<4>().scale(2.0f, 3.0f, 4.0f);

    Tuple v = Tuple::vector(-4.0f, 6.0f, 8.0f);

    Tuple result = transform * v;

    ASSERT_TRUE(result == Tuple::vector(-8.0f, 18.0f, 32.0f));

    return true;
}

TEST(transform_vector_inverse_scale)
{
    Matrix<4> transform = Matrix<4>()
        .scale(2.0f, 3.0f, 4.0f)
        .inverse();

    Tuple v = Tuple::vector(-4.0f, 6.0f, 8.0f);

    Tuple result = transform * v;

    ASSERT_TRUE(result == Tuple::vector(-2.0f, 2.0f, 2.0f));

    return true;
}

TEST(transform_point_reflect)
{
    Matrix<4> transform = Matrix<4>().scale(-1.0f, 1.0f, 1.0f);

    Tuple p = Tuple::point(2.0f, 3.0f, 4.0f);

    Tuple result = transform * p;

    ASSERT_TRUE(result == Tuple::point(-2.0f, 3.0f, 4.0f));

    return true;
}

TEST(transform_rotate_x)
{
    Tuple p = Tuple::point(0.0f, 1.0f, 0.0f);

    Matrix<4> half_quarter = Matrix<4>().rotate_x(M_PI / 4.0f);
    Matrix<4> full_quarter = Matrix<4>().rotate_x(M_PI / 2.0f);

    Tuple result1 = half_quarter * p;
    Tuple result2 = full_quarter * p;

    ASSERT_TRUE(result1 == Tuple::point(0.0f, sqrt(2.0f) / 2.0f, sqrt(2.0f) / 2.0f));
    ASSERT_TRUE(result2 == Tuple::point(0.0f, 0.0f, 1.0f));

    return true;
}

TEST(transform_rotate_y)
{
    Tuple p = Tuple::point(0.0f, 0.0f, 1.0f);

    Matrix<4> half_quarter = Matrix<4>().rotate_y(M_PI / 4.0f);
    Matrix<4> full_quarter = Matrix<4>().rotate_y(M_PI / 2.0f);

    Tuple result1 = half_quarter * p;
    Tuple result2 = full_quarter * p;

    ASSERT_TRUE(result1 == Tuple::point(sqrt(2.0f) / 2.0f, 0.0f, sqrt(2.0f) / 2.0f));
    ASSERT_TRUE(result2 == Tuple::point(1.0f, 0.0f, 0.0f));

    return true;
}

TEST(transform_rotate_z)
{
    Tuple p = Tuple::point(0.0f, 1.0f, 0.0f);

    Matrix<4> half_quarter = Matrix<4>().rotate_z(M_PI / 4.0f);
    Matrix<4> full_quarter = Matrix<4>().rotate_z(M_PI / 2.0f);

    Tuple result1 = half_quarter * p;
    Tuple result2 = full_quarter * p;

    ASSERT_TRUE(result1 == Tuple::point(-sqrt(2.0f) / 2.0f, sqrt(2.0f) / 2.0f, 0.0f));
    ASSERT_TRUE(result2 == Tuple::point(-1.0f, 0.0f, 0.0f));

    return true;
}

TEST(shearing)
{
    Matrix<4> transform = Matrix<4>()
        .shear(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

    Tuple p = Tuple::point(2.0f, 3.0f, 4.0f);

    Tuple result = transform * p;

    ASSERT_TRUE(result == Tuple::point(5.0f, 3.0f, 4.0f));

    return true;
}