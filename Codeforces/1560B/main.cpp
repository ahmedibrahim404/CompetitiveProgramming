#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c;cin >> a >> b >> c;
        if(a < b) swap(a, b);
        int sub = (a - b);
        if(a > 2*sub || b > 2*sub || c > 2*sub) {
            cout << "-1\n";
            continue;
        }
        if(c + sub <= 2 * sub) cout << c + sub << endl;
        else if(c - sub > 0 && c - sub <= 2 * sub) cout << c - sub << endl;
        else cout << "-1\n";
    }
    return 0;
}
