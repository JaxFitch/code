#include<iostream>
#include<cstdlib>

using namespace std;

void randList(int a[], int size) {
    srand(time(0));

    for(int i = 0; i < size; i++) {
        a[i] = rand() % 101;
    }

}

void sum(int a[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += a[i];
    }

    cout << "Sum: " << sum << endl;
}

void largest(int a[], int size) {
    int largest = a[0];
    for(int i = 1; i < size; i++) {
        if(a[i] > largest) {
            largest = a[i];
        }
    }

    cout << "Largest: " << largest << endl;
}

int main() {
    int a[10];
    
    randList(a, 10);
    sum(a, 10);
    largest(a, 10);

    return 0; 
}