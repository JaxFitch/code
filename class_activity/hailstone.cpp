#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int steps = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
            cout << n << endl;
        } else {
            n = 3 * n + 1;
            cout << n << endl;
        }
        steps++;
    }

    cout << "It took " << steps << " steps to reach 1." << endl;

    return 0;
}