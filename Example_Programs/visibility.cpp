#include <iostream>
using namespace std;

int a = 1, b = 2;

int main()
{
    int a = 10;
    cout<<"global a = "<<::a<<endl;
    cout<<"local a = "<<a<<endl;
    {
        int b = 20; int c = 30;
        cout<<"global b = "<<::b<<endl;
        cout<<"local b = "<<b<<endl;
    }
    cout<<"global b without :: = "<<b<<endl;
    // cout<<"c = "<<c<<endl;       // c is not visiable
}