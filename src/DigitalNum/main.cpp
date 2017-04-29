#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include "../include/comm.h"

#define INVALID 255
UINT8 aucSelfChg[10][3] = { {9,INVALID,INVALID},
                            {INVALID,INVALID,INVALID},
                            {3,5,INVALID},
                            {2,5,INVALID},
                            {INVALID,INVALID,INVALID},
                            {2,3,INVALID},
                            {8,INVALID,INVALID},
                            {INVALID,INVALID,INVALID},
                            {6,INVALID,INVALID},
                            {0,INVALID,INVALID}};
UINT8 aucAddChg[10][3] = { {6,8,INVALID},
                            {7,INVALID,INVALID},
                            {INVALID,INVALID,INVALID},
                            {0,9,INVALID},
                            {2,3,5},
                            {0,9,INVALID},
                            {INVALID,INVALID,INVALID},
                            {4,INVALID,INVALID},
                            {INVALID,INVALID,INVALID},
                            {6,8,INVALID}};
UINT8 aucMinChg[10][3] = { {3,5,INVALID},
                            {INVALID,INVALID,INVALID},
                            {4,INVALID,INVALID},
                            {4,INVALID,INVALID},
                            {7,INVALID,INVALID},
                            {4,INVALID,INVALID},
                            {0,9,INVALID},
                            {1,INVALID,INVALID},
                            {0,9,INVALID},
                            {3,5,INVALID}};
UINT8 aucNumToChar[] = {'0','1','2','3','4','5','6','7','8','9'};
UINT8 aucCharToNum[255] = { 0 };


typedef enum {
	ADD = 10,
	MIN = 11,
	EQUAL = 12,
	SELF = 13
}SYMBOL_TYPE_ENUM;

using namespace std;

string checkEqual(vector<UINT8> &NumList)
{
	string result;
	INT32 sum = 0;
	string temp;
	INT8 iSymobol = 1;
	bool isStartRight = false;
	for (UINT16 usLoop = 0; usLoop < NumList.size(); usLoop++)
	{
		if (NumList[usLoop] == ADD || NumList[usLoop] == MIN || NumList[usLoop] == EQUAL)
		{
			if (temp.size() > 0)
			{
				if (temp[0] == '0')
				{
					result.clear();
					return result;
				}
				UINT32 ulVar = atoi(temp.c_str());
				if (isStartRight)
				{
					sum += ulVar*iSymobol*-1;
				}
				else
				{
					sum += ulVar*iSymobol;
				}
				temp.clear();
			}
			if (NumList[usLoop] == ADD)
			{
				iSymobol = 1;

				result += "+";
				continue;
			}
			else if (NumList[usLoop] == MIN)
			{
				result += "-";
				iSymobol = -1;
				continue;
			}
			else if (NumList[usLoop] == EQUAL)
			{
				result += "=";
				iSymobol = 1;
				isStartRight = true;
				continue;
			}
		}
		else
		{
			result += aucNumToChar[NumList[usLoop]];
			temp += aucNumToChar[NumList[usLoop]];
		}
	}

	if (temp.size() > 0)
	{

		if (temp[0] == '0')
		{
			result.clear();
			return result;
		}
		UINT32 ulVar = atoi(temp.c_str());
		if (isStartRight)
		{
			sum += ulVar*iSymobol*-1;
		}
		else
		{
			sum += ulVar*iSymobol;
		}
		temp.clear();
	}
	if (sum != 0)
	{
		result.clear();
	}
	return result;
}

void chgNumList(vector<UINT8> gNumList,bool isNum1Add)
{

	for (UINT16 usNum1Loop = 0; usNum1Loop<gNumList.size(); usNum1Loop++)
	{
		if (gNumList[usNum1Loop] == ADD || gNumList[usNum1Loop] == MIN || gNumList[usNum1Loop] == EQUAL)
		{
			continue;
		}

		for (UINT16 usNum1ChgLoop = 0; usNum1ChgLoop < 3; usNum1ChgLoop++)
		{
				
			UINT8 ucAddTarget = INVALID;
			if (isNum1Add)
			{
				ucAddTarget = aucAddChg[gNumList[usNum1Loop]][usNum1ChgLoop];
			}
			else
			{
				ucAddTarget = aucMinChg[gNumList[usNum1Loop]][usNum1ChgLoop];
			}
			if (INVALID == ucAddTarget)
			{
				continue;
			}

			for (UINT16 usNum2Loop = 0; usNum2Loop < gNumList.size(); usNum2Loop++)
			{
				if (gNumList[usNum2Loop] == ADD || gNumList[usNum2Loop] == MIN || gNumList[usNum2Loop] == EQUAL)
				{
					continue;
				}

				for (UINT16 usNum2ChgLoop = 0; usNum2ChgLoop < 3; usNum2ChgLoop++)
				{
					UINT8 ucMinTarget = INVALID;
					if (isNum1Add)
					{
						ucMinTarget = aucMinChg[gNumList[usNum2Loop]][usNum2ChgLoop];
					}
					else
					{
						ucMinTarget = aucAddChg[gNumList[usNum2Loop]][usNum2ChgLoop];
					}
					vector<UINT8> newNumList = gNumList;
					newNumList[usNum1Loop] = ucAddTarget;
					newNumList[usNum2Loop] = ucMinTarget;

					string result = checkEqual(newNumList);
					if (result.size()>0)
					{
						cout << result << endl;
					}
				}
			}

		}

	}
}
int main()
{
	aucCharToNum['0'] = 0;
	aucCharToNum['1'] = 1;
	aucCharToNum['2'] = 2;
	aucCharToNum['3'] = 3;
	aucCharToNum['4'] = 4;
	aucCharToNum['5'] = 5;
	aucCharToNum['6'] = 6;
	aucCharToNum['7'] = 7;
	aucCharToNum['8'] = 8;
	aucCharToNum['9'] = 9;

    //string sin = "156+31=45+198-53"; //self
	string sin = "146+31=52+198-53"; //add,min
	//string sin = "156+91=45+199-53"; //min,add
    //cin>>sin;
	vector<UINT8> gNumList;

    for(UINT16 usLoop = 0; usLoop<sin.length();usLoop++)
    {
        if (sin[usLoop] == '-')
        {
			gNumList.push_back(MIN);
        }
        else if (sin[usLoop] == '+')
        {
			gNumList.push_back(ADD);
        }
        else if (sin[usLoop] == '=')
        {
			gNumList.push_back(EQUAL);
        }
        else
        {
            char numchar[2]; 
            numchar[0]= sin[usLoop];
            numchar[1]= '\0';
			gNumList.push_back(atoi(numchar));
		
        }
         
    }
    
    for(UINT16 usLoop = 0; usLoop<gNumList.size();usLoop++)
    {
		if (gNumList[usLoop] == ADD || gNumList[usLoop] == MIN || gNumList[usLoop] == EQUAL)
		{
			continue;
		}

		for (UINT16 usInnerLoop = 0; usInnerLoop < 3; usInnerLoop++)
		{
			UINT8 ucTarget = aucSelfChg[gNumList[usLoop]][usInnerLoop];
			if (INVALID == ucTarget)
			{
				continue;
			}
			vector<UINT8> newNumList = gNumList;
			newNumList[usLoop] = ucTarget;
			string result = checkEqual(newNumList);
			if (result.size()>0)
			{
				cout << result << endl;
			}
		}
		
		chgNumList(gNumList,true);
		chgNumList(gNumList, false);
    }


    return 0;
}