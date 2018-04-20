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

void Matrix::print(int w)
{
    for(int i=0; i<_rows; i++)
    {
        for(int j=0; j<_cols; j++)
            cout<<setw(w)<<dataPtr[i][j]<<"  ";
        cout<<endl;
    }
}

Matrix & Matrix::copy(Matrix & m)
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

Matrix & Matrix::copy(double x)
{
    for(int i = 0; i<_rows; i++)
        for(int j = 0; j<_cols; j++)
            dataPtr[i][j] = x;
    return *this;
}

double Matrix::getData(int m, int n)
{
    if(m>=_rows || n>=_cols)
    {
        cerr<<"out of size"<<endl;
        exit(0);
    }
    return dataPtr[m][n];
}

void Matrix::setData(int m, int n, double x)
{
    if(m>=_rows || n>=_cols)
    {
        cerr<<"out of size"<<endl;
        exit(0);
    }
    dataPtr[m][n] = x;
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
    copy(tmp);
    return *this;
}

Matrix Matrix::plus(Matrix & m)
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

Matrix Matrix::minus(Matrix & m)
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

const Vector Matrix::product(Vector v)
{
    if(_cols!=v.getSize())
    {
        cerr<<"dimension not match"<<endl;
        exit(0);
    }
    Vector tmp(_rows);
    for(int i=0; i<_rows; i++)
    {
        tmp.setData(i,0);
        for(int j=0; j<_cols; j++)
            tmp.setData(i, tmp.getData(i)+dataPtr[i][j]*v.getData(j));
    }
    return tmp;
}

const Matrix Matrix::product(Matrix m)
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
            tmp.setData(i,j,0);
            for(int k=0; k<_cols; k++)
                tmp.setData(i,j,tmp.getData(i,j)+dataPtr[i][k]*m.dataPtr[k][i]);
        }
    }
    return tmp;
}