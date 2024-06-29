#include "math.h"

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

template bool Matrix<4>::operator==(const Matrix &m) const;
template bool Matrix<3>::operator==(const Matrix &m) const;
template bool Matrix<2>::operator==(const Matrix &m) const;

template <size_t N>
bool Matrix<N>::operator==(const Matrix &m) const
{
    for (size_t row = 0; row < N; row++)
    {
        for (size_t col = 0; col < N; col++)
        {
            if (fabs(this->get(row, col) - m.get(row, col)) > EPSILON)
            {
                return false;
            }
        }
    }

    return true;
}
