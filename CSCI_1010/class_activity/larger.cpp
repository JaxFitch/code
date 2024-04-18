#include<iostream>
#include<cmath>

using namespace std ;

int main () {
    double a , b ;

    cout << "Enter first number: " ;
    cin >> a ;
    cout << "Enter first number: " ;
    cin >> b ;

    if (a > b) {
        cout << "The larger number is: " << a << endl ;
    }
    else if (b > a) {
        cout << "The larger number is: " << b << endl ;
    }
    else {
        cout << "The numbers are equal" << endl ;
    }

    return 0 ;
}