#include <stdlib.h>
#include <string.h>

#include "matrix.h"

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