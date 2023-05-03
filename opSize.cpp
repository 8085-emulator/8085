#include "ALLHEADER.h"

int opSize(string s)
{
    string one[] = {"HLT","MOV","STAX","XCHG","ADD","SUB","INR","DCR","INX","DCX","DAD","CMA","CMP"};
	string two[] = {"MVI","ADI","SUI"};
	string three[] = {"LXI","LDA","STA","SHLD","LHLD","JMP","JC","JNZ","JNC","JZ","SET"};
	char *ch = s.c_str();
	char *delimiter = " ,";
	char *p = strtok (ch , delimiter);
	string cmd = p;

    for(int i = 0 ; i < (sizeof(one) / sizeof(one[0])) ; i++)
    {
        if(one[i] == cmd)
            return 1;
    }

    for(int i = 0 ; i < (sizeof(two) / sizeof(two[0])) ; i++)
    {
        if(two[i] == cmd)
            return 2;
    }

    for(int i = 0 ; i < (sizeof(three) / sizeof(three[0])) ; i++)
    {
        if(three[i] == cmd)
            return 3;
    }
    return 0;
}
