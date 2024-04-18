// 1. Ask user for the amount of change
// 2. Use a series of mods and divides to find the amount of each coin needed to make the total change
// 3. Display the results to the user using a cout statement

#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int change , q , d , n , p ; 

    cout << "Enter a number between 0 to 99 for cents: " ; 
    cin >> change ;

    q = change / 25 ;
    change = change % 25 ;
    d = change / 10 ;
    change = change % 10 ; 
    n = change / 5 ;
    change  = change % 5 ;
    p = change / 1 ;

    cout << "Quarters: " << q << endl ;
    cout << "Dimes: " << d << endl ;
    cout << "Nickels: " << n << endl ;
    cout << "Pennies: " << p << endl ;

    return 0 ;
}