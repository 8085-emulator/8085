#include"ALLHEADER.h"
string complement(string a)
{
	int l=a.length();
	string complement="";
	for(int i=0;i<l;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{ 
			int difference=15-(a[i]-'0');
			if(difference>=0&&difference<=9)
				complement+=('0'+difference);
			else if(difference>=10&&difference<=15)
				complement+=('A'+(difference-10));	
		}
		if(a[i]>='A'&&a[i]<='F')
		{
			int value=a[i]-'A';
			int difference=15-value;
			if(difference>=0&&difference<=9)
				complement+=('0'+difference);
			else if(difference>=10&&difference<=15)
				complement+=('A'+(difference-10));
		}
	}
	return complement;
} 
