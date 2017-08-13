#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
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

inline bool isPointInLine(INT32 xDelta,INT32 yDelta,INT32 x1,INT32 y1,INT32 x,INT32 y)
{
	return yDelta*(x-x1) == xDelta*(y-y1);
}
int main()
{
	INT32 ulX1,ulY1,ulX2,ulY2;
	INT32 lMinX,lMaxX,lMinY,lMaxY;
	UINT32 ulNum = 0;
	cin>>ulNum;

	for(UINT32 ulLoop = 0; ulLoop<ulNum;ulLoop++)
	{
		cin>>ulX1>>ulY1>>ulX2>>ulY2;
		
		INT32 xDelta, yDelta;
		xDelta=ulX2-ulX1;
		yDelta=ulY2-ulY1;
		
		lMinX = MIN(ulX1,ulX2);
		lMinY = MIN(ulY1,ulY2);
		lMaxX = MAX(ulX1,ulX2);
		lMaxY = MAX(ulY1,ulY2);
		bool notIsFirst = false;
		for(INT32 lLoopX = lMinX; lLoopX<=lMaxX;lLoopX++)
		{
			for(INT32 lLoopY = lMinY; lLoopY<=lMaxY;lLoopY++)
			{
				if(isPointInLine(xDelta,yDelta,ulX1,ulY1,lLoopX,lLoopY))
				{
					if(notIsFirst)
					{
						printf(",");
					}
					notIsFirst = true;
					printf("(%ld,%ld)",lLoopX,lLoopY);
				}
			}
		}
		cout<<endl;
	}
	
    return 0;
}