#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){

    int t;
    cin >> t;
    while(t--){
        int n;ll k, xs[200000+3];

        cin >> n >> k;
        ll g=0;
        for(int i=0;i<n;i++){
            cin >> xs[i];
        }
        sort(xs, xs+n);
        for(int i=1;i<n;i++){
            g=__gcd(g, xs[i]-xs[0]);
        }

        if((k-xs[0])%g) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
