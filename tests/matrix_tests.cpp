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