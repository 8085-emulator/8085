#include "ALLHEADER.h"
#include "functions.h"

void DAD(string arg,string reg[],bool flag[])
{
	if(arg.length() == 1)
    {
		if(validReg(arg))
        {
			int regID = regNo(arg);
			if(regID == 1 || regID == 3 || regID == 5)
            {	
				string data16bit = "";
				string data16bitHL = "";
				string res = "";
				if(validData(reg[regID]) && validData(reg[regID + 1]) && validData(reg[5]) && validData(reg[6]))
                {
					data16bit = data16bit + reg[regID] + reg[regID];
					data16bitHL = data16bitHL + reg[5] + reg[6];
					int value16bit[4];
					int value16bitHL[4];
					int c = 0;
					hexToDec(arg,value16bit);
					hexToDec(arg,value16bitHL);	  
					for(int i = 3 ; i >= 0 ; i--)
                    {
						int val = value16bit[i] + value16bitHL[i] + c;
						if(val >= 16)
							flag[0] = true;
						else
							flag[0] = false;
						c = val / 16;
						val = val % 16;
						if(val >=0 && val <=9)
							res = (char)('0' + val) + res;
						else if (val == 10)
                             res = "A" + res;
						else if(val == 11)
                            res = "B" + res;
                        else if(val == 12)
                    		res = "C" + res;
						else if(val == 13)
							res = "D" + res;
						else if(val == 14)
							res = "E" + res;
						else if(val == 15)
							res = "F" + res;
					}
					reg[5] = res[0] + res[1];
					reg[6] = res[2] + res[3];
				}		
				else
                {
					cout<<"Error : Invalid data content.\nThe program will quit\n";
					exit(0);
				}
			}
			else
            {
				cout<<"Error : Invalid register pair.\nThe program will quit\n";
				exit(0);
			}
		}
		else
        {
			cout<<"Error : Invalid register content.\nThe program will quit\n";
			exit(0);
		}
	}
	else
    {
		cout<<"Error : Invalid arguments\nThe program will quit\n";
		exit(0);
	}
}
