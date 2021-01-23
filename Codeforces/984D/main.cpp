#include <iostream>
using namespace std;
const int MAX=5000+3;
int n, q, l, r, a[MAX];
int ns[100000000][4];
int dp[MAX][MAX];
int main(){

    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        cin >>  a[i];
        dp[i][i] = a[i];
    }
    for (int sz = 1; sz < n; sz++) {
        for (int i = 0; i < n-sz; i++) {
            dp[i][i+sz] = (dp[i][i+sz-1]^dp[i+1][i+sz]);
        }
    }


    for(int len=1;len<n;len++){
        for(int i=n-len;i>=0;i--){
            int j=i+len;
            dp[i][j]=max(dp[i][j], dp[i][j-1]);
            dp[i][j]=max(dp[i][j], dp[i+1][j]);
        }
    }




    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&l,&r);
        r--, l--;
        printf("%d\n", dp[l][r]);
    }

    return 0;
}
