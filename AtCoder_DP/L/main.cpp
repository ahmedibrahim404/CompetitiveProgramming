#include<bits/stdc++.h>

using namespace std;
const int MAX=3000+3;
typedef long long ll;
int N;
ll a[MAX], dp[MAX][MAX];

ll solve(int l, int r, int t){

    if(l > r) return 0;
    ll &ret=dp[l][r];
    if(ret!=-1) return ret;

    if(t){
        ret=min(solve(l+1, r, 0)-a[l], solve(l, r-1, 0)-a[r]);
    } else {
        ret=max(solve(l+1, r, 1)+a[l], solve(l, r-1, 1)+a[r]);
    }

    return ret;

}


int main(){
    scanf("%d",&N);
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<N;i++) scanf("%lld",&a[i]);
    printf("%lld\n",solve(0, N-1, 0));
    return 0;
}
