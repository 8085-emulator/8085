#include "ALLHEADER.h"
#include "functions.h"
#include "arithmetic.h"
#include "jump.h"
#include "load.h"
#include "logical.h"

string run(string command , string reg[] , bool flag[] , map < string , string > &mem , string pc)
{
    vector<string> cmd;
    string str;
    int cmdSize;
    const char *partition = command.c_str();
    char *temp = (char *)partition;
    const char * delimiter = " ,";
    char *part = strtok(temp , delimiter);
  
    while(part != NULL)
    {
        str = part;
        cmd.push_back(str);
        part = strtok(NULL , delimiter);
    }

    if(cmd[0] == "MOV")
    {
        MOV(cmd[1] , cmd[2] , reg , flag , mem);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }
    else if(cmd[0] == "MVI")
    {
        MVI(cmd[1] , cmd[2] , reg , flag , mem);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }
    else if(cmd[0] == "LXI")
    {
        LXI(cmd[1] , cmd[2] , reg , flag , mem);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }
    else if(cmd[0] == "LDA")
    {    
        LDA(cmd[1] , reg , flag , mem);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }
    else if(cmd[0] == "STA")
    {
        STA(cmd[1] , reg , flag , mem);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }
    else if(cmd[0] == "LHLD")
    {
        LHLD(cmd[1] , reg , flag , mem);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }
    else if(cmd[0] == "SHLD")
    {
        SHLD(cmd[1] , reg , flag , mem);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }
    else if(cmd[0] == "STAX")
    {
        STAX(cmd[1] , reg , flag , mem);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }
    else if(cmd[0] == "XCHG")
    {   
        XCHG(reg , flag);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }

    
    else if(cmd[0] == "ADD")
    {
        ADD(cmd[1] , reg , flag , mem);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }
    else if(cmd[0] == "ADI")
    {
        ADI(cmd[1] , reg , flag);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }
    else if(cmd[0] == "SUB")
    {
        SUB(cmd[1] , reg , flag , mem);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }
    else if(cmd[0] == "SUI")
    {
        SUI(cmd[1] , reg , flag);
            cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }
    else if(cmd[0] == "INR")
    {    
        INR(cmd[1] , reg , flag , mem);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }
    else if(cmd[0] == "DCR")
    {
        DCR(cmd[1] , reg , flag , mem);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }
    else if(cmd[0] == "INX")
    {
        INX(cmd[1] , reg , flag);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }
    else if(cmd[0] == "DCX")
    {
        DCX(cmd[1] , reg , flag);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }
    else if(cmd[0] == "DAD")
    {
        DAD(cmd[1] , reg , flag);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }


    else if(cmd[0] == "CMA")
    {
        CMA(reg , flag);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }
    
    else if(cmd[0] == "CMP")
    { 
        CMP(cmd[1] , reg , flag , mem);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }

   
    else if(cmd[0] == "JMP")
        return JMP(cmd[1] , pc , reg , flag);

    else if(cmd[0] == "JC")
        return JC(cmd[1] , pc , reg , flag);

    else if(cmd[0] == "JNC")
        return JNC(cmd[1] , pc , reg , flag);

    else if(cmd[0] == "JZ")
        return JZ(cmd[1] , pc , reg , flag);

    else if(cmd[0] == "JNZ")
        return JNZ(cmd[1] , pc , reg , flag);


    else if(cmd[0] == "SET")
    {
        SET(cmd[1] , cmd[2] , mem);
        cmdSize = opSize(cmd[0]);
        return nextAddr(pc , cmdSize);
    }

    return "";
}