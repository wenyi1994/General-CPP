#include <iostream>
#include <iomanip>
#include "Matrix.h"
using namespace std;

Matrix::Matrix()
{}

void Matrix::allocate()
{
    dataPtr = new double *[_rows];
    dataPtr[0] = new double [_rows*_cols];
    for (int i = 1; i<_rows; i++)
        dataPtr[i] = dataPtr[0]+i*_cols;
}

Matrix::Matrix(int row, int col)
{
    _rows = row;
    _cols = col;
    allocate();
}

Matrix::Matrix(const Matrix & m)
{
    _rows = m._rows;
    _cols = m._cols;
    allocate();
    for(int i = 0; i<_rows; i++)
        for(int j = 0; j<_cols; j++)
            dataPtr[i][j] = m.dataPtr[i][j];
}

Matrix::~Matrix()
{
    delete [] dataPtr[0];
    delete [] dataPtr;
}

Matrix & Matrix::operator=(Matrix & m)
{
    if(_rows != m._rows || _cols != m._cols)
    {
        delete [] dataPtr[0];
        delete [] dataPtr;
        _rows = m._rows;
        _cols = m._cols;
        allocate();
    }
    for(int i = 0; i<_rows; i++)
        for(int j = 0; j<_cols; j++)
            dataPtr[i][j] = m.dataPtr[i][j];
    return *this;
}

Matrix & Matrix::operator=(double x)
{
    for(int i = 0; i<_rows; i++)
        for(int j = 0; j<_cols; j++)
            dataPtr[i][j] = x;
    return *this;
}

const double Matrix::operator()(int m, int n) const
{
    if(m>=_rows || n>=_cols)
    {
        cerr<<"out of size"<<endl;
        exit(0);
    }
    return dataPtr[m][n];
}

double & Matrix::operator()(int m, int n)
{
    if(m>=_rows || n>=_cols)
    {
        cerr<<"out of size"<<endl;
        exit(0);
    }
    return dataPtr[m][n];
}

int Matrix::getRows()
{
    return _rows;
}

int Matrix::getCols()
{
    return _cols;
}

Matrix Matrix::transpose()
{
    Matrix tmp(_cols, _rows);
    for(int i = 0; i<_rows; i++)
        for(int j = 0; j<_cols; j++)
            tmp.dataPtr[j][i] = dataPtr[i][j];
    *this = tmp;
    return *this;
}

Matrix Matrix::operator+(Matrix & m)
{
    if(_rows!=m._rows || _cols!=m._cols)
    {
        cerr<<"different dimensions"<<endl;
        exit(0);
    }
    for(int i=0; i<_rows; i++)
        for(int j=0; j<_cols; j++)
            dataPtr[i][j] += m.dataPtr[i][j];
    return *this;
}

Matrix Matrix::operator-(Matrix & m)
{
    if(_rows!=m._rows || _cols!=m._cols)
    {
        cerr<<"different dimensions"<<endl;
        exit(0);
    }
    for(int i=0; i<_rows; i++)
        for(int j=0; j<_cols; j++)
            dataPtr[i][j] -= m.dataPtr[i][j];
    return *this;
}

const Vector Matrix::operator*(Vector v)
{
    if(_cols!=v.getSize())
    {
        cerr<<"dimension not match"<<endl;
        exit(0);
    }
    Vector tmp(_rows);
    for(int i=0; i<_rows; i++)
    {
        tmp[i] = 0;
        for(int j=0; j<_cols; j++)
            tmp[i] += dataPtr[i][j] * v[i];
    }
    return tmp;
}

const Matrix Matrix::operator*(Matrix m)
{
    if(_cols!=m._rows || _rows!=m._cols)
    {
        cerr<<"dimension not match"<<endl;
        exit(0);
    }
    Matrix tmp(_rows, m._cols);
    for(int i=0; i<_rows; i++)
    {
        for(int j=0; j<m._cols; j++)
        {
            tmp(i,j) = 0;
            for(int k=0; k<_cols; k++)
                tmp(i,j) += dataPtr[i][k] * m.dataPtr[k][i];
        }
    }
    return tmp;
}

Matrix Matrix::operator*(double s)
{
    for(int i = 0; i<_rows; i++)
        for(int j = 0; j<_cols; j++)
            dataPtr[i][j] *= s;
    return *this;
}

Matrix operator*(double s, Matrix m)
{
    return m * s;
}

ostream & operator<<(ostream & os, Matrix m)
{
    for(int i=0; i<m.getRows(); i++)
    {
        for(int j=0; j<m.getCols(); j++)
            os<<setw(8)<<m(i,j)<<"  ";
        os<<endl;
    }
    return os;
}