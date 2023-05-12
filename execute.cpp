#include "ALLHEADER.h"
#include "functions.h"
#include <fstream>
#include <set>

void runNormal(string pc , map < string , string > &mem , vector<string>&seq , bool flag[] , string reg[])
{
      for(int i = 0 ; i < seq.size() ; i++)
      {
          pc = run(mem[seq[i]] , reg , flag , mem , pc);
      }
}
void runDebug(string pc , map<string , string> &mem , vector<string> &seq , bool flag[] , string reg[])
{
      string option;
      set<int>breakpoints;
      set<int>::iterator it;
	cout<<"Enter Options:-\n";
	while(true)
	{
		cout << "-> ";
		cin >> option;
		if(option == "help")
		{
			char line;
			ifstream write("help.txt");
			while(write.get(line))
			{
				if(write.eof())
				{
					write.close();
					break;
				}
				cout<<line;
			}
			write.close();
		}
		else if(option == "PC")
            {
			cout<<"Program counter --> "<<pc<<"\n";
		}
	      else if(option=="p"||option=="print")
            {
			string valueHolder;
			cin>>valueHolder;
      		cin.ignore();
			int l = valueHolder.length();
			if(l == 1)
			{
				if(validReg(valueHolder))
      				cout << reg[regNo(valueHolder)] << endl;
				else
                        {
                              cout<<"Error: "<<valueHolder << endl;
                              cout << "Invalid register name\n"<<"Type 'help' for more information\n";
                        }
			}
			else if(l==4)
			{
				if(validAddr(valueHolder))
      				cout<<mem[valueHolder]<<"\n";
				else
					cout<<"Error: "<<valueHolder<<"\nInvalid address\n"<<"Type 'help' for more information\n";
			}
			else
				cout<<"Error: "<<valueHolder<<"\nType 'help' for more information\n";
		}
      	else if(option=="q"||option=="quit")
			break;
		else if(option=="break"||option=="b")
		{
			int lineNumber;
			cin>>lineNumber;
			breakpoints.insert(lineNumber);
		}
		else if(option=="s"||option=="step")
		{
			if(pc!="")
			pc = run(mem[pc] , reg , flag , mem , pc);
		}
		else if(option=="r"||option=="run")
		{
			if(pc != "")
                  {
				if(breakpoints.empty())
                        {
					while(true)
                              {
						if(mem[pc] == "HLT")
                                    {
						      pc = "";
							break;
						}
						else
							pc = run(mem[pc] , reg , flag , mem , pc);
					}
				}
				else
                        {
					it = breakpoints.begin();
					int var = *it;
					while(pc!=seq[var])
                              {
						pc = run(mem[pc] , reg , flag , mem , pc);
					}
					breakpoints.erase(it);
				}
			}
			else
                  {
				char choice='\0';
				cout<<"You have reached till the end of execution.\nPress to continue[Y/n] ";
				cin>>choice;
				if(choice == 'Y' || choice == 'y')
                        {
					continue;
				}
				else if(choice == 'N' || choice == 'n')
					exit(0);
				else
					cout<<"Please input correct option\n";
				continue;
			}
		}
		else
		{
			cout<<"Invalid choice has been entered.\nType 'help' for more information about debugger\n";
		}
	}
}
