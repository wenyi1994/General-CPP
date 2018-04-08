#include <iostream>
using namespace std;

#define _LEN_CHAR 30

char * invert_char(char * str)
{
    char *pBegin = str;                     // begin of string
    char *pEnd = str + strlen(str) - 1;     // end of string
    while(pBegin < pEnd)                    // swap begin and end of the string
    {
        char tmp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = tmp;
        pBegin++;
        pEnd--;
    }
    return str;
}

int main()
{
    while(1)
    {
        // get string by typing in
        cout<<"Type in a string, it will be inverted. Type in /end to end."<<endl;
        char str[_LEN_CHAR];
        cin.getline(str,_LEN_CHAR);
        if(strcmp(str,"/end") == 0) break;
        cout<<invert_char(str)<<endl;
    }
    return 0;
}