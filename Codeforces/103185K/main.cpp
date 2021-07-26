#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int K = 750 + 1, N = 10000 + 3;;
const int MOD = 1e9+7;
int k, l, n;
int ns[K][K], arr[N];

int dp[N][K];
int solve(int but, int cur){
    if(but == n-1) return 1;

    int &ret=dp[but][cur];
    if(~ret) return ret;
    ret=0;

    int st=lower_bound(ns[cur], ns[cur]+k, arr[but] - l) - ns[cur];
    int en=upper_bound(ns[cur], ns[cur]+k, arr[but] + l) - ns[cur];

    for(int i=st;i<en;i++){
        ret += solve(i, but+1)%MOD;
        ret %= MOD;
    } // st -> en


    return ret%MOD;

}

int main(){


    scanf("%d%d",&k,&l);
    memset(dp, 0, sizeof dp);

    for(int i=0;i<k;i++) for(int j=0;j<k;j++) scanf("%d",&ns[i][j]);


    scanf("%d",&n);
    for(int i=0;i<n-1;i++) scanf("%d",&arr[i]);

    for(int i=0;i<k;i++){
        dp[n-1][i]=1;
        if(i) dp[n-1][i] += dp[n-1][i-1];
    }

    for(int j=n-2;~j;j--){
        for(int i=0;i<k;i++){

            int st=lower_bound(ns[i], ns[i]+k, arr[j] - l) - ns[i];
            int en=upper_bound(ns[i], ns[i]+k, arr[j] + l) - ns[i];

            dp[j][i] += ((en-1 >= 0 ? dp[j+1][en-1] : 0) - (st-1>=0 ? dp[j+1][st-1] : 0) + MOD)%MOD;
            dp[j][i] %= MOD;

        }

        for(int i=1;i<k;i++){
            dp[j][i] += dp[j][i-1]%MOD;
            dp[j][i] %= MOD;
        }
    }

    printf("%d\n", dp[0][k-1]%MOD);

    return 0;
}
