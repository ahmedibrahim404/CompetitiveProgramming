#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX=21, N=12;
int n, m, k, cost[N][N];
int xs[N], ys[N];
int dp[N][1<<N];

int getBit(int mask, int idx){
    return (mask>>idx)&1;
}

int setBit(int mask, int idx){
    return (mask | (1<<idx));
}

bool done(int mask){
    return mask == (1<<k)-1;
}

int solve(int idx, int mask){

    if(done(mask)) return cost[idx][0];

    int &ret=dp[idx][mask];
    if(~ret) return ret;
    ret=2e9;
    for(int i=0;i<k;i++){
        if(i == idx) continue;
        if(getBit(mask, i)) continue;
        ret=min(ret, cost[i][idx]+solve(i, setBit(mask, i)));
    }

    return ret;

}

int main(){

    int t;
    scanf("%d",&t);

    while(t--){

        memset(cost, 0, sizeof cost);
        memset(dp, -1, sizeof dp);

        scanf("%d%d",&n,&m);
        scanf("%d%d",&xs[0], &ys[0]);
        scanf("%d",&k);
        for(int i=1;i<=k;i++){
            scanf("%d%d",&xs[i],&ys[i]);
        }
        k++;

        for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
               cost[i][j]=abs(xs[i]-xs[j]) + abs(ys[i]-ys[j]);
               cost[j][i]=cost[i][j];
            }
        }

        printf("%d\n", solve(0, 1));

    }

    return 0;
}
