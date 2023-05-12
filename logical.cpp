#include "ALLHEADER.h"
#include "functions.h"
void CMA(string reg[],bool flags[])
{
	string complmt = complement(reg[0]);
	reg[0] = complmt;
	if(reg[0]=="00")
    {
        flags[6] = true;
        flags[2] = true;
    }
    else
    {
        string temp = reg[0];
		int array[2];
		hexToDec(temp,array);
		int value=array[1]*16+array[0];
		bitset<8> dataInBinary(value);
		int parity = dataInBinary.count();
		if(parity%2 == 0 && parity!=0)
			flags[2] = true;
		else
			flags[2] = false;
    }
}


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
