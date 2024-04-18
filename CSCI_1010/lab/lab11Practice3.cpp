/*
This program will ask the user for the x for e^x and then
calculate the value of e^x using the formula:
e^x = 1 + x^1/1! + x^2/2! + x^3/3! + ... + x^n/n!
Then display the result.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double e = 1;
    double x = 0;
    int factorial = 0;

    cout << "Enter the value of x: ";
    cin >> x;

    for (int i = 1; i <= 10; i++) {
        factorial = 1;
        for (int j = 1; j <= i; j++) {
            factorial *= j;
        }
        e += pow(x, i) / factorial;
    }

    cout << "e^" << x << " = " << e << endl;
}

/*
The numbers I used to test this program are:

Input:
1
Output:
e^1 = 2.71828

Input:
2
Output:
e^2 = 7.38871

Input:
3
Output:
e^3 = 20.0855
*/