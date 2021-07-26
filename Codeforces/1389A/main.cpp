#include <iostream>

using namespace std;
int t, a, b;
int main(){
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(2*a <=b) cout << a << " " << 2 * a << "\n";
        else cout << "-1 -1\n";
    }
    return 0;
}
