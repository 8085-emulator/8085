#include "ALLHEADER.h"
#include "functions.h"

void LHLD(string arg1 , string reg[] , bool flag[] , map <string , string> &mem)
{
  if(arg1.length() == 4)
  {
    string nextAddr = incrAddr(arg1);
    if(validAddr(arg1) && validAddr(nextAddr))
    {
      reg[6] = mem[arg1];
      reg[5] = mem[nextAddr];
    }
    else
    {
      cout << "Error : Invalid address." << endl;
      exit(0);
    }
  }
  else
  {
    cout << "Error : Invalid content." << endl;
    exit(0);
  }
}
