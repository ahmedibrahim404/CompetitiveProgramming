#include <iostream>
#include<cstring>
using namespace std;

int n, k;
int as[100+1], bs[100+1];
int dp[100][200000+9][2];

int solve(int idx, int sum, bool took){

    if(idx==n){
        if(sum||!took) return -1e9;
        return 0;
    }


    int&ret=dp[idx][sum+100001][took];
    if(~ret)return ret;


    ret=solve(idx+1, sum, took);
    int newsum;
    // 10*100*100
    newsum=sum+as[idx]-k*bs[idx];
    ret=max(ret, as[idx]+solve(idx+1, newsum, 1));

    return ret;
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)scanf("%d",&as[i]);
    for(int i=0;i<n;i++)scanf("%d",&bs[i]);
    for(int i=0;i<100;i++) for(int j=0;j<200000+9;j++) for(int k=0;k<2;k++) dp[i][j][k]=-1;

    int ans=solve(0,0,0);
    printf("%d\n", ans<0?-1:ans);


    return 0;
}
