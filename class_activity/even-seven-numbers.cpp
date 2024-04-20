#include <iostream>

using namespace std;

int main() {
    int i = 0;
    while (i < 100) {
        if (i % 2 == 0 && i % 7 == 0) {
            cout << i << endl;
        }
        i++;
    }

    return 0;
}