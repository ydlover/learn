#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include "../include/comm.h"


using namespace std;

struct Point
{
	UINT16 usX;
	UINT16 usY;
	Point(UINT16 usX,UINT16 usY)
	{
		this->usX = usX;
		this->usY = usY;
		
	}

	bool operator < (const Point& target) { 
		return this->usX < target.usX || this->usY < target.usY;
    } 
};

int main()
{
	vector<Point> points;
	points.push_back(Point(3,5));
	points.push_back(Point(4,6));
	points.push_back(Point(5,4));
	points.push_back(Point(3,5));
	points.push_back(Point(5,3));

	sort(points.begin(),points.end());
	bool ret = Point(3,5)<Point(5,4);
	cout<<ret<<endl;
	ret = Point(5,4)<Point(3,5);
	cout<<ret<<endl;
	for(UINT16 usLoop = 0; usLoop<points.size();usLoop++)
	{
		cout<<points[usLoop].usX<<","<<points[usLoop].usY<<endl;
	}
	UINT16 temp;
	cin>>temp;
    return 0;
}