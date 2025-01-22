// Jackson Fitch

// This program adds two large integers, and prints the result to the screen

#include <cctype>
#include <iostream>
using namespace std;

// Max number of digits in the large integer
const int MAXSIZE = 25;

// Initializes an integer array so that all positions are holding the value zero.
void initArray(int array[]);

// Gets a large integer from the keyboard and stores each individual digit
// into the array.
void getNum(int array[]);

// Prints a large integer to the screen. Leading zeros are not printed.
void printNum(int array[]);

// Adds two large intergers and stores the result in the result array and returns true 
// if there is no integer overflow
bool addNumbers(int num1[], int num2[], int result[]);


int main()
{
	// Initialize the arrays and fill with zeross
	int num1[MAXSIZE], num2[MAXSIZE], result[MAXSIZE];
	initArray(num1);
	initArray(num2);
	initArray(result);

	// Recive user input for the two large integers and store them in the arrays
	getNum(num1);
	getNum(num2);

	// Add the two large integers and store the result in the result array
	if(addNumbers(num1, num2, result) == true)
	{
		cout << "             Sum: ";
		printNum(result);
	}
	else
	{
		cout << "Interger overflow\n";
	}

	cout << endl;
	return 0;
}

void initArray(int array[])
{
	// Fill array with zeros
	for(int i = 0; i < MAXSIZE; i++)
	{
		array[i] = 0;
	}
}


void printNum(int array[])
{
	bool leadingZero = true;

	// Check for leading zeros and print the large integer
	for(int i = MAXSIZE - 1; i >= 0; i--)
	{
		if(array[i] != 0)
		{
			leadingZero = false;
		}

		if(!leadingZero)
		{
			cout << array[i];
		}
	}

	if(leadingZero)
	{
		cout << "0";
	}
}


void getNum(int array[])
{
	char input[MAXSIZE + 1];
	int length;
	bool inputOkay;

	do
	{
		inputOkay = true;

		cout << "Enter an integer: ";
		cin.getline(input, MAXSIZE + 1);

		// If user entered more than the max number of digits
		// then make them enter the large integer again
		while(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Integer too long\n";
			cout << "Enter an integer: ";
			cin.getline(input, MAXSIZE + 1);
		}

		// Check to ensure that the user did not enter any non-digit values
		length = (int)strlen(input);
		for(int x = 0; x < length && inputOkay; x++)
		{
			if(!isdigit(input[x]))
			{
				inputOkay = false;
				cout << "Invalid input\n";
			}
		}
	} while(!inputOkay);

	// Store the large integer in the array
	for(int i = 0; i < length; i++)
	{
		array[i] = input[length - 1 - i] - '0';
	}
}

bool addNumbers(int num1[], int num2[], int result[])
{
	int carry = 0;

	// Add the two large integers
	for(int i = 0; i < MAXSIZE; i++)
	{
		int sum = num1[i] + num2[i] + carry;
		result[i] = sum % 10;
		carry = sum / 10;
	}

	// Check for integer overflow
	if(carry > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}