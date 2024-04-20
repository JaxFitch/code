#include<iostream>
#include<cmath>

using namespace std;

int main() {
    string s;
    int c = 0;
    double avWeight = 0.0;
    double grades[1000] = {};
    double weight[1000] = {};
    double average = 0.0;

    while(s != "n") {
        cout << "Enter grade: %";
        cin >> grades[c];
        cout << "Enter weight: %";
        cin >> weight[c];
        cout << "Do want to enter another grade? (y/n): ";
        cin >> s;
        ++c;
    }
    cout << endl;

    for(int i = 0; i < c; ++i) {
        average += grades[i] * weight[i];
        avWeight += weight[i];
    }

    average /= avWeight;

    cout << "Average grade: " << average << endl;

    return 0;
}