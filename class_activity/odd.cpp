#include<iostream>

using namespace std;

int main() {
    int interger;

    cout << "Enter an interger: ";
    cin >> interger;

    if (interger % 2 == 0 && interger > 10 && interger < 100) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}