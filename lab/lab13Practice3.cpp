/*
This program will ask the user for weigh, height, and age then
calculate the hat size, jacket size, and waist size and display 
it to the user. It will repeat until they want to stop.
*/

#include<iostream>

using namespace std;

double hatSize(double weight, double height) {
    double hatSize = (weight / height) * 2.9;

    return hatSize;
}

double jacketSize(double height, double weight, double age) {
    int years = 0;

    if(age > 30) {
        age -= 30;
        while((age - 10) >= 0) {
            years ++;
            age -= 10;
        }
    }

    double jacketSize = (height * (weight / 288) + (.125 * years));

    return jacketSize;
}

double waistSize(double weight, double age) {
    int years = 0;

    if(age > 28) {
        age -= 28;
        while((age - 2) >= 0) {
            years ++;
            age -= 2;
        }
    }

    double waistSize = (weight / 5.7) + (.1 * years);

    return waistSize;
}

int main() {
    double weight, height, age, hatSizeOut, jacketSizeOut, waistSizeOut;
    char choice;

    do {
        cout << "Enter weight (pounds): ";
        cin >> weight;
        cout << "Enter height (inches): ";
        cin >> height;
        cout << "Enter age (years): ";
        cin >> age;

        hatSizeOut = hatSize(weight, height);
        jacketSizeOut = jacketSize(weight, height, age);
        waistSizeOut = waistSize(weight, age);

        cout << "Hat size: " << hatSizeOut << endl;
        cout << "Jacket size: " << jacketSizeOut << endl;
        cout << "Waist size: " << waistSizeOut << endl;

        cout << "Would you like to do another (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');

    return 0;
}

/*
The numbers I used to test the program are:

Input:
190
74
18
Output:
Hat size: 7.44595
Jacket size: 48.8194
Waist size: 33.3333
*/