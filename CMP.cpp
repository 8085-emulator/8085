#include "ALLHEADER.h"
#include "functions.h"

void CMP (string arg1 , string reg[] , bool flag[] , map <string , string> &mem)
{
	if(arg1.length() == 1)
	{
		if(arg1 == "M")
		{
			if(reg[0] < mem[registers[5] + registers[6]])
			    flag[0] = true;
			else if(reg[0] == mem[registers[5] + registers[6]])
				flag[6] = true;
			else
			{
				flag[0] = false;
				flag[6] = false;
			}
		}
		else if(validReg(arg1))
		{
			int i = regNo(arg1);
    		if(reg[0] < reg[i])
				flag[0] = true;
			else if(reg[0] == reg[i])
				flag[6] = true;
			else
			{
			    flag[0] = false;
				flag[6] = false;
			}
		}
		else
        {
			cout<<"Error: Invalid registers.\nThe program will quit." << endl;
			exit(0);
		}
	}
	else
    {
		cout<<"Error: Invalid argument.\nThe program will quit.\n";
		exit(0);
	}
}
Footer
