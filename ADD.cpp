#include "ALLADDRESS.h"
#include "functions.h"

void ADD(string agr1 , string reg[] , bool flag[] , map <string , string> &mem)
{
    if(arg1.length() == 1)
    {
        if(validReg(agr1) || validRP(arg1))
        {
            if(arg1 == 'M')
            {
                int regNo = registerNo(arg1);
                reg[0] = hexAdd(reg[regNo] , reg[0] , flag , true);
            }
            else
            {
                string addr = "";
                addr = addr + reg[5] + reg[6];
                if(addr >= "0000" && addr <= "FFFF")
                {
                    reg[0] = hexAdd(mem[addr] , reg[0] , flag , true);
                }
                else
                {
                    cout << "Error : " << arg1 << endl;
                    cout << "Address out of bounds\nThe program will quit" << endl;
                    exit(0);
                }
            }
        }
        else
        {
            cout << "Error : " << arg1 << "\nInvalid register details\nThe program will quit.\n";
            exit(0);
        }
    }
    else
    {
        cout << "Error : " << arg1 << "\nInvalid arguments\nThe program will quit\n";
        exit(0);
    }
}