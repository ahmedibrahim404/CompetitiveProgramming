#include<bits/stdc++.h>

using namespace std;

int n, m, mn[100+9], fav[100+9], dp[100+3][10000+9];

int solve(int cur=0, int took=0){

    if(took > m && m < 1800)
        return -1000;
    if(took > m + 200)
        return -1000;

    if(cur == n) {
        if(took > m && took <= 2000)
            return -1000;
        return 0;
    }

    int &ret=dp[cur][took];
    if(ret != -1) return ret;

    ret=max( solve(cur+1, took), solve(cur+1, took+mn[cur])+fav[cur] );

    return ret;

}

int main(){
    while(scanf("%d %d",&m,&n)==2){
        for(int i=0;i<n;i++)
            scanf("%d %d",&mn[i],&fav[i]);
        memset(dp, -1, sizeof(dp));
        int ans=solve();
        printf("%d\n", ans);
    }
    return 0;
}
