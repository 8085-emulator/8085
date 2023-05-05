#include "ALLHEADER.h"
#include "functions.h"

void SHLD(string arg1 , string reg[] , bool flag[] , map <string , string> &mem)
{
    if(arg1.length() == 4 && validAddr(arg1) && reg[5] != "" && reg[6] != "" && mem.empty() == false)
    {
        mem[arg1] = reg[6];
        mem[incrAddr(arg1)] = reg[5];
    }
    else
    {
        cout << "Error : Invalid content." << endl;
        cout << "The program will quit." << endl;
        exit(0);
    }
}
