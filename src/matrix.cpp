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
    return data[0][0] * cofactor(0, 0) +
           data[0][1] * cofactor(0, 1) +
           data[0][2] * cofactor(0, 2);
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