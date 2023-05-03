#include"ALLHEADER.h"
#include"functions.h"
bool validFile(string s)
{
    string c=s;
    vector<string>token;
    bool f=false;
    const char *ch=s.c_str();
    char *p=(char*)ch;
    const char *delimiter=" ,";
    char *chp=strtok(x,delimiter);
    while(chp!=NULL)
    {
        token.push_back(chp);
        chp=strtok(NULL,delimiter);
    }
    if(inRep(token[0]) && argValid(token , token[0]) && alpha(c))
    
}
