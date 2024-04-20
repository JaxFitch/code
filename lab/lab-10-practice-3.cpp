/*
This program will calculate the decimal value of a binary number.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int bin = 0;
    int dec = 0;
    int d = 0;

    cout << "Enter a binary number: ";
    cin >> bin;

    for(int i = 0; bin > 0; i++) {
        d = bin % 10;
        bin = bin / 10;
        dec += d * pow(2, i);
    }

    cout << "Decimal value = " << dec << endl ;

    return 0;
}

/*
The numbers I used to test the program are:

Input:
10110110
Output:
Decimal value = 182

Input:
11111111
Output:
Decimal value = 255
*/