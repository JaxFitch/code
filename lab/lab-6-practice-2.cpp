#include<iostream>

using namespace std;

int main() {
    char gender;
    int weight, height, age;
    double bmr;

    cout << "Enter the gender , M for male, and F for female: ";
    cin >> gender;
    cout << "Enter the weight (pounds): ";
    cin >> weight;
    cout << "Enter the height (inches): ";
    cin >> height;
    cout << "Enter the age: ";
    cin >> age;

    if(gender == 'm' || gender == 'M') {
        bmr = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
    } else if(gender == 'f' || gender == 'F') {
        bmr = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
    } else {
        cout << "ERROR" << endl;
    }

    cout << "You can eat " << bmr / 230 << " chocolate bars!" << endl;
}