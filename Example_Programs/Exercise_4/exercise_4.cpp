#include "Vector.h"
#include "Matrix.h"
#include <iostream>

using namespace std;

int main()
{
    cout<<"Matrix A = B:"<<endl;
    Matrix A(3,5);
    // A.copy(5.);
    A = 5.;
    // Matrix B (A);
    Matrix B = A;
    // B.print();
    cout<<B;

    cout<<"Vector v1:"<<endl;
    Vector v1(5);
    // v1.copy(2.);
    v1 = 2.;
    // v1.print();
    cout<<v1;

    cout<<"Replace Matrix B at (2,2) with 2:"<<endl;
    // B.setData(2,2,2);
    B(2,2) = 2.;
    // B.print();
    cout<<B;

    cout<<"Vector v2 = B * v1:"<<endl;
    // Vector v2(B.product(v1));
    Vector v2 = B * v1;
    // v2.print();
    cout<<v2;

    cout<<"A.Transpose:"<<endl;
    // A.transpose().print();
    cout<<A.transpose();

    cout<<"C = B * A:"<<endl;
    // Matrix C(B.product(A));
    Matrix C = B * A;
    // C.print();
    cout<<C;
    return 0;
}