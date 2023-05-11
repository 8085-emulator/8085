#include "ALLHEADER.h"
#include "functions.h"

void DCX(string arg , string reg[] , bool flag[])
{
	if(arg.length() == 1)
  {
			if(validReg(arg))
      {
					int registerID = regNo(arg);
			    if(registerID == 1 || registerID == 3 || registerID == 5)
          {
							string data16b = "";
			      	string temp = "";
	      			string s1 = "";
      				string s2 = "";
      				if(validData(reg[registerID]) == true && validData(reg[registerID+1]) == true)
              {
										data16b = data16b + reg[registerID] + reg[registerID + 1];
					          temp = hexSub16bit(data16b , "0001" , flag , false);
					          s1 = s1 + temp[0] + temp[1];
            				s2 = s2 + temp[2] + temp[3];
					          reg[registerID] = s1;
          					reg[registerID+1] = s2;
      				}
	      			else
              {
					        cout << "Error : Invalid data content.\nThe program will quit\n";
					        exit(0);
      				}
			    }
			    else
          {
      				cout << "Error : Invalid register pair.\nThe program will quit\n";
      				exit(0);
    			}
		  }
		  else
      {
			    cout << "Error : Invalid register content.\nThe program will quit\n";
    			exit(0);
  		}
	}
	else
  {
	  	cout << "Error : Invalid input arguments.\nThe program will quit\n";
  		exit(0);
	}
}
