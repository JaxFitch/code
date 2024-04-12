/* 
This program will ask the user for the time that they started their call and 
the time that they ended their call. It will then calculate the total cost of
the call depending on the time that the call was started. If the call was started
between 8am and 6pm, the cost will be $0.40 per minute. If the call was started
outside of that time frame, the cost will be $0.25 per minute.
*/

#include <iostream>

using namespace std;

int main() {
    // Declare variables
    int startHour, startMinute, endHour, endMinute, totalMinutes, totalCost;
    double rate1 = .40, rate2 = .25;

    // Get user input
    cout << "Enter the starting time (24h): ";
    cin >> startHour >> startMinute;

    cout << "Enter the ending time (24h): ";
    cin >> endHour >> endMinute;

    // Calculate total minutes
    totalMinutes = ((endHour * 60) + endMinute) - ((startHour * 60) + startMinute);

    // Calculate cost total cost depending on what time it was started
    if(startHour >= 8 && startHour <= 18) {
        totalCost = totalMinutes * rate1;
        cout << "The cost is: $" << totalCost << endl; 
    } else {
        totalCost = totalMinutes * rate2;
        cout << "The cost is: $" << totalCost << endl;
    }

    return 0;
}

/*
The numbers I used to test this program are as follows:
Start time: 16:45
End time: 17:25
*/