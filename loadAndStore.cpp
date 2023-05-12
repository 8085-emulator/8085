#include "ALLHEADER.h"
#include "functions.h"

void MOV(string args1 , string arg2 , string reg[] , bool flag[] , map<string , string > &mem)
{
  if(arg1.length() == 1 && arg2.length() == 1)
  {
    if(arg1 == "M" && arg2 != "M" && validReg(arg2))
      mem[reg[5] + reg[6]] = reg[regNo(arg2)];
    
    else if(arg1 != "M" && arg2 == "M" && validReg(arg1))
      reg[regNo(arg1)] = mem[reg[5] + reg[6]];
    
    else if(arg1 != "M" && arg2 != "M" && validReg(arg1) && validReg(arg2))
      reg[regNo(arg1)] = reg[regNo(arg2)];
    
    else
    {
      cout << "Error : Invalid Register." << endl;
      cout << "The program will quit." << endl;
      exit(0);
    }
  }
}


void MVI(string arg1 , string agr2 , string reg[] , bool flag[] , map<string , string> &mem)
{
  if(arg1.length() == 1 && arg2.length() == 2)
  {
     if(arg1 == "M")
     {
          if(validData(arg2))
              mem[reg[5] + reg[6]] = arg2;
          else
          {
              cout << "Error : Invalid content." << endl;
              exit(0);
          }
     }
     else if(validReg(arg1) && validData(arg2))
       reg[regNo(arg1)] = arg2;
     else
     {
        cout << "Error : Invalid content." << endl;
        exit(0);
     }
  }
  else
  {
    cout << "Error : Invalid content." << endl;
    exit(0);
  }
}

void LXI (string arg1 , string arg2 , string reg[] , bool flag[] , map <string , string> &mem)
{
    if(arg1.length() == 1 && arg2.length() == 4)
    {
        if(arg1 == "M")
        {
            if(validAddr(arg2))
            {
                string a = "" , b ="";
                for(int i = 0 ; i < 2 ; i++)
                {
                    a += arg2[i];
                    b += arg2[i + 2];
                }
                reg[5] = a;
                reg[6] = b;
            }
            else
            {
                cout << "Error : Invalid address." << endl;
                exit(0);
            }
        }
        else
        {
            if(validRp(arg1) && validAddr(arg2))
            {
                string a = "" , b = "";
                for(int i = 0 ; i < 2 ; i++)
                {
                    a += arg2[i];
                    b += arg2[i + 2];
                }
                reg[regNo(arg1)] = a;
                reg[regNo(arg1) + 1] = b;
            }
            else
            {
                cout << "Error : Invalid content."  << endl;
                exit(0);
            }
        }
    }
    else
    {
        cout << "Error : Invalid content."  << endl;
        exit(0);
    }
}

void LDA(string arg1 , string reg[] , bool flag[] , map <string,string> &mem)
{
    if(arg1.length() == 4)
    {
        if(validAddr(arg1))
            reg[0] = mem[arg1];
        else
        {
            cout << "Error : Invalid address." << endl;
            exit(0);
        }
    }
    else
    {
        cout << "Error : Invalid agrument." << endl;
        exit(0);
    }
}

void STA(string arg1 , string reg[] , bool flag[] , map <string , string> &mem)
{
	if(arg1.length() == 4)
	{
		if(validAddr(arg1))
			mem[arg1]=reg[0];
		else
		{
			cout<<"Error: Invalid address." << endl;
			exit(0);
		}
	}
	else
	{
		cout<<"Error: Invalid arguments\nThe program will quit\n";
		exit(0);
	}
}

void LHLD(string arg1 , string reg[] , bool flag[] , map <string , string> &mem)
{
  if(arg1.length() == 4)
  {
    string nextAddr = incrAddr(arg1);
    if(validAddr(arg1) && validAddr(nextAddr))
    {
      reg[6] = mem[arg1];
      reg[5] = mem[nextAddr];
    }
    else
    {
      cout << "Error : Invalid address." << endl;
      exit(0);
    }
  }
  else
  {
    cout << "Error : Invalid content." << endl;
    exit(0);
  }
}

void SHLD(string arg1 , string reg[] , bool flag[] , map <string , string> &mem)
{
    if(arg1.length() == 4 && validAddr(arg1) && reg[5] != "" && reg[6] != "" && mem.empty() == false)
    {
        mem[arg1] = reg[6];
        mem[incrAddr(arg1)] = reg[5];
    }
    else
    {
        cout << "Error : Invalid content." << endl;
        cout << "The program will quit." << endl;
        exit(0);
    }
}

void STAX(string arg1 , string reg[] , bool flag[] , map <string , string> &mem)
{
    if(arg1.length() == 4 && validRp(arg1))
    {
        string a = reg[regNo(arg)] + reg[regNo(arg) + 1];
        if(validAddr(a))
            mem[a] = reg[0];
        else
        {
            cout << "Error : Inavalid content." << endl;
            exit(0);
        }
    }
    else
    {
        cout << "Error : Invalid content.\nThe program will quit." << endl;
        exit(0);
    }
}

void XCHG (string reg[],bool flag[])
{
	string temp = reg[3];
	reg[3] = reg[5];
	reg[5] = temp;
	
	temp = reg[4];
	reg[4] = reg[6];
	reg[6] = temp;
}
