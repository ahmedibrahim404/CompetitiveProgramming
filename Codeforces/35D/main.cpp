#include <iostream>

using namespace std;

int n,x,ns[100+3];
int dp[100+3][10000+3];
int solve(int idx, int rem){

    if(idx==n) return 0;

    int &ret=dp[idx][rem];
    if(~ret) return ret;

    ret=solve(idx+1, rem);

    if(rem >= (n-idx)*ns[idx] ) ret=max(ret, 1+solve(idx+1, rem-(n-idx)*ns[idx]));

    return ret;

}


int main(){
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++) scanf("%d",&ns[i]);
    for(int i=0;i<100+3;i++) for(int j=0;j<10000+3;j++) dp[i][j]=-1;
    printf("%d\n", solve(0, x));
    return 0;
}
