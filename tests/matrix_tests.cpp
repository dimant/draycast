#include "test_framework.h"

#include "../src/matrix.h"

TEST(matrix_access_test)
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