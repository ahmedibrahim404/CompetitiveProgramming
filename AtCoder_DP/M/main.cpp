#include <iostream>

using namespace std;
const int N=100+3;
const int K=100000+3;
const int MOD=1e9+7;
int n, k;
int ns[N];

int dp[N][K];
int sums[N][K];
int as[N];

int solve(int cur=0, int took=0){

    if(cur==n){
        if(took==k) return 1;
        return 0;
    }

    int &ret=dp[cur][took];
    if(~ret) return ret;
    ret=0;
    for(int i=0;i<=as[i];i++){
        if(took+i<=k) ret += solve(cur+1, took+i);
    }

    return ret;

}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&as[i]);
    for(int i=0;i<=n;i++)dp[i][0]=1;

    for(int i=1;i<=n;i++){
        sums[i][0]=dp[i-1][0];
        for(int j=1;j<=k;j++){
            sums[i][j] = sums[i][j-1]%MOD + dp[i-1][j]%MOD;
            sums[i][j] %= MOD;
        }

        for(int j=0;j<=k;j++){
            int sum=sums[i][j];
            if(j-as[i]>0) sum -= sums[i][j-as[i]-1];
            sum += MOD;
            sum %= MOD;
            dp[i][j]=sum;
        }


    }

    printf("%d\n", dp[n][k]);

    return 0;
}
