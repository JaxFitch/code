#include <iostream>

using namespace std;

int main() {
        int primes();

        return 0;
}

int primes() {
    bool isPrime;
    for(int i = 3; i <= 100; i++) {
     isPrime = true;
        for (int n = 2; n < i; n++) {
            if (i % n == 0) {
             isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << i << " ";
        }
    }

    
    return 0;   
}