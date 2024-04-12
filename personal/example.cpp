#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory>
#include <stdexcept>

using namespace std;

// Custom exception class
class MathError : public runtime_error {
public:
    MathError(const string& message) : runtime_error(message) {}
};

// Function templates
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Base class
class Shape {
public:
    virtual void draw() const = 0; // Pure virtual function for polymorphism
    virtual ~Shape() {}
};

// Derived class
class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a circle." << endl;
    }
};

// File I/O functions
void writeToFile(const string& message, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << message;
        file.close();
    } else {
        throw runtime_error("Unable to open file");
    }
}

string readFromFile(const string& filename) {
    ifstream file(filename);
    string content;
    if (file.is_open()) {
        getline(file, content);
        file.close();
    } else {
        throw runtime_error("Unable to open file");
    }
    return content;
}

int main() {
    // Template function usage
    cout << "Adding integers: " << add(5, 3) << endl;
    cout << "Adding doubles: " << add(2.5, 3.5) << endl;

    // Polymorphism with smart pointer
    unique_ptr<Shape> shape = make_unique<Circle>();
    shape->draw();

    // STL Algorithms and Lambda Expressions
    vector<int> numbers = {1, 2, 3, 4, 5};
    sort(numbers.begin(), numbers.end(), [](int a, int b) { return a > b; });
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Exception Handling
    try {
        int result = add(-10, 20);
        if (result < 0) {
            throw MathError("Result cannot be negative");
        }
        cout << "Result: " << result << endl;
    } catch (const MathError& e) {
        cerr << "Caught MathError: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    }

    // File I/O
    const string filename = "test.txt";
    writeToFile("Hello, C++!", filename);
    cout << "File content: " << readFromFile(filename) << endl;

    return 0;
}
