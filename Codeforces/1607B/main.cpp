#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a, b;
        cin >> a >> b;
        if(!b) {
            cout << a << endl;
            continue;
        }
        b--;
        long long ans = -1 + b/4 * -4;
        long long mb = b%4;

        for(long long x=b-mb+2;x<=b+1;x++){
            if(ans%2 == 0) ans -= x;
            else ans += x;
        }

        cout << a + (a%2 == 0 ? ans : -ans) << endl;
    }
    return 0;
}
