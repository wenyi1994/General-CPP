#include "Vector.h"
#include "Matrix.h"
#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

int main()
{
    // init time
    time_t nowtime = time(0);
    char buf[18];  
    strftime(buf,18,"%y%m%d_%H%M%S.dat",localtime(&nowtime));
    ofstream fout(buf);

    fout<<"running..."<<endl<<endl;

    fout<<"Matrix A = B:"<<endl;
    Matrix A(3,5);
    A = 5.;
    Matrix B = A;
    fout<<B;

    fout<<"Vector v1:"<<endl;
    Vector v1(5);
    v1 = 2.;
    fout<<v1;

    fout<<"Replace Matrix B at (2,2) with 2:"<<endl;
    B(2,2) = 2.;
    fout<<B;

    fout<<"Vector v2 = B * v1:"<<endl;
    Vector v2 = B * v1;
    fout<<v2;

    fout<<"A.Transpose:"<<endl;
    fout<<A.transpose();

    fout<<"C = B * A:"<<endl;
    Matrix C = B * A;
    fout<<C;

    fout<<endl<<"done!"<<endl;

    fout.close();

    return 0;
}