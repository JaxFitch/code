#include <iostream>

using namespace std;

char convertToLetterGrade(int grade) {
    if (grade >= 90) {
        return 'A';
    } else if (grade >= 80) {
        return 'B';
    } else if (grade >= 70) {
        return 'C';
    } else if (grade >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    int grades[10];
    int countA = 0;

    for (int i = 0; i < 10; i++) {
        cout << "Enter grade " << i + 1 << ": ";
        cin >> grades[i];

        if (convertToLetterGrade(grades[i]) == 'A') {
            countA++;
        }
    }

    cout << "Letter grades:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Grade " << i + 1 << ": " << convertToLetterGrade(grades[i]) << endl;
    }
    cout << "Number of As: " << countA << endl;

    return 0;
}