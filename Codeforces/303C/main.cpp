#include <iostream>

using namespace std;
typedef long long ll;
const int MAX=1e5+3;
int n;
ll xs[MAX], hs[MAX];
int dp[MAX][3];

int solve(int idx, int prev){

    if(idx==n-1) return 0;
    int&ret=dp[idx][prev];
    if(~ret) return ret;
    ll st=xs[idx-1];
    ll en=(prev==1?xs[idx-1]+hs[idx-1]:xs[idx-1]);
    if((xs[idx]-hs[idx])>en) return ret= 1+solve(idx+1, 0);
    if( xs[idx]+hs[idx]<xs[idx+1] ) ret=1+solve(idx+1, 1);
    ret=max(ret, solve(idx+1, 2));

    return ret;

}


int main(){

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&xs[i],&hs[i]);
        for(int j=0;j<3;j++) dp[i][j]=-1;
    }

    if(n==1||n==2){
        printf("%d\n", n);
        return 0;
    }


    printf("%d\n",solve(1, 0)+2);

    return 0;
}
