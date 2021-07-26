#include<bits/stdc++.h>
using namespace std;

int T, n, k, ns[10000+3];
int dp[10000+3][100+3];

int solve(int cur=0, int sum=0){

    if(cur == n) return ((sum+k)%k)==0 ? 1 : 0;

    int &ret=dp[cur][sum];
    if(ret != -1) return ret;

    ret=solve(cur+1, (sum+ns[cur]+k)%k) | solve(cur+1, (sum-ns[cur]+k)%k);

    return ret;

}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<n;i++){
            scanf("%d",&ns[i]);
            ns[i]=(k+(ns[i]%k))%k;
        }
        if(solve()==1) printf("Divisible\n");
        else printf("Not divisible\n");
    }
    return 0;
}
