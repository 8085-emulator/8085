#include "ALLHEADER.h"
#inlcude "functions.h"

void STAX(string arg1 , string reg[] , bool flag[] , map <string , string> &mem)
{
    if(arg1.length() == 4 && validRp(arg1))
    {
        string a += reg[regNo(arg)] + reg[regNo(arg) + 1];
        if(validAddr(a))
            mem[a] = reg[0];
        else
        {
            cout << "Error : Inavalid content." << endl;
            exit(0);
        }
    }
    else
    {
        cout << "Error : Invalid content.\nThe program will quit." << endl;
        exit(0);
    }
}
