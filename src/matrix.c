#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "matrix.h"

#define EPSILON 0.00001

num *new_mat_zero(size_t size)
{
    num *m = malloc(sizeof(num));
    m = malloc(sizeof(num) * size);
    memset(m, 0, sizeof(num) * size);
    return m;
}

num *new_mat_data(const num *data, size_t size)
{
    mat4 m = malloc(sizeof(num) * size);
    memcpy(m, data, sizeof(num) * size);
    return m;
}

bool mat_eq(const num *a, const num *b, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (NABS(a[i] - b[i]) >= EPSILON)
        {
            return false;
        }
    }
    return true;
}

void free_mat(num **m)
{
    free(*m);
}

mat4 new_mat4_zero()
{
    return new_mat_zero(16);
}

mat4 new_mat4_data(const num *data)
{
    return new_mat_data(data, 16);
}

void free_mat4(mat4 *m)
{
    free_mat(m);
}

bool mat4_eq(const mat4 a, const mat4 b)
{
    return mat_eq(a, b, 16);
}

mat3 new_mat3_zero()
{
    return new_mat_zero(9);
}

mat3 new_mat3_data(const num *data)
{
    return new_mat_data(data, 9);
}

void free_mat3(mat3 *m)
{
    free_mat(m);
}

bool mat3_eq(const mat3 a, const mat3 b)
{
    return mat_eq(a, b, 9);
}

mat2 new_mat2_zero()
{
    return new_mat_zero(4);
}

mat2 new_mat2_data(const num *data)
{
    return new_mat_data(data, 4);
}

void free_mat2(mat2 *m)
{
    free_mat(m);
}

bool mat2_eq(const mat2 a, const mat2 b)
{
    return mat_eq(a, b, 4);
}
