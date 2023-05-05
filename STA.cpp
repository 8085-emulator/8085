#include "ALLHEADER.h"
#include "functions.h"

void STA(string arg1 , string reg[] , bool flag[] , map <string , string> &mem)
{
	if(arg1.length() == 4)
	{
		if(validAddr(arg1))
			mem[arg1]=reg[0];
		else
		{
			cout<<"Error: Invalid address." << endl;
			exit(0);
		}
	}
	else
	{
		cout<<"Error: Invalid arguments\nThe program will quit\n";
		exit(0);
	}
}
