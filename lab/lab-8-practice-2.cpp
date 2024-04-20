/* 
This progam is a simple rock paper sissors game. The game will have 2 users and 
each will have a turn to choose rock paper or sissors. After each choice it will
clear the terminal so that the other player wont see the first players choice.
The program will then display the winner of the game.
*/

#include <iostream>
#include <stdlib.h>

using namespace std ;

int main() {
    //Declare variables
    char p1, p2 ;

    //Ask for the player 1's choice
    cout << "Player 1 enter your choice (R, P, S): " ;
    cin >> p1 ;
    p1 = toupper(p1) ;

    //Clear the terminal
    #ifdef _WIN32
    system("cls") ;
    #elif __APPLE__
    system("clear") ;
    #endif

    //Ask for the player 2's choice
    cout << "Player 2 enter your choice (R, P, S): " ;
    cin >> p2 ;
    p2 = toupper(p2) ;

    //Clear the terminal
    #ifdef _WIN32
    system("cls") ;
    #elif __APPLE__
    system("clear") ;
    #endif

    //Display the winner
    if (p1 == p2) {
        cout << "It's a tie!" << endl ;
    } else if (p1 == 'R' && p2 == 'S' || p1 == 'P' && p2 == 'R' || p1 == 'S' && p2 == 'P') {
        cout << "Player 1 wins!" << endl ;
    } else {
        cout << "Player 2 wins!" << endl ;
    }

    return 0 ;
}

/*
The numbers I used to test the program are:

Player 1: S
Player 2: R
Output: Player 2 wins!

Player 1: P
Player 2: R
Output: Player 1 wins!

Player 1: S
Player 2: P
Output: Player 1 wins!

Player 1: R
Player 2: R
Output: Tie
*/