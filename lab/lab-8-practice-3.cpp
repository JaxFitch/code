/*
This program will add up the numbers 1/1, 1/2, 1/3, ... 1/100
and display the total to the user.
*/

#include <iostream>

using namespace std ;

int main() {
    //Declare variables
    double num = 1 ;
    double den = 1 ;
    double total = 0 ;

    //Add up the numbers
    while(den != 101) {
        total += num / den ;
        den++ ;
    }

    //Display the total
    cout << "The total is: " << total << endl ;

    return 0 ;
}

/*
The output of the program is:

The total is: 5.18738
*/