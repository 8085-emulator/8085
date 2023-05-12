#include "ALLHEADER.h"
#include "functions.h"

string updatedAddr(string pc , map<string , string> &mem)
{
  string command = mem[pc];
  string opcode;
  if(cmd == "HLT" || cmd == "XCHG" || cmd == "CMA")
      opcode = command;
  else
  {
    char * cmd = command.c_str() , * delimiter = " ,";
    char * part = strtok(cmd , delimiter);
    opcode = part;
  }
  int n = opSize(opcode);
  string res;
  for(int i = 1 ; i <= n ; i++)
  {
    int a[4] = {-1 , -1 , -1 , -1};
    res = "";
    hexToDec(pc , a);
    int j = 3;
    a[j] += 1; //to increase address by 1 (n times)
    while(a[j] >= 16)
    {
      a[j] = a[j] % 16;
      a[--j]++;
    }
    for(int j = 0 ; j < 4 ; j++)
    {
      if(a[j] >= 0 && a[j] <= 9)
        res += char('0' + a[j]);
      else
        res == char('A' + (a[j] - 10));
    }
    mem[res] = mem[pc];
    pc = res;
  }
  return pc;
}
