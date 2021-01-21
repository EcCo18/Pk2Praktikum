#include <iostream>

#ifndef MATRIX_H
#define MATRIX_H

template <class T>
class Matrix
{
    private:
    int n;
    T *array[];

    public:

    Matrix<T>(int dimension);
    ~Matrix<T>();

    //setter getter
    void set(int row, int column, T value);
    T get(int row, int column);
        
    //inline
    friend std::ostream &operator<<(std::ostream& cout, Matrix<T> &mat)
    {
        for(int i=0; i<mat.getDimension(); i++)
        {
            for(int p=0; p<mat.getDimension(); p++)
            {
                cout << mat.get(i, p) << "  ";
            }
            cout << std::endl;
        }
        return cout;
    }

    inline int getDimension()
    {
        return this->n;
    }
};

//constructor
template <class T>
Matrix<T>::Matrix(int dimension) : n(dimension)
{
    *array = new T[n];

    for(int i=0; i<n; i++)
    {
        array[i] = new T[n];
    }
}

template <class T>
Matrix<T>::~Matrix()
{
    std::cout << "destructor called!" << std::endl;
}

//getter setter
template <class T>
void Matrix<T>::set(int row, int column, T value)
{
    //check if pos is in matrix
    if(row < n && column < n)
    {
        array[row][column] = value;
    }
}

template <class T>
T Matrix<T>::get(int row, int column)
{
    if(row < n && row < n)
    {
        return array[row][column];
    }
    return -1;
}

#endif 