#include "ALLHEADER.h"
#include "functions.h"

void ADI(string arg , string reg[] , bool flag)
{
    if(arg.length() == 2)
    {
        if(validData(arg))
        {
            reg[0] = hexAdd(arg , reg[0] , flag , true);
        }
        else
        {
            cout << "Error : " << arg << "\nInvalid data.\nThe program will quit." << endl;
            exit(0);
        }
    }
    else
    {
        cout << "Error : " << arg << "\nInvalid data.\nthe program will quit." << endl;
        exit(0);
    }
}
