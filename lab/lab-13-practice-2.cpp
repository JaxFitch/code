/*
This program will ask the user for a weight in pounds and then 
convert it to kilograms. At the end it will ask if the user wants
to convert another weight.
*/

#include<iostream>

using namespace std;

double inputNumber() {
    double num;

    cout << "Enter a weight in pounds: ";
    cin >> num;

    return num;
}

double convertToKilograms(double pounds) {
    return pounds * 0.453592;
}

void outputResult(double pounds, double kilograms) {
    cout << pounds << " pounds is equal to " << kilograms << " kilograms." << endl;
}

int main() {
    double pounds, kilograms;
    char choice;

    do {
        pounds = inputNumber();
        kilograms = convertToKilograms(pounds);
        outputResult(pounds, kilograms);

        cout << "Do you want to convert another weight? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');
    
    return 0;
}

/*
The iputs I used to test the program are:

Input:
100
Output:
100 pounds is equal to 45.3592 kilograms.
Input:
n

Input:
200
Output:
200 pounds is equal to 90.7184 kilograms.
Input:
y
Input:
300
Output:
300 pounds is equal to 136.078 kilograms.
Input:
n
*/