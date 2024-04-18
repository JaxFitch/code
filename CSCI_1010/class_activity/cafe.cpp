#include<iostream>
#include<cmath>

using namespace std ;

int main () {
    double total , cheeseP = 4.99 , espresP = 5.99, chocoP = 3.99;
    int age , cheeseQ , espresQ , chocoQ ;

    cout << "Enter your  age: " ;
    cin >> age ;
    cout << "How many cheeseburgers ($" << cheeseP << "):" ;
    cin >> cheeseQ ;
    cout << "How many cheeseburgers ($" << espresP << "):" ;
    cin >> espresQ ;
    cout << "How many cheeseburgers ($" << chocoP << "):" ;
    cin >> chocoQ ;

    total = (cheeseP * cheeseQ) + (espresP * espresQ) + (chocoP * chocoQ) ;
    
    if (total > 20 && age < 10 || age >= 65) {
        cout << "Your total with the a %35 discount is: $" << total * .65 ;
    }
    else if (total > 20) {
        cout << "Your total with the a %20 discount is: $" << total * .80 ;
    }
    else if (age < 10 || age >= 65) {
        cout << "Your total with the a %15 discount is: $" << total * .85 ;
    }
    else {
        cout << "Your total is: $" << total ;
    }

    return 0 ;
}