#include <iostream>

using namespace std;
int t, n, k;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        int total=(n/k)*k;
        int rem=n-total;
        cout << total + min(k/2, rem) << endl;
    }
    return 0;
}
