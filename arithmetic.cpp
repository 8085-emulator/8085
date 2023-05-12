#include "ALLHEADER.h"
#include "functions.h"

void ADD(string agr1 , string reg[] , bool flag[] , map <string , string> &mem)
{
    if(arg1.length() == 1)
    {
        if(validReg(agr1) || validRP(arg1))
        {
            if(arg1 == 'M')
            {
                int regNo = registerNo(arg1);
                reg[0] = hexAdd(reg[regNo] , reg[0] , flag , true);
            }
            else
            {
                string addr = "";
                addr = addr + reg[5] + reg[6];
                if(addr >= "0000" && addr <= "FFFF")
                {
                    reg[0] = hexAdd(mem[addr] , reg[0] , flag , true);
                }
                else
                {
                    cout << "Error : " << arg1 << endl;
                    cout << "Address out of bounds\nThe program will quit" << endl;
                    exit(0);
                }
            }
        }
        else
        {
            cout << "Error : " << arg1 << "\nInvalid register details\nThe program will quit.\n";
            exit(0);
        }
    }
    else
    {
        cout << "Error : " << arg1 << "\nInvalid arguments\nThe program will quit\n";
        exit(0);
    }
}

void ADI(string arg , string reg[] , bool flag)
{
    if(arg.length() == 2)
    {
        if(validData(arg))
        {
            reg[0] = hexAdd(arg , reg[0] , flag , true);
        }
        else
        {
            cout << "Error : " << arg << "\nInvalid data.\nThe program will quit." << endl;
            exit(0);
        }
    }
    else
    {
        cout << "Error : " << arg << "\nInvalid data.\nthe program will quit." << endl;
        exit(0);
    }
}


void SUB(string arg1,string registers[],bool flag[],map<string,string>&memory){
	
	int length=arg1.length();
	if(length == 1){
		
		if(validReg(arg1)){
			
			if(arg1 != "M"){
			
				/*Fetches index of register to access array string registers[]*/
				int registerID = registerNumber(arg1);              
				/*Converting decimal value to string format and storing in accumulator*/
				registers[0] = hexSub(registers[registerID],registers[0],flag,true);
				
			}
			else{                         
		
				/*Fetches data of HL pair*/
				string address = "";
				address = address + registers[5] + registers[6];
				if(address >= "0000" && address <= "FFFF"){
				
					/*Converting decimal value to string format and storing in accumulator*/
					registers[0] = hexSub(memory[address],registers[0],flag,true);				
					
				}
				else{
					cout<<"Error: "<<arg1<<"\nAddress out of bounds\nThe program will quit\n";
					exit(0);
					/*error message of address out of bounds*/
				}						
			}
		}
		else{
			cout<<"Error: "<<arg1<<"\nInvalid register details\nThe program will quit\n";
			exit(0);
			/*error of invalid register details*/
		}
	}
	else{
		cout<<"Error: "<<arg1<<"\nInvalid arguments\nThe program will quit\n";
		exit(0);
		/*Error message of invalid arguments*/
	}
}


void INR(string arg , string reg[] , bool flag[] , map<string , string> &mem)
{
	if(arg.length() == 1)
    {
		if(validReg(arg))
        {
	  		if(arg != "M")
            {
				int registerID = regNo(arg);
			  	reg[registerID] = hexAdd(reg[registerID] , "01" , flag , false); 
  			}
	  		else
            {
		    	string address = "";
    			address = address + reg[5] + reg[6];
    			if(validAddr(address))
      			    mem[address] = hexAdd(mem[address] , "01" , flag , false);
    		   	else
                {					
     				cout << "Error : Address out of bounds.\nThe program will quit\n";
     				exit(0);
   				}
		    }
		}
		else
        {
			cout << "Error : Invalid register details.\nThe program will quit\n";
		 	exit(0);
		}
	}
	else
    {
		cout << "Error : Invalid argument type.\nThe program will quit\n";
	  	exit(0);
	}
}


void DCR(string arg , string reg[],bool flag[],map<string,string> &mem)
{
	if(arg.length() == 1)
    {
		if(validReg(arg))
        {
			if(arg != "M")
            {
				int registerID = regNo(arg);
				reg[registerID] = hexSub(reg[registerID] , "01" , flag , false);
			}
			else
            {
				string address = "";
				address = address + registers[5] + registers[6];
				if(validAddr(address))
                {
					mem[address] = hexSub(mem[address] , "01" , flag , false);
				}
				else
                {
					cout<<"Error : Invalid register details.\nThe program will quit\n";
					exit(0);
				}
			}
		}
		else
        {
			cout<<"Error : \nInvalid register\nThe program will quit\n";
			exit(0);
		}
	}
	else
    {
		cout<<"Error : Invalid argument.\nThe program will quit\n";
		exit(0);
	}
}


