
#include "ALLHEADER.h"
#include "functions.h"

MVI(string arg1 , string agr2 , string reg[] , bool flag[] , map<string , string> &mem)
{
  if(arg1.length() == 1 && arg2.length() == 2)
  {
    if(arg1 == 'M')
    {
      if(validData(arg2)))
        mem[reg[5] + reg[6]] = arg2;
      else
      {
        cout << "Error : Invalid content." << endl;
        exit(0);
      }
    }
    else if(validReg(arg1) && validData(arg2))
      reg[regNo(arg1)] = arg2;
    else
    {
      cout << "Error : Invalid content." << endl;
      exit(0);
    }
  }
}
