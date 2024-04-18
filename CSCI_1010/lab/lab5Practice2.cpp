// 1. Ask user for the year , month , and day in seperate statments then store them in variables
// 2. Use the formulas for the Gregorian calender to calculate what day of the week it is
// 3. Display the day of the week to the user

#include<iostream> 
#include<cmath>

using namespace std ;

int main() {
    int year , month , day , y , x , m , d ;

    cout << "Enter the year : " ;
    cin >> year ;
    cout << "Enter the month : " ;
    cin >> month ;
    cout << "Enter the day : " ;
    cin >> day ;

    y = year - (14 - m) / 12 ;
    x = y + y/4 -y / 100 + y / 400 ;
    m = month + 12 * ((14 - m) / 12) - 2 ;
    d = (day + x + (31 * m) / 12) % 7 ;

    cout << "The day of the week is : " << d << endl ;

    return 0 ;
}