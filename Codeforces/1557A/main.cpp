#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;int ns[n];
        ll tot=0;
        for(int i=0;i<n;i++) cin >> ns[i];
        sort(ns, ns+n);
        for(int i=0;i<n-1;i++) tot += 1LL*ns[i];
        cout << setprecision(20) << 1.0 * tot/(n-1) + 1.0 * ns[n-1] << "\n";
    }
    return 0;
}
