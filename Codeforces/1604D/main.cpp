#include <iostream>

using namespace std;

int main(){
    int t;
    long long a, b; cin >> t;
    while(t--){
        cin >> a >> b;
        if (a > b) cout << a+b << endl;
        else if (b%a==0) cout << a << endl;
        else cout << b-(b%a)/2 << endl;
    }
    return 0;
}
