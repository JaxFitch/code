//PowerTab
//Author: Jackson Fitch

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;

	for (int n = 0; n <=12; n++)
	{
		cout << "  0 |   0 |    1\n";
		cout << "  " << n << " |   " << n * n << " |    " << pow(2, n);
	}
		return 0;
} 