#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
ll k;
ll ns[200000+9];
map<ll, int> mp;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%lld",&n,&k);
        int mx=0;
        ll mno=0;
        for(int i=0;i<n;i++){
            scanf("%lld",&ns[i]);
            if(ns[i]%k)ns[i]=k-ns[i]%k;
            else ns[i]=0;
            mp[ ns[i] ]++;
            if(mp[ns[i]]>=mx&&ns[i]) {
                if(mp[ ns[i] ]==mx) mno=max(mno, ns[i]);
                else mx=mp[ns[i]], mno=ns[i];
            }
        }


        if(mno==0)printf("0\n");
        else printf("%lld\n", k*(1LL*mx-1)+mno+1);
        mp.clear();
    }
    return 0;
}
