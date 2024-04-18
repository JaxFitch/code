#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int grade;

    cout << "Enter your grade: ";
    cin >> grade;
    if (grade < 0 || grade > 100) {
        cout << "Invalid grade" << endl;
    } else if (grade < 60) {
        cout << "Your grade is an F" << endl;
    } else if (grade < 70) {
        cout << "Your grade is a D" << endl;
    } else if (grade < 80) {
        cout << "Your grade is a C" << endl;
    } else if (grade < 90) {
        cout << "Your grade is a B" << endl;
    } else {
        cout << "Your grade is an A" << endl;
    } 

    return 0;
}