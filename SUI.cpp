#include "ALLHEADER.h"
#include "functions.h"

void SUI(string arg, string reg[],bool flag[]){

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
