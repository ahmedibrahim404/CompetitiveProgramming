#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=200000+3;
int n; ll ns[MAX];
ll dp[MAX];

int main(){
    scanf("%d",&n);
    ll took=1, ans=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&ns[i]);
    }
    sort(ns, ns+n, greater<int>());

    for(int i=0;i<n;i++){
        if(ns[i] > took) ans += ns[i]-took, took++;
        else break;

    }

    printf("%lld\n", ans);

    return 0;
}
