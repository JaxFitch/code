#include<iostream>

using namespace std;

int main() {
    double grade, weight;

    cout << "Enter the grade: ";
    cin >> grade;
    cout << "Enter the weight: ";
    cin >> weight;
    
    if(grade < 0 || grade > 100 || weight < 0 || weight > 100) {
        cout << "Invalid grade or weight" << endl;
    } else if(grade >= 90) {
        cout << "A" << endl;
    } else if(grade >= 80) {
        cout << "B" << endl;
    } else if(grade >= 70) {
        cout << "C" << endl;
    } else if(grade >= 60) {
        cout << "D" << endl;
    } else {
        cout << "F" << endl;
    }
    