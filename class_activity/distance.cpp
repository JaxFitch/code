#include<iostream>
#include<cmath>

using namespace std ;

int main () {
    double x, y, distance ;

    cout << "X: " ;
    cin >> x ;

    cout << "Y: " ;
    cin >> y ;

    distance = sqrt(x * x + y * y) ;
    
    cout << "The distance is: " << distance << endl ;

    return 0 ;
}