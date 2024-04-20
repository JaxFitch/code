/*
This program will ask the user for their account balance then calculate 
the interest due, the total amount due, and the minimum payment.
*/

#include <iostream>

using namespace std;

int main() {
    // Declare variables
    double balance, interest, minimumPayment, totalAmount;

    // Ask the user for their account balance
    cout << "Enter the balance: $";
    cin >> balance;

    // Calculate the interest due
    if (balance <= 1000) {
        interest = balance * 0.015;
    } else {
            interest = 1000 * 0.015 + (balance - 1000) * 0.01;
    }

    // Calculate the total amount due
    totalAmount = balance + interest;

    // Calculate the minimum payment
    if (totalAmount <= 10) {
        minimumPayment = totalAmount;
    } else if (totalAmount <= 100) {
        minimumPayment = 10;
    } else {
        minimumPayment = totalAmount * 0.1;
    }

    // Output the results
    cout << "The interest due is: $" << interest << endl;
    cout << "The total amount due is: $" << totalAmount << endl;
    cout << "The minimum payment is: $" << minimumPayment << endl;

    return 0;
}

/*
The numbers I used to test the program are:
Account balance: $24.89

The results were:
The interest due is: $24.89
The total amount due is: $2013.89
The minimum payment is: $201.389
*/