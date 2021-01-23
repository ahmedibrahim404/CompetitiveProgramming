#include<bits/stdc++.h>
using namespace std;
const int MAX=21;
const int MOD=1e9+7;
int dp[MAX][1<<MAX];
int n; bool ns[MAX][MAX];

int getBit(int mask, int idx){
    return (mask>>idx)&1;
}

int setBit1(int mask, int idx){
    return mask|(1<<idx);
}


int solve(int idx=0, int mask=0){

    if(idx==n) return 1;

    int &ret=dp[idx][mask];
    if(~ret) return ret;
    ret=0;
    for(int i=0;i<n;i++){
        if(ns[idx][i] && !getBit(mask, i)){
            ret += solve(idx+1, (mask|(1<<i)))%MOD;
            ret %= MOD;
        }
    }

    return ret%MOD;
}

int main(){
    scanf("%d",&n);
    memset(dp, -1, sizeof dp);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&ns[i][j]);
    printf("%d\n", solve()%MOD);

    return 0;
}
