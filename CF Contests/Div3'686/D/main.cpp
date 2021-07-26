#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);

        int mx=0;ll no=-1;
        for(ll i=2;i*i<=n;i++){
            ll cnt=0;
            ll cur=n;
            while(cur%i ==0){
                cur/=i;
                cnt++;
            }
            if(cnt>mx) mx=cnt, no=i;
        }

        if(!mx) no=1;

        ll tot=1;
        vector<ll> ans;
        for(int i=0;i<mx-1;i++){
            ans.push_back(no);
            tot *= no;
        }

        if((n/(tot*no)) % no == 0 && no != 1){
            ans.push_back(no);
            tot *= no;
        }

        ans.push_back(n/tot);

        printf("%d\n", ans.size());
        for(auto i: ans) printf("%lld ", i);
        printf("\n");

    }
    return 0;
}
