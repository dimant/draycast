#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>

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

    void transpose();
};

#endif