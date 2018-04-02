#include <iostream>
using namespace std;

int main()
{
    cout<<"Please enter your first name: ";
    char * firstName = new char[20];
    cin.getline(firstName,20);

    cout<<"Please enter your last name: ";
    char * lastName = new char[20];
    cin.getline(lastName,20);

    cout<<"And your address? ";
    char * address = new char[50];
    cin.getline(address,50);

    cout<<firstName<<" "<<lastName<<", you live in "<<address<<", right?"<<endl;

    delete [] firstName;
    delete [] lastName;
    delete [] address;
    return 0;
}