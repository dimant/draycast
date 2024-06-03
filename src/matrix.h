#ifndef MATRIX_H
#define MATRIX_H

#include "tuple.h"

typedef num *mat4;

typedef num *mat3;

typedef num *mat2;

#define MAT4_AT(m, r, c) ((m)[(r) * 4 + (c)])

#define MAT3_AT(m, r, c) ((m)[(r) * 3 + (c)])

#define MAT2_AT(m, r, c) ((m)[(r) * 2 + (c)])

mat4 new_mat4_zero();

mat4 new_mat4_data(const num *data);

void free_mat4(mat4 *m);

mat3 new_mat3_zero();

mat3 new_mat3_data(const num *data);

void free_mat3(mat3 *m);

mat2 new_mat2_zero();

mat2 new_mat2_data(const num *data);

void free_mat2(mat2 *m);

#endif