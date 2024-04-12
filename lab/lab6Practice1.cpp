#include<iostream>

using namespace std;

int main() {
    char choice;

    cout << "Enter F for female or M for male: ";
    cin >> choice;

    if (choice == 'F' || choice == 'f') {
        cout << "Good morning, Mrs ECU" << endl;
    } else if (choice == 'M' || choice == 'm') {
        cout << "Good morning, Mr ECU" << endl;
    } else {
        cout << "Invalid choice" << endl;
    }
}