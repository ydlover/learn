#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>
typedef signed char             INT8;
typedef short int               INT16;  
typedef int                     INT32; 
typedef unsigned char           UINT8;   
typedef unsigned short int      UINT16;  
typedef unsigned int            UINT32; 

#define MAX(v1,v2) ((v1>v2)?v1:v2) 
#define MIN(v1,v2) ((v1>v2)?v2:v1)
#define NULL_UINT32 0xFFFFFFFF
#define NULL_UINT16 0xFFFF
#define NULL_UINT8 0xFF

using namespace std;

struct RECTANGLE
{
	UINT16 usId;
	UINT16 usLength;
	UINT16 usWeight;
	RECTANGLE(UINT16 usId,UINT16 usLength,UINT16 usWeight)
	{
		this->usId = usId;
		this->usLength = usLength;
		this->usWeight = usWeight;
	}

};
class RectangleSortCriterion {  
    public:  
        bool operator() (const RECTANGLE &a, const RECTANGLE &b) const {  
            if(a.usId < b.usId)  
			{
                return true; 
			} 
			else if (a.usId == b.usId)
			{
				if(a.usLength < b.usLength)  
				{
					return true;  
				}
				else if (a.usLength == b.usLength)
				{            
					if(a.usWeight < b.usWeight)  
					{
                		return true;  
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
        }  
};  
int main()
{
	set<RECTANGLE, RectangleSortCriterion> rectangleSet;
	UINT16 usNum = 0;
	cin>>usNum;

	usNum = MIN(usNum, 10000);
	for(UINT16 usLoop = 0; usLoop<usNum;usLoop++)
	{
		UINT16 usRectangleNum = 0;
		cin>>usRectangleNum;
		rectangleSet.clear();
		usRectangleNum = MIN(usRectangleNum, 1000);
		for(UINT16 usRectangleLoop = 0; usRectangleLoop<usRectangleNum;usRectangleLoop++)
		{
			UINT16 usId;
			UINT16 usP1;
			UINT16 usP2;
			cin>>usId>>usP1>>usP2;
			if(usP1 > usP2)
			{
				RECTANGLE r(usId,usP1,usP2);
				rectangleSet.insert(r);
			}
			else
			{
				RECTANGLE r(usId,usP2,usP1);
				rectangleSet.insert(r);
			}
		}
		
		for(set<RECTANGLE, RectangleSortCriterion>::iterator it=rectangleSet.begin();it!=rectangleSet.end();it++)  
		{  
			cout<<it->usId<<" "<<it->usLength<<" "<<it->usWeight<<endl;
		}  
	}
	
    return 0;
}