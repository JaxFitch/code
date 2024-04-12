#include<iostream>

using namespace std ;

int main() {
    // Intitialize variables
    double total ;
    double tip ;
    int people ; 

    // Get user input for total
    cout << "Total: " ;
    cin >> total ;

    // Get user input for tip
    cout << "Tip %: " ;
    cin >> tip ; 

    // Get user input for people
    cout << "People:" ;
    cin >> people ;

    // Calculate and display the total for each person
    cout << "The total for each person is: $" << (total + (total * tip / 100)) / people << endl ;

    return 0 ;
}