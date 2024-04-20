/*
This program will ask the user for 10 numbers using a for loop
then return the largest, smallest, number of evens, & the sum
of all of the numbers.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    //Declare variables
    int user = 0;
    int sum = 0;
    int even = 0;
    int smallest = INFINITY;
    int largest = smallest * -1;
    int temp = 0;

    for(int i = 0; i < 10; i++) {
        //Get user input
        cout << "Enter a number: ";
        cin >> user;
        
        //Add to the sum
        sum += user;
        
        //Find if even
        if(user % 2 == 0) {
            even++;
        }
        
        //Find if largest
        if(user > largest) {
            largest = user;
        }

        //Find if smallest
        if(user < smallest) {
            smallest = user;
        }
    }

    //Display results
    cout << "The sum of the numbers is: " << sum << endl;
    cout << "There were " << even << " even numbers." << endl;
    cout << "The largest number is: " << largest << endl;
    cout << "The smallest number is: " << smallest << endl;

    return 0;
    }

/*
I tested this program with the numbers:

Input:
1, 2, 3, 4, 5, 6, 7, 8, 9, 10
Output:
The sum of the numbers is: 55
There were 5 even numbers.
The largest number is: 10
The smallest number is: 1
*/