#include "ALLHEADER.h"
#include "functions.h"

void DCR(string arg , string reg[],bool flag[],map<string,string> &mem)
{
	if(arg.length() == 1)
  {
		if(validReg(arg))
    {
			if(arg != "M")
      {
				int registerID = regNo(arg);
				reg[registerID] = hexSub(reg[registerID] , "01" , flag , false);
			}
			else
      {
				string address = "";
				address = address + registers[5] + registers[6];
				if(validAddr(address))
        {
					mem[address] = hexSub(mem[address] , "01" , flag , false);
				}
				else
        {
					cout<<"Error : Invalid register details.\nThe program will quit\n";
					exit(0);
				}
			}
		}
		else
    {
			cout<<"Error : \nInvalid register\nThe program will quit\n";
			exit(0);
		}
	}
	else
  {
		cout<<"Error : Invalid argument.\nThe program will quit\n";
		exit(0);
	}
}
