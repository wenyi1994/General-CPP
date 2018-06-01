#include "Vector.h"
#ifndef MATRIX_
#define MATRIX_

class Matrix
{
private:
    int _rows;
    int _cols;
    double **dataPtr;
public:
    Matrix();
    Matrix(int row, int col);
    Matrix(const Matrix & m);
    ~Matrix();
    void print(int w=8);
    void allocate();

    Matrix & copy(Matrix & m);
    Matrix & copy(double x);
    double getData(int m, int n);
    void setData(int m, int n, double x);
    int getRows();
    int getCols();
    Matrix transpose();
    Matrix plus(Matrix & m);
    Matrix minus(Matrix & m);
    const Vector product(Vector v);
    const Matrix product(Matrix m);
};

#endif
