#include<iostream>
#include<cmath>

using namespace std ;

int main () {
    double hours, payRate = 16.78;

    cout << "Enter the amout of hours: " ;
    cin >> hours ;


    if (hours > 40) {
        cout << "Your payout will be: $" << (40 * payRate) + ((hours - 40) * payRate) * 1.5 ;
    }
    else {
        cout << "Your payout will be: $" << hours * payRate ;
    }
    
    return 0 ;
}