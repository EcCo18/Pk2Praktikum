#include <iostream>
#include "Matrix/Matrix.h"

int main(void)
{
    Matrix<int> mat1(2);

    mat1.set(0, 0, 1);
    mat1.set(0, 1, 3);
    mat1.set(1, 0, 4);
    mat1.set(1, 1, 2);

    std::cout << mat1;
}