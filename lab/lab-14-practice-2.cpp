/*
This program will use functions to initialize an array with random numbers, 
display the elements of the array, and reverse the elements of the array.
*/

#include<iostream>

using namespace std;

void initArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 61 + 20;
    }
}

void displayElements(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverseArray(int arr[], int size) {
    for(int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main() {
    int arr[20];
    int size = 20;

    initArray(arr, size);
    displayElements(arr, size);

    reverseArray(arr, size);
    displayElements(arr, size);
}

/*
The output of this program is:

52 68 73 41 26 51 35 64 31 33 44 54 28 23 29 74 28 78 67 55 
55 67 78 28 74 29 23 28 54 44 33 31 64 35 51 26 41 73 68 52 
*/