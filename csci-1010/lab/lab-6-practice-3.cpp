#include<iostream>
#include<cmath>

using namespace std;

int main() {
    char operation;
    double num1, num2, result;

    cout << "Enter the operation (+, -, *, /, ^): ";
    cin >> operation;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    if(operation == '+') {
        result = num1 + num2;
    } else if(operation == '-') {
        result = num1 - num2;
    } else if(operation == '*') {
        result = num1 * num2;
    } else if(operation == '/') {
        result = num1 / num2;
    } else if(operation == '^') {
        result = pow(num1, num2);
    } else {
        cout << "ERROR" << endl;
    }
    
    cout << num1 << " " << operation << " " << num2 << " = " << result << endl;
}