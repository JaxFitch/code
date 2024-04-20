/*
This program will ask the user to enter a character and the test
to see if it is an alphabetical letter or not and then display 
that to the user.
*/

#include <iostream>

using namespace std;

bool isAlphabetical(char ch) {
    //Check if the character is an alphabetical letter
    if(ch >= 'A' && ch <= 'z') {
        return true;
    } else {
        return false;
    }
}

int main() {
    //Declare variables
    char ch;

    //Get user input
    cout << "Enter a character: ";
    cin >> ch;

    //Use the function to check if the character is an alphabetical letter
    if(isAlphabetical(ch)) {
        cout << "The character you entered is an alphabetical letter." << endl;
    } else {
        cout << "The character you entered is not an alphabetical letter." << endl;
    }

    return 0;
}

/*
The inputs I used to test the program are as follows:

Input:
b
Output:
The character you entered is an alphabetical letter.

Input:
$
Output:
The character you entered is not an alphabetical letter.

Input:
z
Output:
The character you entered is an alphabetical letter.
*/