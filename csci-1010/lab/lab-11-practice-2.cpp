/*
This program will ask the user for a number. It will then display
every fibonacci number up to the number that the user entered.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    //Declare variables
    int n = 0;
    int temp = 0;
    int list[1000];
    list[0] = 1;
    list[1] = 1;
    
    //Get user input
    cout << "Enter a number: ";
    cin >> n;

    // Calculate fibonacci numers
    for(int i = 2; i < n; i++) {
        if(n > 1) {
            list[i] = list[i - 1] + list[i - 2];
        } else if(n == 1) {
            cout << list[0] << " ";
            cout << list[1];
        } else if(n == 0) {
            cout << list[0];
        }
    }

    //Display results
    for(int i = 0; i < n; i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
I tested this program with the numbers:

Input:
10
Output:
1 1 2 3 5 8 13 21 34 55 
*/