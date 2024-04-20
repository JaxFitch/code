#include <iostream>

using namespace std;

int calculateArea(int height, int width) {
    return height * width;
}

int main() {
    int height1, width1, height2, width2;

    cout << "Enter the height of the first rectangle: ";
    cin >> height1;
    cout << "Enter the width of the first rectangle: ";
    cin >> width1;

    cout << "Enter the height of the second rectangle: ";
    cin >> height2;
    cout << "Enter the width of the second rectangle: ";
    cin >> width2;

    int area1 = calculateArea(height1, width1);
    int area2 = calculateArea(height2, width2);

    int totalArea = area1 + area2;
    cout << "The total area is: " << totalArea << endl;

    return 0;
}