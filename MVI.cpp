
#include "ALLHEADER.h"
#include "functions.h"

MVI(string arg1 , string agr2 , string reg[] , bool flag[] , map<string , string> &mem)
{
  if(arg1 == 'M')
    mem[reg[5] + reg[6]] = arg2;
  else if(validReg(arg1))
    reg[regNo(arg1)] = val;
  else
  {
    cout << "Error : Invalid register." << endl;
    exit(0);
  }
}
