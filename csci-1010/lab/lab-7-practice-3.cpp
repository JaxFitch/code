/*
This program will ask the user for the year then determine if the year is a leap year.
*/

#include <iostream>

using namespace std;

int main() {
    // Decalre variables
    int year;

    // Ask the user for the year
    cout << "Enter the year: ";
    cin >> year;

    // Determine if the year is a leap year and display the result
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                cout << year << " is a leap year!" << endl;
            } else {
                cout << year << " is not a leap year!" << endl;
            }
        } else {
            cout << year << " is a leap year!" << endl;
        }
    } else {
        cout << year << " is not a leap year!" << endl;
    }
    
    return 0;
}

/*
The numbers I used to test the program are:
Year: 2023
Year: 1800
Year: 2010
Year: 2000

The results were:
2023 is not a leap year!
1800 is not a leap year!
2010 is not a leap year!
2000 is a leap year!
*/