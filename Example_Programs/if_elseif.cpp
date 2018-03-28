#include <iostream>
using namespace std;

int main()
{
    int x = 5;
    if(x > 3) x = 0;
    else if(x > 4) x = 1;
    else x = 2;
    cout<<"x = "<<x<<endl;
    return 0;
}