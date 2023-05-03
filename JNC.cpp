#include "ALLHEADER.h"
#include "function.h"

string JNC(string a, string pc, string reg[],bool flag[])
{
	if(flag[0] == false)
		return a;
	else
    {
	    string res = "";
		int val16[4];
		int returnVal[] = {0,0,0,3};
		int cy = 0;
		hexToDec(pc , val16);	  
		for(int i = 3 ; i >= 0 ; i--)
        {
			int val = val16[i] + returnVal[i] + cy;
			cy = val / 16;
			val = val % 16;
			if(val >= 0 && val <= 9)
				res = (char)('0' + val) + res;
			else
				res = (char)('A' + (val - 10)) + res;
		}
		if(validAddr(res))
			return res;
		else
		{
			cout<<"Error : " << a << endl;
            cout << "Address overflow." << endl;
            cout << "The program will quit." << endl;
    		exit(0);
		}
	}
}