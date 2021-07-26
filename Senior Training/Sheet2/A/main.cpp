#include<bits/stdc++.h>
using namespace std;

int t, k, n;
const int MAX=15+5;
bool can[MAX][MAX];

int dp[11][1<<11];
bool vis[MAX];

int getBit(int num, int idx){
    return (num>>idx)&1;
}

int setBit(int num, int idx){
    return num | (1<<idx);
}

bool done(int mask){
    return mask == (1<<n)-1;
}

int solve(int u, int mask){
    if(done(mask)) return can[u][0];
    int &ret=dp[u][mask];
    if(~ret) return ret;
    ret=0;
    for(int i=0;i<n;i++){
        if(!can[u][i]) continue;
        if(getBit(mask, i)) continue;
        ret += solve(i, setBit(mask, i));
    }
    return ret;
}



int main(){

    scanf("%d",&t);
    int md=1;
    while(t--){
        scanf("%d%d",&n,&k);
        memset(can, 1, sizeof can);
        memset(dp, -1, sizeof dp);
        for(int i=0;i<n;i++) can[i][i]=0;
        for(int i=0;i<k;i++){
            int a, b;
            scanf("%d%d",&a,&b);
            a--, b--;
            can[a][b]=0;
            can[b][a]=0;
        }

        printf("Case #%d: %d\n", md++, ((solve(0, 1)%9901) * (4951))%9901 );

    }
    return 0;
}
