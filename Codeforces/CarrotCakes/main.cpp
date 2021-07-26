#include <iostream>
#include <math.h>

using namespace std;

int n, t, k, d;
int main(){

    cin >> n >> t >> k >> d;

    int c1 = ceil((double) n/k);
    double c2 = d/t;


    if(c1 - c2 > 1){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
