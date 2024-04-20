/*
This program will display every prime number between 3 and 100.
*/

#include <iostream>

using namespace std;

int main() {
    bool isPrime;
    for(int i = 3; i <= 100; i++) {
        isPrime = true;
        for (int n = 2; n < i; n++) {
            if (i % n == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) {
            cout << i << " ";
        }
    }
    return 0;   
}

/*
The output was:
3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
*/