#include "ALLHEADER.h"
#include "functions.h"

string JMP(string a , string reg[] , bool flag[])
{
    if(validAddr(a))
        return a;
    else
    {
        cout << "Error.\nInvalid address : " << a << endl;
        cout << "The program will quit.";
        exit(0);
    }
}

string JC(string a , string pc , string reg[] , bool flag[])
{
    if(flag[0] == true)
        return a;
    else
    {
        string res = "";
        int val16[4];
        int retVal[] = {0 , 0 , 0 , 3};
        int cy = 0;
        hexToDec(pc , val16);
        for(int i = 3 ; i >= 0 ; i--)
        {
            int val = val16[i] + retrunVal[i] + cy;
            cy = val / 16;
            val = val % 16;
            if(val >= 0 && val <= 9)
                res = (char)('0' + val) + res;
            else
                res = (char)('A' + (val - 10)) + res;
        }
        if(vslidAddr(res))
            return res;
        else
        {
            cout << "Error : " << a << endl;
            cout << "Address overflow." << endl;
            cout << "The program will quit." << endl;
            exit(0);
        }
    }
}

string JNC(string a, string pc, string reg[],bool flag[])
{
	if(flag[0] == false)
		return a;
	else
    {
	    string res = "";
		int val16[4];
		int returnVal[] = {0,0,0,3};
		int cy = 0;
		hexToDec(pc , val16);	  
		for(int i = 3 ; i >= 0 ; i--)
        {
			int val = val16[i] + returnVal[i] + cy;
			cy = val / 16;
			val = val % 16;
			if(val >= 0 && val <= 9)
				res = (char)('0' + val) + res;
			else
				res = (char)('A' + (val - 10)) + res;
		}
		if(validAddr(res))
			return res;
		else
		{
			cout<<"Error : " << a << endl;
            cout << "Address overflow." << endl;
            cout << "The program will quit." << endl;
    		exit(0);
		}
	}
}

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

string JNZ(string arg, string pc, string Registers[],bool flag[]){

	if(flag[6] == false){
		
		return arg;
	}
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
			cout<<"Error: "<<arg<<"\nAddress overflow\Quit\n";
				exit(0);
			}
			
	}
}
