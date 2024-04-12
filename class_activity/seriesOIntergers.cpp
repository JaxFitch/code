#include <iostream>

using namespace std;

int main() {
    int num, sum = 0, count = 0, evenCount = 0, greaterThan20Count = 0;

    cout << "Enter a series of integers (end with 0): ";

    while (true) {
        cin >> num;

        if (num == 0) {
            break;
        }

        sum += num;
        count++;

        if (num % 2 == 0) {
            evenCount++;
        }

        if (num > 20) {
            greaterThan20Count++;
        }
    }

    double average = static_cast<double>(sum) / count;

    cout << "Average: " << average << endl;
    cout << "Even numbers count: " << evenCount << endl;
    cout << "Numbers greater than 20 count: " << greaterThan20Count << endl;

    return 0;
}