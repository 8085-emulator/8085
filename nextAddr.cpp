#include "ALLHEADER.h"
#include "functions.h"

string nextAddr(String str, int n)
{
    int arr[4];
    string res = "";
    hexToDec(str , arr)
    int i = 3;
    arr[i] += n;
    while(arr[i] >= 16)
    {
        arr[i] = arr[i] % 16;
        arr[i - 1]++;
        i--;
    }
    for(i = 0 ; i < 4 ; i++)
    {
        if(arr[i] > 0 && arr[i] <= 9)
            res += char('0' + arr[i]);
        else
            res += char('A' + (arr[i] - 10));
    }
    return res;
}