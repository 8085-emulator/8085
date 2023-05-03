#include "ALLHEADER.h"
#include <string>

void hexToDec(string pc,int a[])
{
	int p = 0;
	for(int i =0 ;i < pc.length() ; i++)
  {
		if(pc[i] >= '0' && pc[i] <= '9')
			a[i] = pc[i] - '0';
		else 
			a[i] = 10 + (pc[i] - 'A'); 
	}
}
