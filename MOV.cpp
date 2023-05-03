#include "ALLHEADER.h"
#include "functions.h"

void MOV(string args1 , string arg2 , string reg[] , bool flag[] , map<string , string > &mem)
{
  if(arg1.length() == 1 && arg2.length() == 1)
  {
    if(arg1 == "M" && arg2 != "M" && validReg(arg2))
      mem[reg[5] + reg[6]] = reg[regNo(arg2)];
    
    else if(arg1 != "M" && arg2 == "M" && validReg(arg1))
      reg[regNo(arg1)] = mem[reg[5] + reg[6]];
    
    else if(arg1 != "M" && arg2 != "M" && validReg(arg1) && validReg(arg2))
      reg[regNo(arg1)] = reg[regNo(arg2)];
    
    else
    {
      cout << "Error : Invalid Register." << endl;
      cout << "The program will quit." << endl;
      exit(0);
    }
  }
}
