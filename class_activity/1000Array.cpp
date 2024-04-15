#include <iostream>
#include <cstdlib>
#include <ctime>

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int SIZE = 1000;
    int arr[SIZE];

    // Initialize the first 10 elements with random numbers between [0, 100]
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 101;
    }

    // Display the current elements
    displayArray(arr, 10);

    // Append 80 to the end of the list
    arr[10] = 80;

    // Insert 50 as the new second element
    for (int i = 11; i > 1; i--) {
        arr[i] = arr[i - 1];
    }
    arr[1] = 50;

    // Delete the third element from the list
    for (int i = 2; i < 11; i++) {
        arr[i] = arr[i + 1];
    }

    // Display the updated elements
    displayArray(arr, 11);

    return 0;
}