#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>

#include "tuple.h"

template <size_t N>
class Matrix
{
private:
    float data[N][N];

public:
    Matrix();

    float get(size_t row, size_t col) const
    {
        return data[row][col];
    }

    void set(size_t row, size_t col, float value)
    {
        data[row][col] = value;
    }

    bool operator==(const Matrix<N> &m) const;

    bool operator!=(const Matrix<N> &m)
    {
        return !(*this == m);
    }

    Matrix<N> operator*(const Matrix<N> &m) const;

    Tuple operator*(const Tuple &t) const;

    void transpose();

    float determinant() const;

    Matrix<N - 1> submatrix(size_t row, size_t col) const;

    float minor(size_t row, size_t col) const;

    float cofactor(size_t row, size_t col) const;

    bool invertible() const;

    static Matrix<N> identity();

    Matrix<N> inverse() const;

    Matrix<N> translate(float x, float y, float z);

    Matrix<N> scale(float x, float y, float z);

    Matrix<N> rotate_x(float radians);

    Matrix<N> rotate_y(float radians);

    Matrix<N> rotate_z(float radians);

    Matrix<N> shear(float xy, float xz, float yx, float yz, float zx, float zy);
};

#endif