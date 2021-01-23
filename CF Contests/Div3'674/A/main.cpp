#include <iostream>

using namespace std;
int t, n, x;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> x;
        if(n<=2){
            cout << "1\n";
            continue;
        }
        n-=2;
        cout << ((n+x-1)/x)+1 << "\n";
    }
    return 0;
}
