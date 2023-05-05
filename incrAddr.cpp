#include "ALLHEADER.h"

string incrAddr(string a)
{
    int n[5] , l = a.length();
    string next = "";
    for(int i = l - 1 ; i >= 0 ; i--)
    {
        if(a[i] >= 'A' && a[i] <= 'F')
            n[i] = (int)(10 + (a[i] - 'A'));
        else if(a[i] >= '0' && a[i] <= '9')
            n[i] = (int)(a[i] - '0');
    }
    
    n[l - 1]++;
    
    for(int i = l - 1 ; i >= 0 ; i--)
    {
        if(n[i] >= 0 && n[i] <= 15)
            break;
        if(n[i] >= 16)
        {
            n[i] = n[i] % 16;
            n[i - 1]++;
        }
    }
    for(int i = 0 ; i < l ; i++)
    {
        if(n[i] >= 0 && n[i] <= 9)
            next += (char)('0' + n[i]);
        else if(n[i] >= 10 && n[i] <= 15)
            next += (char)('A' + (n[i] - 10));
    }
    return next;
}
