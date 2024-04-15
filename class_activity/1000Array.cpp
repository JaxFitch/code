#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int SIZE = 1000;
    int arr[SIZE];

    srand(time(0));
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 101;
    }

    displayArray(arr, 10);

    arr[10] = 80;

    for (int i = 11; i > 1; i--) {
        arr[i] = arr[i - 1];
    }

    arr[1] = 50;

    for (int i = 2; i < 11; i++) {
        arr[i] = arr[i + 1];
    }

    displayArray(arr, 11);

    return 0;
}