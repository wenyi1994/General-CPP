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

Vector & Vector::operator=(Vector & v)
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

Vector & Vector::operator=(double x)
{
    for(int i=0; i<dim; i++)
        dataPtr[i] = x;
    return *this;
}

const double Vector::operator[](int count) const
{
    if(count>=dim)
    {
        cerr<<"out of size"<<endl;
        exit(0);
    }
    return dataPtr[count];
}

double & Vector::operator[](int count)
{
    if(count>=dim)
    {
        cerr<<"out of size"<<endl;
        exit(0);
    }
    return dataPtr[count];
}

int Vector::getSize()
{
    return dim;
}

Vector Vector::operator+(Vector v)
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

Vector Vector::operator-(Vector v)
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

double Vector::operator*(Vector v)
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

Vector Vector::operator*(double s)
{
    for(int i=0; i<dim; i++)
        dataPtr[i] *= s;
    return *this;
}

Vector operator*(double s, Vector v)
{
    return v*s;
}

ostream & operator<<(ostream & os, Vector v)
{
    for(int i=0; i<v.getSize(); i++)
        os<<setw(8)<<v[i]<<endl;
        return os;
}