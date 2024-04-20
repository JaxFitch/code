#include<iostream>
#include<cstdlib>

using namespace std;

int main() {
    const int MAX = 100;
    int arr[MAX], used = 0;

    for(int i = 0; i < 10; i++) {
        arr[i] = rand() % 101;
        used++;
    }

    

    return 0; 
}