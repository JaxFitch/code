#include<iostream>
#include<cmath>

using namespace std;

int main() {
    double subTotal, total;

    cout << "Enter the subtotal: ";
    cin >> subTotal;

    if(subTotal >= 50 && subTotal < 75) {
        total = subTotal - 10;
    }
    else if(subTotal >= 75 && subTotal < 100) {
        total = subTotal - 20;
    }
    else if(subTotal >= 100) {
        total = subTotal - 30;
    }

    cout << "The total is: $" << total << endl;

    return 0;
}