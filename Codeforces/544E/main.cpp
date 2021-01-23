#include<bits/stdc++.h>
using namespace std;
const int MAX=5000+1;
int dp[MAX][MAX];
int ns[MAX];
int n, k;

int main(){


    scanf("%d%d",&n,&k);

    for(int i=0;i<n;i++){
        scanf("%d",&ns[i]);
    }
    sort(ns, ns+n);
    for(int i=n-2;i>=0;i--){
        ns[i+1]=ns[i+1]-ns[i];
    }

    int tot, cum;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=k;j++){
            if(!ns[i]) {dp[i][j]=dp[i+1][j];continue;}
            dp[i][j]=dp[i+1][j];
            tot=1, cum=0;
            for(int a=i+1;a<n&&cum+ns[a]<=5;a++) cum += ns[a], tot++;
            if(j)dp[i][j]=max(dp[i][j], dp[i+tot][j-1]+tot);
        }
    }

    printf("%d\n", dp[0][k]);

    return 0;
}
