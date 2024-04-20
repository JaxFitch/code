#include <iostream>

using namespace std;

int main() {
    int a[6] = {20, 39, 77, 19, 10, 89};

    for(int i = 0; i < 6; i++) {
        if(a[i] == 10) {
            cout << "The number 10 is in the array." << endl;
        } else {
            cout << "The number 10 is not in the array." << endl;
        }
    }

    return 0;
}