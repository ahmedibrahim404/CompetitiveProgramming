#include<bits/stdc++.h>
using namespace std;

unsigned int MAX=100000+9;
int N, dp[100000][3], ns[100000][3];
int solve(int cur=0, int pre=0){
    if(cur == N) return 0;

    int &ret=dp[cur][pre];
    if(ret!=-1) return ret;

    ret=0;
    for(int i=0;i<3;i++){
        if(i == pre && cur != 0) continue;
        ret=max(ret, solve(cur+1, i)+ns[cur][i]);
    }

    return ret;
}

int main(){
    scanf("%d",&N);
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<N;i++) for(int j=0;j<3;j++) scanf("%d",&ns[i][j]);
    printf("%d", solve());
    return 0;
}
