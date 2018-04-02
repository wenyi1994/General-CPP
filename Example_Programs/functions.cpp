#include <iostream>
using namespace std;

int power(int a, int b)
{
    if(b == 0 && a == 0) return 0;
	else if(b == 0 && a != 0) return 1;
	else {int i = 1; while(b--) i *= a; return i;}
}

void print_all(int array[], int length)
{
    for(int i = 0; i<length; i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

int fibonacci(int n)
{
    if(n == 1 || n == 2) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}

void swap_value(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap_ref(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int sum_arr(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++) total += arr[i];
    return total;
}

int sum_arr(int * arr_begin, int * arr_end)
{
    int total = 0;
    while(arr_begin < arr_end) total += *arr_begin++;
    return total;
}

int main()
{
    cout<<"3^4 = "<<power(3,4)<<endl;

    int numbers[10];
    for(int i = 0; i<10; i++) numbers[i] = i;
    int count = sizeof(numbers) / sizeof(int);
    print_all(numbers,count);

    cout<<"sum of numbers = "<<sum_arr(numbers,numbers+10)<<endl;

    cout<<"6. number in Fibonacci Sequence is: "<<fibonacci(6)<<endl;

    int x = 3, y = 5;
    swap_value(x,y);
    cout<<"swap x,y by value pass: "<<"x = "<<x<<","<<"y = "<<y<<endl;
    swap_ref(x,y);
    cout<<"swap x,y by value pass: "<<"x = "<<x<<","<<"y = "<<y<<endl;
    return 0;
}