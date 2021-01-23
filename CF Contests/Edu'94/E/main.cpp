#include<bits/stdc++.h>

using namespace std;
const int MAX=5000+2;

int dp[MAX][MAX];
int n, ns[MAX];

int solve(int idx=0, int depIdx=n){
    if(idx==n) return 0;

    int &ret=dp[idx][depIdx];
    if(~ret) return ret;


    if(ns[idx]>ns[depIdx]){
        ret=1+solve(idx+1, depIdx);
        ret=min(ret, ns[idx]-ns[depIdx]+solve(idx+1, idx));
    } else {
        ret=solve(idx+1, idx);
    }
    return ret;

}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&ns[i]);
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve());

    return 0;
}
