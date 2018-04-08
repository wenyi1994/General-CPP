#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#define PI 3.1415926

double * matrix_product(double * mat_22, double * vec_2)
{
    static double r[2];
    r[0] = mat_22[0] * vec_2[0] + mat_22[1] * vec_2[1];
    r[1] = mat_22[2] * vec_2[0] + mat_22[3] * vec_2[1];
    return r;
}

double * vec_scale(double * vec_2, double s)
{
    static double r[2];
    r[0] = s * vec_2[0];
    r[1] = s * vec_2[1];
    return r;
}

double * vec_add(double * vec_2_1, double * vec_2_2)
{
    static double r[2];
    r[0] = vec_2_1[0] + vec_2_2[0];
    r[1] = vec_2_1[1] + vec_2_2[1];
    return r;
}

void print_mat22(const double *mat)
{
    cout<<setw(6)<<mat[0]<<setw(6)<<mat[1]<<endl;
    cout<<setw(6)<<mat[2]<<setw(6)<<mat[3]<<endl;
}

void print_vec2(const double *vec)
{
    cout<<setw(6)<<vec[0]<<endl;
    cout<<setw(6)<<vec[1]<<endl;
}

double * explicit_euler(double * mat_22, double * vec_2, double h, int count)
{
    // static double r[2];
    if(count == 0)
    {
        return vec_2;
    }
    else
    {
        vec_2 = vec_add(vec_scale(matrix_product(mat_22, vec_2), h),vec_2);
        // r[0] = h * mat_22[0] * vec_2[0] + h * mat_22[1] * vec_2[1] + vec_2[0];
        // r[1] = h * mat_22[2] * vec_2[0] + h * mat_22[3] * vec_2[1] + vec_2[1];
        // return explicit_euler(mat_22, r, h, count-1);
        return explicit_euler(mat_22, vec_2, h, count-1);
    }
}

int main()
{
    double mat22[] = {0.0,1.0,-9.81/0.2,0.0};
    double vec2[] = {PI/6,0.0};
    double vec2_2[] = {3.0, 4.5};
    double * vec = vec_add(vec2_2,vec2);
    print_vec2(vec);
    cout<<"x' = "<<endl;
    print_mat22(mat22);
    cout<<"x0 = "<<endl;
    print_vec2(vec2);
    cout<<"Explicit Euler Method after 10000 steps: "<<endl;
    print_vec2(explicit_euler(mat22,vec2,0.0005,10000));
    return 0;
}