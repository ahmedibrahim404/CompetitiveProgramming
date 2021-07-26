#include <iostream>

using namespace std;

int t, a, b;
int main(){
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(b==a) {
            cout << "0\n";
        } else if(b > a){
            cout << 1 + ((a&1) == (b&1)) << "\n";
        } else if(a > b){
            cout << 1 + ((a&1) != (b&1)) << "\n";
        }
    }
    return 0;
}