void INX(string arg , string reg[] , bool flag[])
{
	if(arg.length() == 1)
	{
		if(validReg(arg))
      	{
 		   	int registerID = regNo(arg);
		   	if(registerID == 1 || registerID == 3 || registerID == 5)
 	       	{
    			string data16b = "";
		   		string temp = "";	
		        string s1 = "";
    			string s2 = "";
		   		if(validData(reg[registerID]) == true && validData(reg[registerID + 1]) == true)
		        {
					data16b = data16b + reg[registerID] + reg[registerID + 1];
      				temp = incrAddr(data16b);
       				s1 = s1 + temp[0] + temp[1];		
    				s2 = s2 + temp[2] + temp[3];
    				reg[registerID] = s1; 
					reg[registerID + 1] = s2;
				}
    			else
        		{
					cout << "Error : Invalid data content in registers.\nThe program will quit\n";
    				exit(0);
    			}
			}
    	   	else
        	{
				cout << "Error : Invalid register pair.\nThe program will quit\n";
    				exit(0);
 	   		}
		}
		else
      	{
			cout << "Error : Invalid register content.\nThe program will quit\n";
    		exit(0);
  		}
	}
	else
	{
	  	cout << "Error : Invalid input arguments.\nThe program will quit\n";
  		exit(0);
	}
}


void DCX(string arg , string reg[] , bool flag[])
{
	if(arg.length() == 1)
    {
			if(validReg(arg))
            {
					int registerID = regNo(arg);
			        if(registerID == 1 || registerID == 3 || registerID == 5)
                    {
						string data16b = "";
			      	    string temp = "";
    	      			string s1 = "";
          				string s2 = "";
      	    			if(validData(reg[registerID]) == true && validData(reg[registerID+1]) == true)
                        {
							data16b = data16b + reg[registerID] + reg[registerID + 1];
					        temp = hexSub16bit(data16b , "0001" , flag , false);
					        s1 = s1 + temp[0] + temp[1];
            				s2 = s2 + temp[2] + temp[3];
					        reg[registerID] = s1;
          					reg[registerID+1] = s2;
      				    }
	      			    else
                        {
					        cout << "Error : Invalid data content.\nThe program will quit\n";
					        exit(0);
      				    }
			        }
			        else
                    {
      				    cout << "Error : Invalid register pair.\nThe program will quit\n";
      				    exit(0);
    			    }
	        }
	        else
            {
		        cout << "Error : Invalid register content.\nThe program will quit\n";
       			exit(0);
  	  	    }
    }
	else
    {
	   	cout << "Error : Invalid input arguments.\nThe program will quit\n";
  	    exit(0);
	}
}


void DAD(string arg,string reg[],bool flag[])
{
	if(arg.length() == 1)
    {
		if(validReg(arg))
        {
			int regID = regNo(arg);
			if(regID == 1 || regID == 3 || regID == 5)
            {	
				string data16bit = "";
				string data16bitHL = "";
				string res = "";
				if(validData(reg[regID]) && validData(reg[regID + 1]) && validData(reg[5]) && validData(reg[6]))
                {
					data16bit = data16bit + reg[regID] + reg[regID];
					data16bitHL = data16bitHL + reg[5] + reg[6];
					int value16bit[4];
					int value16bitHL[4];
					int c = 0;
					hexToDec(arg,value16bit);
					hexToDec(arg,value16bitHL);	  
					for(int i = 3 ; i >= 0 ; i--)
                    {
						int val = value16bit[i] + value16bitHL[i] + c;
						if(val >= 16)
							flag[0] = true;
						else
							flag[0] = false;
						c = val / 16;
						val = val % 16;
						if(val >=0 && val <=9)
							res = (char)('0' + val) + res;
						else if (val == 10)
                             res = "A" + res;
						else if(val == 11)
                            res = "B" + res;
                        else if(val == 12)
                    		res = "C" + res;
						else if(val == 13)
							res = "D" + res;
						else if(val == 14)
							res = "E" + res;
						else if(val == 15)
							res = "F" + res;
					}
					reg[5] = res[0] + res[1];
					reg[6] = res[2] + res[3];
				}		
				else
                {
					cout<<"Error : Invalid data content.\nThe program will quit\n";
					exit(0);
				}
			}
			else
            {
				cout<<"Error : Invalid register pair.\nThe program will quit\n";
				exit(0);
			}
		}
		else
        {
			cout<<"Error : Invalid register content.\nThe program will quit\n";
			exit(0);
		}
	}
	else
    {
		cout<<"Error : Invalid arguments\nThe program will quit\n";
		exit(0);
	}
}

void SUI(string arg, string reg[],bool flag[])
{

	int length = arg.length();
	if(length == 2){
	
		if(validData(arg)){
	//result stores in accumulator
			reg[0] = hexSub(arg,reg[0],flag,true);
		}
		else{
			
			cout<<"Error: "<<arg<<"\n";
			cout<<"Invalid data\n";
			exit(0);
	
		}
	}
	else{
		
		cout<<"Error: "<<arg<<"\n";
		cout<<"Invalid data\nThe program will quit\n";
		exit(0);
	
	}
	
}
