#include <iostream>

using namespace std;

long long result = 0;
long long modulo = 10000000000;



int main(){
    for (int i = 1; i <= 1000; i++) {
        long long temp = i;
        for (int j = 1; j < i; j++) {
            temp *= i;
            temp %= modulo;
        }

        result += temp;
        result %= modulo;
    }

    cout << (result) << endl;

    return 0;
}
