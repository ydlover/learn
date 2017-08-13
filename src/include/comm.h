#ifndef __COMM_H__
#define __COMM_H__

#include <vector>
#include <string>

typedef signed char             INT8;
typedef short int               INT16;  
typedef int                     INT32; 
typedef unsigned char           UINT8;   
typedef unsigned short int      UINT16;  
typedef unsigned int            UINT32; 
#define NULL_UINT32 0xFFFFFFFF
#define NULL_UINT16 0xFFFF
#define NULL_UINT8 0xFF

#define MAX(v1,v2) ((v1>v2)?v1:v2) 
#define MIN(v1,v2) ((v1>v2)?v2:v1)

using namespace std;

#endif