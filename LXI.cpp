#include "ALLHEADER.h"
#include "functions.h"

void LXI (string arg1 , string arg2 , string reg[] , bool flag[] , map <string , string> &mem)
{
    if(arg1.length() == 1 && arg2.length() == 4)
    {
        if(arg1 == "M")
        {
            if(validAddr(arg2))
            {
                string a = "" , b ="";
                for(int i = 0 ; i < 2 ; i++)
                {
                    a += arg2[i];
                    b += arg2[i + 2];
                }
                reg[5] = a;
                reg[6] = b;
            }
            else
            {
                cout << "Error : Invalid address." << endl;
                exit(0);
            }
        }
        else
        {
            if(validRp(arg1) && validAddr(arg2))
            {
                string a = "" , b = "";
                for(int i = 0 ; i < 2 ; i++)
                {
                    a += arg2[i];
                    b += arg2[i + 2];
                }
                reg[regNo(arg1)] = a;
                reg[regNo(arg1) + 1] = b;
            }
            else
            {
                cout << "Error : Invalid content."  << endl;
                exit(0);
            }
        }
    }
    else
    {
        cout << "Error : Invalid content."  << endl;
        exit(0);
    }
}
