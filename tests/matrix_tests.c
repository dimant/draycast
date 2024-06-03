#include "test_framework.h"

#include "../src/matrix.h"

TEST(mat4_at_test)
{
    const num data[16] = {
        0.0, 1.0, 2.0, 3.0,
        4.0, 5.0, 6.0, 7.0,
        8.0, 9.0, 10.0, 11.0,
        12.0, 13.0, 14.0, 15.0};

    mat4 m = new_mat4_data(data);

    ASSERT_FLOAT_EQ(0.0f, MAT4_AT(m, 0, 0));
    ASSERT_FLOAT_EQ(3.0f, MAT4_AT(m, 0, 3));
    ASSERT_FLOAT_EQ(4.0f, MAT4_AT(m, 1, 0));
    ASSERT_FLOAT_EQ(6.0f, MAT4_AT(m, 1, 2));
    ASSERT_FLOAT_EQ(10.0f, MAT4_AT(m, 2, 2));
    ASSERT_FLOAT_EQ(12.0f, MAT4_AT(m, 3, 0));
    ASSERT_FLOAT_EQ(14.0f, MAT4_AT(m, 3, 2));

    MAT4_AT(m, 0, 0) = 1.0f;
    ASSERT_FLOAT_EQ(MAT4_AT(m, 0, 0), 1.0f);

    free_mat4(&m);

    return true;
}

TEST(mat4_eq_test)
{
    const num data[16] = {
        0.0, 1.0, 2.0, 3.0,
        4.0, 5.0, 6.0, 7.0,
        8.0, 9.0, 10.0, 11.0,
        12.0, 13.0, 14.0, 15.0};

    mat4 m1 = new_mat4_data(data);
    mat4 m2 = new_mat4_data(data);

    ASSERT_TRUE(mat4_eq(m1, m2));

    MAT4_AT(m2, 1, 0) = 1.0f;

    ASSERT_FALSE(mat4_eq(m1, m2));

    free_mat4(&m1);
    free_mat4(&m2);

    return true;
}

TEST(mat3_at_test)
{
    const num data[9] = {
        0.0, 1.0, 2.0,
        3.0, 4.0, 5.0,
        6.0, 7.0, 8.0};

    mat3 m = new_mat3_data(data);

    ASSERT_FLOAT_EQ(0.0f, MAT3_AT(m, 0, 0));
    ASSERT_FLOAT_EQ(3.0f, MAT3_AT(m, 1, 0));
    ASSERT_FLOAT_EQ(4.0f, MAT3_AT(m, 1, 1));
    ASSERT_FLOAT_EQ(6.0f, MAT3_AT(m, 2, 0));
    ASSERT_FLOAT_EQ(8.0f, MAT3_AT(m, 2, 2));

    MAT3_AT(m, 1, 0) = 1.0f;
    ASSERT_FLOAT_EQ(MAT3_AT(m, 1, 0), 1.0f);

    free_mat3(&m);

    return true;
}

TEST(mat3_eq_test)
{
    const num data[9] = {
        0.0, 1.0, 2.0,
        3.0, 4.0, 5.0,
        6.0, 7.0, 8.0};

    mat3 m1 = new_mat3_data(data);
    mat3 m2 = new_mat3_data(data);

    ASSERT_TRUE(mat3_eq(m1, m2));

    MAT3_AT(m2, 1, 0) = 1.0f;

    ASSERT_FALSE(mat3_eq(m1, m2));

    free_mat3(&m1);
    free_mat3(&m2);

    return true;
}

TEST(mat2_at_test)
{
    const num data[4] = {
        0.0, 1.0,
        2.0, 3.0};

    mat2 m = new_mat2_data(data);

    ASSERT_FLOAT_EQ(0.0f, MAT2_AT(m, 0, 0));
    ASSERT_FLOAT_EQ(1.0f, MAT2_AT(m, 0, 1));
    ASSERT_FLOAT_EQ(2.0f, MAT2_AT(m, 1, 0));
    ASSERT_FLOAT_EQ(3.0f, MAT2_AT(m, 1, 1));

    MAT2_AT(m, 1, 0) = 1.0f;
    ASSERT_FLOAT_EQ(MAT2_AT(m, 1, 0), 1.0f);

    free_mat2(&m);

    return true;
}

TEST(mat2_eq_test)
{
    const num data[4] = {
        0.0, 1.0,
        2.0, 3.0};

    mat2 m1 = new_mat2_data(data);
    mat2 m2 = new_mat2_data(data);

    ASSERT_TRUE(mat2_eq(m1, m2));

    MAT2_AT(m2, 1, 0) = 1.0f;

    ASSERT_FALSE(mat2_eq(m1, m2));

    free_mat3(&m1);
    free_mat3(&m2);

    return true;
}
