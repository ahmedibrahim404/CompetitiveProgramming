#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
const int MAX=200+3;
int n, k, x;
ll ns[MAX];
ll dp[MAX][MAX][MAX];
ll solve(int idx, int rem, int pre){

    if(pre>k) return -1e18;

    if(idx==n){
        if(rem) return -1e18;
        return 0;
    }

    ll &ret=dp[idx][rem][pre];
    if(~ret) return ret;
    ret=solve(idx+1, rem, pre+1);
    if(rem) ret=max(ret, ns[idx]+solve(idx+1, rem-1, 1));

    return ret;
}

int main(){

    cin >> n >> k >> x;
    for(int i=0;i<n;i++) cin >> ns[i];
    memset(dp, -1 , sizeof(dp));
    ll cost=solve(0, x, 1);
    if(cost < 0)
    cout << "-1";
    else cout << cost;

    return 0;
}
