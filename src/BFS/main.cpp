#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
#include <stdlib.h>
#include "../include/comm.h"


using namespace std;
#define MAX_M 11
int matrix[MAX_M][MAX_M];

int visited[MAX_M];

int main()
{
	memset(matrix, 0,sizeof(matrix));
	int num = 0;
	cin>>num;
	for(int usLoop = 0; usLoop<num;usLoop++)
	{
		int g1,g2,var;
		cin>>g1>>g2>>var;
		matrix[g1][g2] = var;
		matrix[g2][g1] = var;
	}
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while(!q.empty())
	{
		int top = q.front();
		cout<<top<<" ";
		q.pop();
		for(int usLoop = 1;usLoop<MAX_M;usLoop++)
		{
			if(visited[usLoop] != 1 && matrix[top][usLoop]>0)
			{
				q.push(usLoop);
				visited[usLoop] = 1;
			}
		}

	}
    return 0;
}