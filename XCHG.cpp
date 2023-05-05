#include"ALLHEADER.h"
void XCHG (string reg[],bool flag[])
{
	string temp = reg[3];
	reg[3] = reg[5];
	reg[5] = temp;
	
	temp = reg[4];
	reg[4] = reg[6];
	reg[6] = temp;
}
