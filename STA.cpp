#include "ALLHEADER.h"
#include "functions.h"
void STA (string arg1,string register[],bool flag[],map<string,string> &mem)
{
	int l1=arg1.length();
	if(l1==4)
	{
		if(validityAddr(arg1))
			mem[arg1]=register[0];
		else
		{
			cout<<"Error: "<<arg1<<"\nInvalid address\n";
			exit(0);
		}
	}
	else
	{
		cout<<"Error: "<<arg1<<"\nInvalid arguments\nThe program will quit\n";
		exit(0);
	}
}
