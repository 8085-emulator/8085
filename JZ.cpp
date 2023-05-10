#include "AllHEADER.h"
#include "functions.h"

string JZ(string arg, string pc, string reg[],bool flag[]){

	if(flag[6] == true)
		return arg;
	else{
		
		string resultant = "";
		int value16bit[4];
		int returnValue[] = {0,0,0,3};
		int carry = 0;
		hexToDec(pc,value16bit);	  
		for(int i = 3;i>=0;i--){
					
			int value = value16bit[i] + returnValue[i] + carry;
			carry = value / 16;
			value = value % 16;
			if(value>=0 && value<=9)
				resultant = (char)('0' + value) + resultant;
			else{
				resultant = (char)('A'+(value-10)) + resultant;
			}
		}
		if(validAddr(resultant))
			return resultant;
		else
		{
			cout<<"Error: "<<arg<<"\nAddress overflow\nQuit\n";
				exit(0);
		}
			/*Error - Address over-flow*/
	}
}
