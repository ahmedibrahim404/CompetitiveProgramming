#include <iostream>

using namespace std;

int t, n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;

        if(n == 1){
            cout << "a\n";
            continue;
        }

        string ans = "";
        for(int i=0;i<n/2;i++) ans += 'a';

        int k=n/2-1;
        n-=n/2;
        n-=k;

        if(n){
            if(n&1) ans += 'b';
            else ans += "bc";
        }

        for(int i=0;i<k;i++) ans += 'a';

        cout << ans << "\n";

    }
    return 0;
}
