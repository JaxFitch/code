#include <iostream>

using namespace std;

int main() {
    int a = 0, b = 0, c = 0, d = 0, f = 0, n = 0;
    int grades[100];

    while(true) {
        cout << "Enter a grade (-1 to EXIT): ";
        cin >> grades[n];
        if(grades[n] < 0) {
            break;
        }
        n++;
    }

    for(int i = 0; i < n; i++) {
        if(grades[i] >= 90) {
            a++;
        } else if(grades[i] >= 80) {
            b++;
        } else if(grades[i] >= 70) {
            c++;
        } else if(grades[i] >= 60) {
            d++;
        } else {
            f++;
        }
    }

    cout << "A: " << a << endl;
    cout << "B: " << b << endl;
    cout << "C: " << c << endl;
    cout << "D: " << d << endl;
    cout << "F: " << f << endl;

    return 0;
}