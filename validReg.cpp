#include "ALLHEADER.h"

bool validReg(string r)
{
    if(r == "A" || r == "B" || r == "C" || r == "D" || r == "E" || r == "H" || r == "L")
        return true;
    return false;
}