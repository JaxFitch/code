/*
This program will allow the user to input a fraction and find the lowest
and most simple form of the freaction.
*/

#include <iostream>

using namespace std;

int main() {
    int num, den;

    cout << "Enter the numerator: ";
    cin >> num;
    cout << "                   -------" << endl;
    cout << "Enter The denominator: ";
    cin >> den;

    if (den == 0) {
        cout << "The denominator cannot be 0";
    } else {
        int m = num;
        int n = den;
        while (n != 0) {
            int remainder = m % n;
            m = n;
            n = remainder;
        }
        num /= m;
        den /= m;
        if (den < 0) {
            num *= -1;
            den *= -1;
        }
        cout << "The simplified fraction is: " << num << "/" << den;
    }

    return 0;
}

/*
The numbers I used to test the program are:

Input:
3/9
Output:
1/3

Input:
12/24
Output:
1/2
*/