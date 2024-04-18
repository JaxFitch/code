#include <iostream>

using namespace std;

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    int digitCount = 0;
    int tempNumber = number;

    while (tempNumber != 0) {
        tempNumber /= 10;
        digitCount++;
    }

    cout << "The number " << number << " has " << digitCount << " digits" << endl;

    return 0;
}
