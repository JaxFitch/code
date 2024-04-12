// 1. Ask the user if they would like to convert celcius to fahrenheit or fahrenheit to celcius
// 2. Use an if and if else statement to determine which conversion to perform
// 3. Ask the user for the temperature in fahrenheit or celcius depending on what the user chooses
// 4. Use the formulas to calculate the temperature in fahrenheit or celcius depending on what the user chooses
// 5. Display the temperature conversion result

#include<iostream>
#include<cmath>

using namespace std ;

int main() {
    int type ;
    double c , f ;

    cout << "Enter 1 for converting Farenheit to Celsius,\nor, enter 2 for converting Celsius to Farenheit: " ;
    cin >> type ;

    if (type == 1) {
        cout << "Now, enter the temperature fahrenheit: " ;
        cin >> f ;
        c = 5 * (f - 32) / 9 ;
        cout << "The temperature is " << c << " in Celcius" << endl ;
    }
    else if (type == 2) {
        cout << "Now, enter the temperature in celcius: " ;
        cin >> c ;
        f = ((9 * c) / 5)+ 32 ;
        cout << "The temperature is " << f << " in Fahrenheit" << endl ;
    }

    return 0 ;
}