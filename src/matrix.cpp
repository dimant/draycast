#include "math.h"
#include <algorithm>

#include "matrix.h"
#include "tuple.h"

template Matrix<4>::Matrix();
template Matrix<3>::Matrix();
template Matrix<2>::Matrix();

template <size_t N>
Matrix<N>::Matrix()
{
    for (size_t row = 0; row < N; row++)
    {
        for (size_t col = 0; col < N; col++)
        {
            data[row][col] = 0.0f;
        }
    }
}

template bool Matrix<4>::operator==(const Matrix<4> &m) const;
template bool Matrix<3>::operator==(const Matrix<3> &m) const;
template bool Matrix<2>::operator==(const Matrix<2> &m) const;

template <size_t N>
bool Matrix<N>::operator==(const Matrix<N> &m) const
{
    for (size_t row = 0; row < N; row++)
    {
        for (size_t col = 0; col < N; col++)
        {
            if (fabs(this->data[row][col] - m.data[row][col]) > EPSILON)
            {
                return false;
            }
        }
    }

    return true;
}

template Matrix<4> Matrix<4>::operator*(const Matrix<4> &m) const;
template Matrix<3> Matrix<3>::operator*(const Matrix<3> &m) const;
template Matrix<2> Matrix<2>::operator*(const Matrix<2> &m) const;

template <size_t N>
Matrix<N> Matrix<N>::operator*(const Matrix<N> &m) const
{
    Matrix<N> result;

    for (size_t row = 0; row < N; row++)
    {
        for (size_t col = 0; col < N; col++)
        {
            float c = 0.0f;

            for (size_t i = 0; i < N; i++)
            {
                c += this->data[row][i] * m.data[i][col];
            }

            result.data[row][col] = c;
        }
    }

    return result;
}

#include <stdio.h>

template void Matrix<4>::transpose();
template void Matrix<3>::transpose();
template void Matrix<2>::transpose();

template <size_t N>
void Matrix<N>::transpose()
{
    for (size_t row = 0; row < N; row++)
    {
        for (size_t col = row; col < N; col++)
        {
            std::swap(data[row][col], data[col][row]);
        }
    }

}

template <>
float Matrix<2>::determinant() const
{
    return data[0][0] * data[1][1] - data[0][1] * data[1][0];
}

template <>
float Matrix<3>::determinant() const
{
    return data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) -
           data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]) +
           data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);
}

template <>
float Matrix<4>::determinant() const
{
    return data[0][0] * cofactor(0, 0) +
           data[0][1] * cofactor(0, 1) +
           data[0][2] * cofactor(0, 2) +
           data[0][3] * cofactor(0, 3);
}

template Matrix<3> Matrix<4>::submatrix(size_t row, size_t col) const;
template Matrix<2> Matrix<3>::submatrix(size_t row, size_t col) const;

template <size_t N>
Matrix<N - 1> Matrix<N>::submatrix(size_t row, size_t col) const
{
    Matrix<N - 1> result;

    size_t r = 0;
    size_t c = 0;

    for (size_t i = 0; i < N; i++)
    {
        if (i == row) continue;

        c = 0;

        for (size_t j = 0; j < N; j++)
        {
            if (j == col) continue;

            result.set(r, c, data[i][j]);
            c++;
        }

        r++;
    }

    return result;
}

template float Matrix<3>::minor(size_t, size_t) const;
template float Matrix<4>::minor(size_t, size_t) const;

template <size_t N>
float Matrix<N>::minor(size_t row, size_t col) const
{
    return submatrix(row, col).determinant();
}

template float Matrix<3>::cofactor(size_t, size_t) const;
template float Matrix<4>::cofactor(size_t, size_t) const;

template <size_t N>
float Matrix<N>::cofactor(size_t row, size_t col) const
{
    return (row + col) % 2 == 0 ? minor(row, col) : -minor(row, col);
}

template bool Matrix<2>::invertible() const;
template bool Matrix<3>::invertible() const;
template bool Matrix<4>::invertible() const;

template <size_t N>
bool Matrix<N>::invertible() const
{
    return fabs(determinant()) < EPSILON ? false : true;
}

template <>
Matrix<2> Matrix<2>::inverse() const
{
    Matrix<2> result;

    float det = determinant();

    result.set(0, 0, data[1][1] / det);
    result.set(0, 1, -data[0][1] / det);
    result.set(1, 0, -data[1][0] / det);
    result.set(1, 1, data[0][0] / det);

    return result;
}

template Matrix<3> Matrix<3>::inverse() const;
template Matrix<4> Matrix<4>::inverse() const;

template <size_t N>
Matrix<N> Matrix<N>::inverse() const
{
    Matrix<N> result;

    float det = determinant();

    for (size_t row = 0; row < N; row++)
    {
        for (size_t col = 0; col < N; col++)
        {
            float c = cofactor(row, col);

            result.set(col, row, c / det);
        }
    }

    return result;
}

template <>
Tuple Matrix<4>::operator*(const Tuple &t) const
{
    Tuple result;

    result.x = data[0][0] * t.x + data[0][1] * t.y + data[0][2] * t.z + data[0][3] * t.w;
    result.y = data[1][0] * t.x + data[1][1] * t.y + data[1][2] * t.z + data[1][3] * t.w;
    result.z = data[2][0] * t.x + data[2][1] * t.y + data[2][2] * t.z + data[2][3] * t.w;
    result.w = data[3][0] * t.x + data[3][1] * t.y + data[3][2] * t.z + data[3][3] * t.w;

    return result;
}

template <>
Matrix<4> Matrix<4>::translate(float x, float y, float z)
{
    Matrix<4> t;

    t.set(0, 0, 1);
    t.set(1, 1, 1);
    t.set(2, 2, 1);
    t.set(3, 3, 1);

    t.set(0, 3, x);
    t.set(1, 3, y);
    t.set(2, 3, z);

    return t;
}

template <>
Matrix<4> Matrix<4>::scale(float x, float y, float z)
{
    Matrix<4> s;

    s.set(0, 0, x);
    s.set(1, 1, y);
    s.set(2, 2, z);
    s.set(3, 3, 1);

    return s;
}

template <>
Matrix<4> Matrix<4>::rotate_x(float radians)
{
    Matrix<4> r;

    r.set(0, 0, 1);
    r.set(1, 1, cos(radians));
    r.set(1, 2, -sin(radians));
    r.set(2, 1, sin(radians));
    r.set(2, 2, cos(radians));
    r.set(3, 3, 1);

    return r;
}

template <>
Matrix<4> Matrix<4>::rotate_y(float radians)
{
    Matrix<4> r;

    r.set(0, 0, cos(radians));
    r.set(0, 2, sin(radians));
    r.set(1, 1, 1);
    r.set(2, 0, -sin(radians));
    r.set(2, 2, cos(radians));
    r.set(3, 3, 1);

    return r;
}

template <>
Matrix<4> Matrix<4>::rotate_z(float radians)
{
    Matrix<4> r;

    r.set(0, 0, cos(radians));
    r.set(0, 1, -sin(radians));
    r.set(1, 0, sin(radians));
    r.set(1, 1, cos(radians));
    r.set(2, 2, 1);
    r.set(3, 3, 1);

    return r;
}