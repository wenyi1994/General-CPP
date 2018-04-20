#include<iostream>
#include<iomanip>
#include "Vector.h"
using namespace std;

Vector::Vector()
{}

Vector::Vector(int N)
{
    dim = N;
    dataPtr = new double[N];
}

Vector::Vector(const Vector & v)
{
    dim = v.dim;
    dataPtr = new double[dim];
    for(int i=0; i<dim; i++)
        dataPtr[i] = v.dataPtr[i];
}

Vector::~Vector()
{
    delete [] dataPtr;
}

void Vector::print(int w)
{
    for(int i=0; i<dim; i++)
        cout<<setw(w)<<dataPtr[i]<<endl;
}

Vector & Vector::copy(Vector & v)
{
    if(dim != v.dim)
    {
        delete [] dataPtr;
        dim = v.getSize();
        dataPtr = new double[dim];
    }
    for(int i=0; i<dim; i++)
        dataPtr[i] = v.dataPtr[i];
    return *this;
}

Vector & Vector::copy(double x)
{
    for(int i=0; i<dim; i++)
        dataPtr[i] = x;
    return *this;
}

double Vector::getData(int count)
{
    if(count>=dim)
    {
        cerr<<"out of size"<<endl;
        exit(0);
    }
    return dataPtr[count];
}

void Vector::setData(int count, double x)
{
    if(count>=dim)
    {
        cerr<<"out of size"<<endl;
        exit(0);
    }
    dataPtr[count] = x;
}

int Vector::getSize()
{
    return dim;
}

Vector Vector::plus(Vector v)
{
    if(dim!=v.dim)
    {
        cerr<<"different dimensions"<<endl;
        exit(0);
    }
    for(int i=0; i<dim; i++)
        dataPtr[i] = dataPtr[i] + v.dataPtr[i];
    return *this;
}

Vector Vector::minus(Vector v)
{
    if(dim!=v.dim)
    {
        cerr<<"different dimensions"<<endl;
        exit(0);
    }
    for(int i=0; i<dim; i++)
        dataPtr[i] = dataPtr[i] - v.dataPtr[i];
    return *this;
}

double Vector::dotProduct(Vector v)
{
    if(dim!=v.dim)
    {
        cerr<<"different dimensions"<<endl;
        exit(0);
    }
    double temp = 0;
    for(int i=0; i<dim; i++)
        temp += dataPtr[i] * v.dataPtr[i];
    return temp;
}
Vector Vector::scale(double s)
{
    for(int i=0; i<dim; i++)
        dataPtr[i] *= s;
    return *this;
}