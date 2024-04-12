#include <iostream>

using namespace std;

int main() {
    int num = 1000;
    while (num < 10000) {
        int sum = 0;
        int temp = num;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        if (num % 2 != 0 && sum == 27) {
            cout << num << endl;
            break;
        }
        num++;
    }

    return 0;
}