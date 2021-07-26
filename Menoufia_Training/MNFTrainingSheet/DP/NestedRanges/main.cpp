#include<bits/stdc++.h>
using namespace std;

int dp[51][51], w[51];
int solve(int l, int r){
        if(l + 1 == r) return 0;
        int& cache = dp[l][r];
        if(cache != -1) return cache;
        int ret = 0;
        for(int i = l + 1; i <= r - 1; i++) ret = max(ret, go(l, i) + go(i, r));
        return cache = ret + w[l] * w[r];
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&w[i]);
    memset(dp, sizeof(dp), -1);
    printf("%d\n", solve(0, n-1));
    return 0;
}
