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
