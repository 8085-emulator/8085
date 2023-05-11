#include "ALLHEADER.h"
#include "functions.h"

void INR(string arg , string reg[] , bool flag[] , map<string , string> &mem)
{
	if(arg.length() == 1)
  {
		if(validReg(arg))
    {
	  		if(arg != "M")
        {
					int registerID = regNo(arg);
			  	reg[registerID] = hexAdd(reg[registerID] , "01" , flag , false); 
  			}
	  		else
        {
		    		string address = "";
    				address = address + reg[5] + reg[6];
    				if(validAddr(address))
      					mem[address] = hexAdd(mem[address] , "01" , flag , false);
    				else
            {					
    	 				cout << "Error : Address out of bounds.\nThe program will quit\n";
      				exit(0);
    				}
		    }
		}
		else
    {
				cout << "Error : Invalid register details.\nThe program will quit\n";
		  	exit(0);
		}
	}
	else
  {
			cout << "Error : Invalid argument type.\nThe program will quit\n";
	  	exit(0);
	}
}
