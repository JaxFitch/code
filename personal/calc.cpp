#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string operation;
  double number1, number2;

  cout << "Enter first number: ";
  cin >> number1;
  cout << "Enter operation (+, -, *, /): ";
  cin >> operation;
  cout << "Enter second number: ";
  cin >> number2;

  if (operation == "+") {
    cout << number1 + number2 << endl;
  } else if (operation == "-") {
    cout << number1 - number2 << endl;
  } else if (operation == "*") {
    cout << number1 * number2 << endl;
  } else if (operation == "/") {
    cout << number1 / number2 << endl;
  } else {
    cout << "Invalid operation" << endl;
  }

  return 0;
}
