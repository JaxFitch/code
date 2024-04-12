#include <iostream>

using namespace std;

int main() {
    int total = 0;
    for (int i = 1; i <= 100; i++) {
        if (i % 2 != 0) {
            total += i;
        }
    }
    cout << "The sum of all odd numbers from 1 to 100 is: " << total << endl;

    return 0;
}