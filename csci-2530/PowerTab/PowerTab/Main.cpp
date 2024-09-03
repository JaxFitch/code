//PowerTab.cpp
//Author: Jackson Fitch

#include <iostream>
#include "PowerFunctions.h"
using namespace std;

//Global constants
const int LOWERLIMIT = 0;
const int UPPERLIMIT = 12;

int main()
{
	printf("    |   2 |    N\n");
	printf("  N |  N  |   2\n");
	printf("----+-----+-----\n");

	for (int n = LOWERLIMIT; n <= UPPERLIMIT; n++)
	{	
		int p1 = RaiseIntToPower(n, 2);
		int p2 = RaiseIntToPower(2, n);

		printf(" %2d | %3d | %4d\n", n, p1, p2);
		
	}
		return 0;
} 