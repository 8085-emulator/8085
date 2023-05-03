#include "ALLHEADER.h"
#include <string>

bool isHex(string data , int l)
{
    for(int i = 0 ; i < l ; i++)
    {
        if((data[i] >= '0' && data[i] <= '9') || (data[i] >= 'A' && data[i] <= "F"))
            continue;
        return false;
    }
    return true;
}

bool validHex(string data)
{
    bool flag;
    int l = data.length();
    if((l == 2 || l == 4) && isHex(data , l))
        return true;
    return false;
}