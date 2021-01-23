#include <iostream>

using namespace std;
const int MAX=200000+1;
int dp[MAX][2];
int t, n, ns[MAX];

int solve(int idx=0, int turn=0){

    if(idx>=n) return 0;
    int &ret=dp[idx][turn];
    if(~ret) return ret;
    ret=1e9;

    if(turn){
        if(idx+2<=n) ret=solve(idx+2, 0);
        return ret=min(ret, solve(idx+1, 0));
    }
    if(idx+2<=n) ret=min(ret, solve(idx+2, 1) + ns[idx] + ns[idx+1]);
    ret=min(ret, solve(idx+1, 1) + ns[idx]);

    return ret;

}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) for(int j=0;j<2;j++) dp[i][j]=-1;
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        printf("%d\n", solve());
    }
    return 0;
}
