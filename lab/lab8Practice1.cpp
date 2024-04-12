// 1. Ask user for the year , month , and day in seperate statments then store them in variables
// 2. Use the formulas for the Gregorian calender to calculate what day of the week it is
// 3. Display the day of the week to the user in a sentence

#include<iostream> 

using namespace std ;

int main() {
    //Declare variables
    int year , month , day , y , x , m , d ;

    //Ask user for the year
    cout << "Enter the year : " ;
    cin >> year ;

    //Ask user for the month
    cout << "Enter the month : " ;
    cin >> month ;

    //Ask user for the day
    cout << "Enter the day : " ;
    cin >> day ;

    //Calculate the day of the week
    y = year - (14 - m) / 12 ;
    x = y + y/4 -y / 100 + y / 400 ;
    m = month + 12 * ((14 - m) / 12) - 2 ;
    d = (day + x + (31 * m) / 12) % 7 ;

    //Display the day of the week
    switch(d) {
        case 0 :
            cout << "The day of the week is : Sunday" << endl ;
            break ;
        case 1 :
            cout << "The day of the week is : Monday" << endl ;
            break ;
        case 2 :
            cout << "The day of the week is : Tuesday" << endl ;
            break ;
        case 3 :
            cout << "The day of the week is : Wednesday" << endl ;
            break ;
        case 4 :
            cout << "The day of the week is : Thursday" << endl ;
            break ;
        case 5 :
            cout << "The day of the week is : Friday" << endl ;
            break ;
        case 6 :
            cout << "The day of the week is : Saturday" << endl ;
            break ;
    }

    return 0 ;
}

/*
The numbers I used to test the program are:

Month: 2
Day: 29
Year: 2024
Output: The day of the week is : Thursday

Month: 3
Day: 1
Year: 2024
Output: The day of the week is : Friday

Month: 4
Day: 2
Year: 2024
Output: The day of the week is : Sunday
*/