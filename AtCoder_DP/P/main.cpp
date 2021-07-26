#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int MAX=100000+3;
const ll MOD=1e9+7;
int n, a, b;
vvi ns;
ll dp[MAX][2];

ll solve(int idx=0, bool pre=0, int pt=-1){
    ll &ret=dp[idx][pre];
    if(~ret) return ret;
    ret=1;

    for(int i=0;i<ns[idx].size();i++){
        int to=ns[idx][i];
        if(to==pt) continue;
        if(pre==0){
            ret *= solve(to, 0, idx)%MOD+solve(to, 1, idx)%MOD;
        } else {
            ret *= solve(to, 0, idx)%MOD;
        }
        ret %= MOD;
    }

    return ret;
}

int main(){
    scanf("%d",&n);
    memset(dp, -1, sizeof dp);
    ns=vvi(n);
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        a--, b--;
        ns[a].push_back(b);
        ns[b].push_back(a);
    }

    printf("%lld\n", (solve(0, 0, -1)%MOD + solve(0, 1, -1)%MOD)%MOD);

    return 0;
}
