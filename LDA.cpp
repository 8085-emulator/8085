#include "ALLHEADER.h"
#include "functions.h"

void LDA(string arg1 , string reg[] , bool flag[] , map <string,string> &mem)
{
    if(arg1.length() == 4)
    {
        if(validAddr(arg1))
            reg[0] = mem[arg1];
        else
        {
            cout << "Error : Invalid address." << endl;
            exit(0);
        }
    }
    else
    {
        cout << "Error : Invalid agrument." << endl;
        exit(0);
    }
}
