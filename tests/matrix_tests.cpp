#include "test_framework.h"

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

    // 3 5 0
    // 2 -1 -7
    // 6 -1 5

    // 3 5
    // 6 -1

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