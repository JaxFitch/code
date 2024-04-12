#include<iostream>
#include<cstdlib>

using namespace std;

double average(int a, int b, int c) {
    return (a + b + c) / 3.0;
}

int main() {
    double a[15];
    double min = -1;

    for(int i = 0; i < 15; i++) {
        a[i] = rand() % 101;
    }

    for(int i = 0; i < 15; i++) {
        if(a[i] > min) {
            min = a[i];
        }
    }

    cout << "The largest number is: " << min << endl;

    return 0;
}