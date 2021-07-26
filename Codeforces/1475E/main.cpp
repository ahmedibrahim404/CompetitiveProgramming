#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int t;ll n, k;
ll nCr[1000+5][1000+5];

int main(){


    for(int i=0;i<=1000+2;i++){
        nCr[i][0]=1;
        nCr[i][1]=i;
    }



    for(int i=1;i<=1000+2;i++){
        for(int j=2;j<=i;j++){
            nCr[i][j] = nCr[i-1][j]%MOD + nCr[i-1][j-1]%MOD;
            nCr[i][j] %= MOD;
        }
    }

    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        ll ns[n+3];
        for(int i=0;i<n;i++) scanf("%lld",&ns[i]);
        sort(ns, ns+n, greater<long long>());
        ll sc=0;
        ll lst=-1, cnt=0;
        for(int i=0;i<k;i++){
            sc += ns[i];
            if(lst != ns[i]){
                lst=ns[i];
                cnt=1;
            } else cnt++;
        }
        ll tot=cnt;
        for(int i=k;i<n;i++){
            if(ns[i]==lst) tot++;
            else break;
        }

        cout << nCr[tot][cnt]%MOD << "\n";



    }
    return 0;
}
