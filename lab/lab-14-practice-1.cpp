/*
This program will use a function to count how many uppercase letters are in 
an array of characters.
*/

#include<iostream>

using namespace std;

int countUppercase(char arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 'A' && arr[i] <= 'Z') {
            count++;
        }
    }
    return count;
}

int main() {
    char arr[] = {'a', 'B', 'C', 'd', 'E', 'f', 'G', 'h', 'I', 'j'};
    int size = 10;
    cout << "Number of uppercase letters: " << countUppercase(arr, size) << endl;
}

/*
The output of this program is:

Number of uppercase letters: 5
*/