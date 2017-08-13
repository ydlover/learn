#include <iostream>
#include <stdio.h>
#include <list>
#include <stdlib.h>
#include "../include/comm.h"

#define INVALID 255

void sort(string &inStr)
{
	list<char> inChars;
	for(UINT16 usLoop = 0; usLoop <inStr.size(); usLoop++)
	{
		char ch = inStr.at(usLoop);
		inChars.push_back(ch);
		
	}
	inChars.sort();
	
	bool isFirst = true;
	for(list<char>::iterator it=inChars.begin();it!=inChars.end();it++)  
	{  
		if(isFirst)
		{
			isFirst = false;
		}
		else
		{
			cout<<' ';
		}
		cout<<*it;
	}  
	cout<<endl;
	
}
int main()
{
	UINT16 usNum = 0;
	cin>>usNum;

	usNum = MIN(usNum, 100);
	for(UINT16 usLoop = 0; usLoop<usNum;usLoop++)
	{
		string inputStr;
		cin>>inputStr;
		sort(inputStr);
	}
    return 0;
}