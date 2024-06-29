#include "matrix.h"

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
