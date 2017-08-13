#include <iostream>
#include <stdio.h>
#include <list>
#include <stdlib.h>
#include <cstring>
#include <cmath>
#include "../include/comm.h"

struct HOUSEHOLD
{
	UINT16 usX;
	UINT16 usY;
	HOUSEHOLD(UINT16 usX,UINT16 usY)
	{
		this->usX = usX;
		this->usY = usY;
		
	}
};
UINT16 pointDist(UINT16 usX1,UINT16 usY1,UINT16 usX2,UINT16 usY2)
{
	UINT16 usXdist = (usX1>=usX2)?(usX1-usX2):(usX2-usX1);
	UINT16 usYdist = (usY1>=usY2)?(usY1-usY2):(usY2-usY1);
	
	return usXdist+usYdist;
}

int main()
{
	vector<HOUSEHOLD> households;
	UINT16 usNum = 0;
	cin>>usNum;

	usNum = MIN(usNum, 20);
	for(UINT16 usLoop = 0; usLoop<usNum;usLoop++)
	{

		UINT16 usHouseholdNum = 0;
		cin>>usHouseholdNum;
		households.clear();
		usHouseholdNum = MIN(usHouseholdNum, 20);
		for(UINT16 usHouseholdLoop = 0; usHouseholdLoop<usHouseholdNum;usHouseholdLoop++)
		{
			UINT16 usX;
			UINT16 usY;
			cin>>usX>>usY;
			if(usX==0 || usX >=100)
			{
				return 0;
			}
			if(usY==0 || usY >=100)
			{
				return 0;
			}
			HOUSEHOLD h(usX,usY);
			households.push_back(h);
		}
		UINT32 ulMinDist = NULL_UINT32;
		for(UINT16 usXLoop = 1; usXLoop<100;usXLoop++)
		{
			for(UINT16 usYLoop = 1; usYLoop<100;usYLoop++)
			{
				UINT16 ulCurrDist = 0;
				for(UINT16 usHouseholdIndex = 0;usHouseholdIndex<households.size();usHouseholdIndex++)
				{
					UINT16 pd = pointDist(households[usHouseholdIndex].usX,households[usHouseholdIndex].usY,usXLoop,usYLoop);
					//cout<<"["<<households[usHouseholdIndex].usX<<","<<households[usHouseholdIndex].usY<<"]"<<pd<<" ";
					ulCurrDist+=pd;
				}
				//cout<<":"<<ulCurrDist<<":"<<usXLoop<<","<<usYLoop<<endl;
				if(ulCurrDist<ulMinDist)
				{
					ulMinDist = ulCurrDist;
				}
			}
		}
		cout<<ulMinDist<<endl;
	}
	
    return 0;
}