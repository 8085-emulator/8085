#include"ALLHEADER.h"
void XCHG (string register[],bool flag[])
{
	string temp=register[3];
	register[3]=register[5];
	register[5]=temp;
	temp=register[4];
	register[4]=register[6];
	register[6]=temp;
}