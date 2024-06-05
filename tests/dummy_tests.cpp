#include "test_framework.h"

TEST(dummy_test)
{
    ASSERT_EQ(1, 1);
    ASSERT_FLOAT_EQ(1.0, 1.0);
    ASSERT_TRUE(true);
    ASSERT_FALSE(false);

    return true;
}