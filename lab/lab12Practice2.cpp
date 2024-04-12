/*
This program will ask the user to enter an integer and then reverse 
the digits and display the reversed number to the user.
*/

#include <iostream>

using namespace std;

int reverseDigits(int num) {
    //Declare variables
    int reversedNum = 0;

    //Reverse the digits of the number
    while (num != 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    return reversedNum;
}

int main() {
    //Declare variables
    int num;

    //Get user input
    cout << "Enter an integer: ";
    cin >> num;

    //Use the function to reverse the digits of the number
    int reversedNum = reverseDigits(num);

    //Display the reversed number to the user
    cout << "Reversed number: " << reversedNum << endl;

    return 0;
}

/*
The inputs I used to test the program are as follows:

Input:
123
Output:
Reversed number: 321

Input:
456
Output:
Reversed number: 654

Input:
78924
Output:
Reversed number: 42987
*/