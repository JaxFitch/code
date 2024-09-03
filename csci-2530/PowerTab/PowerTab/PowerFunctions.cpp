//PowerFunctions.cpp
//Author: Jackson Fitch

int RaiseIntToPower(int num, int power)
{
	int i, result;
	result = num;

	for (int i = 0; i < power; i++)
	{
		result *= num;
	}

	return result;
}