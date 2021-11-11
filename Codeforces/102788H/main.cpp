#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){

    ll n, k;
    cin >> n >> k;

    ll st=2, en=n-1;

    ll ans=0;

    while(en >= st){
        ll mid=(st+en)/2LL;
        vector<ll> v((int)n+1, 0);
        v[1] = 1;
        for(ll i=1;i<=n;i++){
            if(i+1 < v.size())v[(int)i+1] += v[i];
            if(i*7 < v.size())v[(int)i*7] += v[i];
            if(i+mid < v.size())v[(int)i+mid] += v[i];
        }


        if(v[(int) n] > k){
            st=mid+1;
        } else {
            if(v[(int) n] == k) ans=mid;
            en=mid-1;
        }

    }

    cout << ans << endl;

    return 0;
}
