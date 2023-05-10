#include "ALLHEADER.h"
#include "functions.h"

string hexAdd(string arg1 , string arg2 , bool flag[] , bool carry)
{	
	string resultant = "";
	int variable;
	int value1[5] = {0,0};
	int value2[5] = {0,0};
	int tempAnswer[2];
	hexToDec(arg1,value1);
	hexToDec(arg2,value2);
  
	tempAnswer[1] = value1[1] + value2[1];
	if(tempAnswer[1]>=16)
  {
		tempAnswer[1] = tempAnswer[1]%16;
		value1[0]++;
		flag[4] = true;
	}
	tempAnswer[0] = value1[0] + value2[0];
	if(tempAnswer[0]>=16)
  {
		tempAnswer[0] = tempAnswer[0]%16;
		if(carry == true)
		  	flag[0] = true;
	}
	variable = tempAnswer[0]*16 + tempAnswer[1];
	bitset<8> dataInBinary(variable);
	int parity = dataInBinary.count();
	if(parity%2 == 0 && parity!=0)
	  	flag[2] = true;
	else
	  	flag[2] = false;
	flag[7] = dataInBinary[7];
	if(parity == 0)
		  flag[6] = true;
	for(int i = 1;i>=0;--i)
  {
		  if(tempAnswer[i]>=0 && tempAnswer[i]<=9)
			  resultant = char('0' + tempAnswer[i]) + resultant;
  		else if(tempAnswer[i]>=10 && tempAnswer[i]<=15)
  			resultant = (char)('A'+(tempAnswer[i] - 10)) + resultant;
  }
	return resultant;
}
