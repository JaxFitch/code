/*
This program will ask the user for two numbers and then calculate the 
sum of the digits of each number and then add the two sums together.
*/

#include<iostream>

using namespace std;

int sumDigits(int n) {
    if (n == 0) {
        return 0;
    }

    return n % 10 + sumDigits(n / 10);
}

int main() {
    int userNum1, userNum2, total;

    cout << "Enter number 1: ";
    cin >> userNum1;
    cout << "Enter number 2: ";
    cin >> userNum2;

    total = sumDigits(userNum1) + sumDigits(userNum2);

    cout << "The sum of the digits of " << userNum1 << " and " << userNum2 << " is " << total << endl;

    return 0;
}

/*
The numbers I used to test the program are:

Input:
123
456
Output:
The sum of the digits of 123 and 456 is 21

Input:
765
432
Output:
The sum of the digits of 765 and 432 is 27
*/