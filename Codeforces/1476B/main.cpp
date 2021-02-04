#include<bits/stdc++.h>

const long long EPS=1e-9;

    using namespace std;
typedef long long ll;
int t, n, k;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        ll ns[n];
        for(int i=0;i<n;i++) cin >> ns[i];
        ll cur=ns[0], add=0;
        for(int i=1;i<n;i++){
            if( ns[i]*100 > k*cur){

                ll st=0, en=1e14;ll ans=0;
                while(en >= st){
                    ll mid=(st+en)/2;
                    if( ns[i]*100 > k*(cur+mid)){
                        st=mid+1;
                    } else {
                        ans=mid;
                        en=mid-1;
                    }
                }

                add += ans;
                cur += ans;

            }

            cur += ns[i];
        }

        cout << add << "\n";

    }
    return 0;
}
