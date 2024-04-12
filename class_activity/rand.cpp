#include<iostream>

using namespace std;

int randInt(int min, int max){
    return rand() % (max - min + 1) + min;
}

int main(){
    for(int i = 0; i < 10; i++){
        cout << randInt(1, 100) << endl;
    }

	return 0;
}