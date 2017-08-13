#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include "../include/comm.h"
#include <stack>

#define INVALID 255
bool checkIsMatch(string &inStr)
{
	UINT16 openParenCnt  = 0;
	UINT16 closeParenCnt = 0;
	UINT16 openbracket   = 0;
	UINT16 closebracket  = 0;
	stack<char> chStacks;
	
	for(UINT16 usLoop = 0; usLoop <inStr.size(); usLoop++)
	{
		char ch = inStr.at(usLoop);
	
		switch(ch)
		{
			case '[':
				openbracket++;
				chStacks.push(ch);
				break;
			case ']':
				closebracket++;
				if(chStacks.empty())
				{
					return false;
				}
				if( chStacks.top() == '[')
				{
					chStacks.pop();
				}
				else
				{
					chStacks.push(ch);
				}
				break;
			case '(':
				openParenCnt++;
				chStacks.push(ch);
				break;
			case ')':
				closeParenCnt++;
				if(chStacks.empty())
				{
					return false;
				}
				if( chStacks.top() == '(')
				{
					chStacks.pop();
				}
				else
				{
					chStacks.push(ch);
				}
				break;
			default:
				return false;
				break;
		}
	}

	if ((openParenCnt != closeParenCnt)
		|| (openbracket != closebracket))
	{
		return false;
	}
	if(chStacks.size()>0)
	{
		return false;
	}
	return true;
	
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
		if(checkIsMatch(inputStr))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
    return 0;
}