#include "ALLHEADER.h"

bool isHex(char c)
{
    if((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))
        return true;
    return false;
}

bool validData(string s)
{
    if((s.length() == 2) && isHex(s[0]) && isHex(a[1]))
        return true;
    return false;
}