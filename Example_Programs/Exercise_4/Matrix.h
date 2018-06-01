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
    friend ostream & operator<<(ostream & os, Matrix m);
    void allocate();

    Matrix & operator=(Matrix & m);
    Matrix & operator=(double x);
    const double operator()(int m, int n) const;
    double & operator()(int m, int n);
    int getRows();
    int getCols();
    Matrix transpose();
    Matrix operator+(Matrix & m);
    Matrix operator-(Matrix & m);
    const Vector operator*(Vector v);
    const Matrix operator*(Matrix m);
    Matrix operator*(double s);
    friend Matrix operator*(double s, Matrix m);
};

#endif