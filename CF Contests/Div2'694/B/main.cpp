#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t, n;
ll x;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> x;
        ll ns[n], ans=0;
        ll lst=2e18;
        int st=-1;
        for(int i=0;i<n;i++){
            cin >> ns[i];
            ll cur=ns[i];
            ll lvl=1;
            while(cur%x==0){
                lvl++;
                cur /= x;
            }
            if(lvl < lst) lst=lvl, st=i;
        }

        for(int i=0;i<n;i++){
            ans += (ns[i] * lst);
        }

        for(int i=0;i<st;i++){
            ans += ns[i];
        }

        cout << ans << "\n";
    }
    return 0;
}
