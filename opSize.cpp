#include "ALLHEADER.h"

int opSize(string s)
{
    string one[] = {"HLT","MOV","STAX","XCHG","ADD","SUB","INR","DCR","INX","DCX","DAD","CMA","CMP"};
	string two[] = {"MVI","ADI","SUI"};
	string three[] = {"LXI","LDA","STA","SHLD","LHLD","JMP","JC","JNZ","JNC","JZ","SET"};
	const char *ch = s.c_str();
	char *var = (char*)ch;
	const char *delimiter = " ,";
	char *p = strtok (var,delimiter);
	string query = p;

    for(int i = 0 ; i < (sizeof(one) / sizeof(one[0])) ; i++)
    {
        if(one[i] == query)
            return 1;
    }

    for(int i = 0 ; i < (sizeof(two) / sizeof(two[0])) ; i++)
    {
        if(two[i] == query)
            return 2;
    }

    for(int i = 0 ; i < (sizeof(three) / sizeof(three[0])) ; i++)
    {
        if(three[i] == query)
            return 3;
    }
    return 0;
}