#include "ALLHEADER.h"
#include "functions.h"

void SET(string arg1,string arg2,map<string,string> &memory){
	int l1=arg1.length();
	int l2=arg2.length();
	if(l1==4 && l2==2 && validAddr(arg1)&&validData(arg2))
		memory[arg1]=arg2;
	else{
		cout<<"Error:Invaid Arguments "<<arg1<<" & "<<arg2<<"\nThe program will quit\n";
		exit(0);
	}
}
