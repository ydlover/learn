#include <iostream>
#include "../include/comm.h"
#define INVALID 255
UINT8 aucSelfChg[10][3] = { {9,INVALID,INVALID},
                            {INVALID,INVALID,INVALID},
                            {3,5,INVALID},
                            {2,5,INVALID},
                            {INVALID,INVALID,INVALID},
                            {2,3,INVALID},
                            {8,INVALID,INVALID},
                            {6,INVALID,INVALID},
                            {0,INVALID,INVALID}}；
UINT8 aucAddChg[10][3] = { {9,INVALID,INVALID},
                            {INVALID,INVALID,INVALID},
                            {INVALID,INVALID,INVALID},
                            {INVALID,INVALID,INVALID},
                            {INVALID,INVALID,INVALID},
                            {INVALID,INVALID,INVALID},
                            {INVALID,INVALID,INVALID},
                            {INVALID,INVALID,INVALID},
                            {INVALID,INVALID,INVALID}}；
UINT8 aucMinChg[10][3] = { {9,INVALID,INVALID},
                            {INVALID,INVALID,INVALID},
                            {INVALID,INVALID,INVALID},
                            {INVALID,INVALID,INVALID},
                            {INVALID,INVALID,INVALID},
                            {INVALID,INVALID,INVALID},
                            {INVALID,INVALID,INVALID},
                            {INVALID,INVALID,INVALID},
                            {INVALID,INVALID,INVALID}}；
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    cout << a+b << endl;
    return 0;
}