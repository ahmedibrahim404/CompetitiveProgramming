#include <iostream>

using namespace std;

int dp[100+3][4];
int n, ns[100+3];

int solve(int idx=0, int prev=0){

    if(idx==n) return 0;
    int&ret=dp[idx][prev];
    if(~ret) return ret;

    if(ns[idx]==0) return 1+solve(idx+1, 0);
    if(ns[idx]==1){
        if(prev==1) return 1+solve(idx+1, 0);
        return solve(idx+1, 1);
    }
    if(ns[idx]==2){
        if(prev==2) return 1+solve(idx+1, 0);
        return solve(idx+1, 2);
    }

    return solve(idx+1, 3-prev);

}

int main(){
    scanf("%d",&n);
    for(int i=0;i<100+3;i++) for(int j=0;j<4;j++) dp[i][j]=-1;
    for(int i=0;i<n;i++) scanf("%d",&ns[i]);
    printf("%d\n", solve(0, 0));
    return 0;
}
