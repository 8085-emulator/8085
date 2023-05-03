#include "ALLHEADER.h"
#include "functions.h"

string JC(string a , string pc , string reg[] , bool flag[])
{
    if(flag[0] == true)
        return a;
    else
    {
        string res = "";
        int val16[4];
        int retVal[] = {0 , 0 , 0 , 3};
        int cy = 0;
        hexToDec(pc , val16);
        for(int i = 3 ; i >= 0 ; i--)
        {
            int val = val16[i] + retrunVal[i] + cy;
            cy = val / 16;
            val = val % 16;
            if(val >= 0 && val <= 9)
                res = (char)('0' + val) + res;
            else
                res = (char)('A' + (val - 10)) + res;
        }
        if(vslidAddr(res))
            return res;
        else
        {
            cout << "Error : " << a << endl;
            cout << "Address overflow." << endl;
            cout << "The program will quit." << endl;
            exit(0);
        }
    }
}