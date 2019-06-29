#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double cnt;

int prices[] = { 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5 };

ll dp[ 11+1 ][ 30000+1 ];

ll solve(int idx, int cur){

    if(cur == 0) return 1;
    if(idx >= 11 || cur < 0) return 0;

    ll &ret = dp[idx][cur];
    if(ret != -1) return ret;

    ret=solve(idx, cur - prices[idx])+solve(idx+1, cur);
    return ret;
}


int main(){
        for(int i=0;i<11+1;i++) for(int j=0;j<30000+1;j++) dp[i][j]=-1;

    while(scanf("%lf", &cnt) && cnt){
        printf("%.2lf                 %lld\n", cnt, solve(0, cnt*100+0.5));
    }

    return 0;
}
