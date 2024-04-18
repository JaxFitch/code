// 1. Ask user for 4 digit binary number using cin and cout
// 2. Use modulus 10 and divide 10 4 times to separate each binary number
// 3. Use the formuala to convert binary to decimal and declare that calue to dec
// 4. Display dec using cout

#include<iostream>

using namespace std ;

int main () {
    int bin, d1, d2, d3, d4, dec ;

    cout << "Enter a 4 digit binary number: " ;
    cin >> bin ;

    d1 = bin % 10 ;
    bin = bin / 10 ;

    d2 = bin % 10 ;
    bin = bin / 10 ;

    d3 = bin % 10 ;
    bin = bin / 10 ;

    d4 = bin % 10 ;

    dec = (d4 * 8) + (d3 * 4) + (d2 * 2) + (d1 * 1) ;
    cout << "Decimal value = " << dec << endl ;

    return 0 ;
}