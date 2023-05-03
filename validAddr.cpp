#include "ALLHEADER.h"
#include<string>

bool validAddr(string addr)
{
    for(int i = 0 ; i < addr.length() ; i++)
    {
        if(!((addr[i] >= '0' && addr[i] <= '9')||(addr[i] >= 'A' && addr[i] <= 'F')))
            return false;
    }
    return true;
}
