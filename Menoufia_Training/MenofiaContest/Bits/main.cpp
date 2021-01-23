#include <iostream>

using namespace std;

void printNumber(int n){
    if(n == 0) return;
    printNumber(n>>1);
    cout << (n&1);
}

int main(){

    printNumber(16);

    return 0;

}
