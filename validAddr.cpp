#include "ALLHEADER.h"
#include<string>

bool validAddr(string add)
{
    bool f;
    for(int i = 0 ; i < add.length() ; i++)
    {
        if((add[i] >= '0' && add[i] <= '9')||(add[i] >= 'A' && add[i] <= 'F'))
            f = true;
        else
        {
            f = false;
            break;
        }
    }
    return f;
}
