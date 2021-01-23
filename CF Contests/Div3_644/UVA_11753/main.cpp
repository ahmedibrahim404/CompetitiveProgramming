#include <iostream>

using namespace std;

int T, n, k;
const int MAX=10000+1;
int ns[MAX], dp[MAX][21][21];

int solve(int i, int right, int cost){

    if(cost>20) return 1e9;

    int j=n-right-1;
    if(i>=j) return 0;
    int&ret=dp[i][right][cost];
    if(~ret) return ret;
    ret=1e9;
    if(ns[i]==ns[j]) return ret=solve(i+1, right+1, cost);
    ret=min( ret, 1+solve(i, right+1, cost+1) );
    ret=min(ret, 1+solve(i+1, right, cost+1) );
    return ret;

}


int main(){
    scanf("%d",&T);
    int ts=1;
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        for(int i=0;i<n;i++) for(int j=0;j<21;j++) for(int k=0;k<21;k++) dp[i][j][k]=-1;
        int cost=solve(0, 0, 0);
        if(cost>k) printf("Case %d: Too difficult\n",ts++);
        else if(cost==0) printf("Case %d: Too easy\n", ts++);
        else printf("Case %d: %d\n", ts++, cost);
    }
    return 0;
}
