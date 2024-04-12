// 1. Initialize the varialbles you will need
// 2. Ask the user for a 2 digit number using cout and cin
// 3. Set tens value by deviding by 10 
// 4. Set ones value by using modulus 10
// 5. Redefine userNum as ones multiplied by 10 + tens 
// 6. Display userNum to the user

#include<iostream>

using namespace std ;

int main () {
    int userNum, tens, ones ;

    cout << "Enter a 2 digit number: " ;
    cin >> userNum ;

    tens = userNum / 10 ;
    ones = userNum % 10 ;
    userNum = (ones * 10) + tens ;

    cout << "Flipped: " << userNum << endl;

    return 0 ;
}