#ifndef VECTOR_
#define VECTOR_
#include<iostream>
#include<iomanip>
using namespace std;
class Vector
{
private:
    int dim;
    double * dataPtr;
public:
    Vector();
    Vector(int N);
    Vector(const Vector & v);
    ~Vector();
    friend ostream & operator<<(ostream & os, Vector v);

    Vector & operator=(Vector & v);
    Vector & operator=(double x);
    const double operator[](int count) const;
    double & operator[](int count);
    int getSize();
    Vector operator+(Vector v);
    Vector operator-(Vector v);
    double operator*(Vector v);
    Vector operator*(double s);
    friend Vector operator*(double s, Vector v);
};

#endif