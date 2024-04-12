#include <iostream>

using namespace std;

int main() {
    double balance = 1000;
    double rate = 0.05;
    double years = 0;

    while (balance <= 2 * 1000) {
        balance += balance * rate;
        years++;
    }

    cout << "It will take " << years << " years for the balance to double." << endl;

    return 0;
}