#include "ALLHEADER.h"

bool validRp(string rp)
{
    if(rp == "B" || rp == "D" || rp == "H" || rp == "M")
        return true;
    return false;
}