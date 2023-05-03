#include "ALLHEADER.h"
#include "functions.h"

string JMP(string a , string reg[] , bool flag[])
{
    if(validAddr(a))
        return a;
    else
    {
        cout << "Error.\nInvalid address : " << a << endl;
        cout << "The program will quit.";
        exit(0);
    }
}