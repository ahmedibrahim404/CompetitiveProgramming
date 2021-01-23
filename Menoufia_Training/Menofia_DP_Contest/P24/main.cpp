#include <iostream>

using namespace std;

int n, m;
double ns[21][21];
double dp[21][21];
double OO = 1e9*1.00;
double solve(int cur, int bank){

    if(cur == m && bank == n) return 0;

    double &ret=dp[cur][bank];
    if(ret!=0) return ret;



}

int main(){
    while(scanf("%d %d",&n,&m)==1 && n && m){
        for(int i=0;i<21;i++) for(int j=0;j<21;j++) dp[i][j]=0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%lf",&ns[i][j]);
        solve(0, 0);
    }

    return 0;
}
