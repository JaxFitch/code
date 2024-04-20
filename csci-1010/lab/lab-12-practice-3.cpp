/*
This program calculates the distance between a point and the origin 
using the distance formula. Then display the distance to the user.
*/

#include <iostream>
#include <cmath>

using namespace std;


double calculateDistance(double x, double y) {
    //Initialize the distance variable and calculate the distance
    double distance = sqrt(x * x + y * y);

    return distance;
}

int main() {
    //Declare variables
    double x, y;

    //Get user input
    cout << "Enter the x value: ";
    cin >> x;
    cout << "Enter the y value: ";
    cin >> y;
    
    //Use the function to calculate the distance between the point and the origin
    double distance = calculateDistance(x, y);

    //Display the distance to the user
    cout << "The distance between the point (" << x << ", " << y << ") and the origin is: " << distance << endl;
    
    return 0;
}

/*
The inputs I used to test the program are as follows:

Input:
3 4
Output:
The distance between the point (3, 4) and the origin is: 5

Input:
5 12
Output:
The distance between the point (5, 12) and the origin is: 13

Input:
8 15
Output:
The distance between the point (8, 15) and the origin is: 17
*/