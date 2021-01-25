#include <iostream>

using namespace std;
long long t, n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;

        if(n&1){
            cout << "YES\n";
            continue;
        }
        if(n&(n-1)) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}
