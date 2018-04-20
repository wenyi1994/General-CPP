#ifndef VECTOR_
#define VECTOR_

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
    void print(int w=8);

    Vector & copy(Vector & v);
    Vector & copy(double x);
    double getData(int count);
    void setData(int count, double x);
    int getSize();
    Vector plus(Vector v);
    Vector minus(Vector v);
    double dotProduct(Vector v);
    Vector scale(double s);
};

#endif