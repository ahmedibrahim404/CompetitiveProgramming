#include<bits/stdc++.h>
using namespace std;
const int MAX=51;
int t, n, m;
int as[MAX], bs[MAX];
int dp[MAX][1000+5];

int solve(int idx, int w){

    if(idx==m) return 0;

    int &ret=dp[idx][w];
    if(~ret) return ret;

    ret=solve(idx+1, w);
    if(w >= as[idx]) ret=max(ret, bs[idx] + solve(idx+1, w - as[idx]));
    return ret;

}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&as[i], &bs[i]);
        }

        memset(dp, -1, sizeof dp);

        printf("Hey stupid robber, you can get %d.\n", solve(0, n));

    }
    return 0;
}
