#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

bool validAddr(string);
string hexAdd(string,string,bool[],bool);
string hexSub(string,string,bool[],bool);
string hexAdd16bit(string,string,bool[],bool);
string hexSub16bit(string,string,bool[],bool);
void hexToDec(string,int[]);
bool validReg(string);
bool validRp(string);
bool validData(string);
bool validHex(string);
int regNo(string);
bool validFile(string);
string incrAddr(string);
string complement(string);
string decimalToHex(int[]);
int opSize(string);
string run(string, string[], bool[], map<string,string>&,string);
string updatedAddr(string,map<string,string>&);

#endif
