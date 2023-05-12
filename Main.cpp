#include "ALLHEADER.h"
#include <fstream>
#include "functions.h"
#include "execute.h"

class emulator8085
{
    private:
        map<string , string>mem;
        vector<string>seq;
        string start , pc , reg[7];
        bool flag[8];
    public:
        emulator8085()
        {
            for(int i = 0 ; i < 7 ; i++)
                reg[i] = "NULL";
            for(int i = 0 ; i < 8 ; i++)
                flag[i] = false;
            start = "";
            pc = "";
        }
        void startAddr()
        {
            cout << "\nInput starting address : ";
            cin >> start;
            pc = start;
            if(!validAddr(start))
            {
                cout<<"Invalid start address.\nThe program will quit." << endl;
                exit(0);
            }
            seq.push_back(start);
        }
        void debug()
        {
            cout << "\nStart writing your code :\n";
            while(1)
            {
                cout << ">> " << pc << " : ";
                string line;
                getline(cin , line);
                if(validFile(line))
                {
                    mem[pc] = line;
                    pc = updatedAddr(pc , mem);
                    if(line == "HLT")
                    {
                        break;
                        seq.push_back(pc);
                    }
                }
                else
                {
                    cout << "Error : " << line << endl;
                    cout << "Invalid statement\nProgram will quit." << endl;
                    exit(0);
                }
            }
            runDebug(start , mem , seq , flag , reg);
        }
        void prgFile(char * fname)
        {
            ifstream input;
            execute obj;
            input.open(fname);
            if(input.fail() == true)
            {
				cout<<"Invalid filename.\nThe prorgam will quit\n";
			    exit(0);
    		}
            string line;
            while(1)
            {
                getline(input,line);
                if(validFile(line))
                {
                    mem[pc] = line;
                    pc=updatedAddr(pc , mem);
                    if(line=="HLT")
	    				break;
                    seq.push_back(pc);
       			}
                else
                {
					cout<<"Error: "<<line<<"\n";
				    cout<<"You have entered an incorrect statement\nThe program will quit\n"<<endl;
    				exit(0);
	    		}
            }
            obj.runNormal(start , mem , seq , flag , reg);
        }
        void normalInput()
        {
            string line;
            cout << "Start writing your code :" << endl;
            while(1)
            {
                cout << ">> " << pc << " ";
                getline(cin , line);
                if(validFile(line))
                {
                    mem[pc] = line;
                    pc = updatedAddr(pc , mem);
                    if(line == "HLT")
                        break;
                    seq.pushback(pc);
                }
                else
                {
                    cout << "Error : " << line << endl;
                    cout << " Incorrect statement.\n Program will quit." << endl;
                    exit(0);
                }
            }
            runNormal(start , mem , seq , flag , reg);
        }
        void prgFileDebug(char * fname)
        {
            ifstream input;
            execute obj;
	    	input.open(fname);
		    if(input.fail() == true)
            {
				cout << "Invalid filename.\nThe prorgam will quit\n";
			    exit(0);
    		}
	    	string line;
    		while(1)
	    	{
		        getline(input,line);
    			if(validFile(line))
    			{
                    mem[pc]=line;
    				pc=updatedAddr(pc,mem);
    				if(line=="HLT")
	    				break; 
    				seq.push_back(pc);
    			}
	    		else
                {
					cout << "Error : "<<line<<"\n";
    				cout << "You have entered an incorrect statement.\nThe program will quit\n"<<endl;
	    			exit(0);
	    		}
    		}
    		obj.runDebug(start , mem , seq , flag , reg);
        }
};

int main(int argc , char * argv[])
{
    emulator8085 obj;
    obj.startAddr();
    if(argc == 2)
    {
        if(strcmp(argv[1] , "--debugger") == 0)
        {
            obj.debug();
        }
        else
        {
            obj.prgFile(argv[1]);
        }
    }
    else if(argc == 1)
    {
        obj.normalInput();
    }
    else if(argc == 3)
    {
        obj.prgFileDebug(argv[1]);
    }
}
