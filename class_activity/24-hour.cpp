#include<iostream>

using namespace std;

int main() {
    int minutes, hours;

    cout << "Enter the hour in 24 hour format: ";
    cin >> hours;
    cout << "Enter the minutes: ";
    cin >> minutes;


    if(hours > 24 || minutes > 60) {
        cout << "Invalid time" << endl;
    } else if(hours > 12) {
        hours -= 12;
        cout << "The time in 12 hour format is: " << hours << ":" << minutes << " PM" << endl;
    } else {
        cout << "The time in 12 hour format is: " << hours << ":" << minutes << " AM" << endl;
    }

    return 0;
}