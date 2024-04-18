#include<iostream>

using namespace std;

int main(){
    int a[6] = {20, 39, 77, 19, 10, 89};
    int count = 0;


    for(int i = 0; i < 6; i++) {
        if(a[i] == 10) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}