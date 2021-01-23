#include <iostream>

using namespace std;

int t, n, ns[100+3], dp[100+3][50000+3];

int solve(int idx, int rem){

    if(idx==n) return rem;

    int&ret=dp[idx][rem];
    if(~ret)return ret;

    ret=solve(idx+1, rem+ns[idx]);
    ret=min(ret, solve(idx+1, abs(rem-ns[idx])));

    return ret;

}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<100+3;i++) for(int j=0;j<50000+3;j++) dp[i][j]=-1;
        for(int i=0;i<n;i++){
            scanf("%d",&ns[i]);
        }

        printf("%d\n", solve(0, 0));

    }
    return 0;
}
