#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, di[18+3], tk[18+3][18+3];
ll dp[18+2][1<<18];
ll solve(int prev=0, bitset<19> bt=0){

    if(bt.count() == m) return 0;


    ll &ret=dp[prev][bt.to_ullong()];
    if(ret!=-1) return ret;

    ret=0;
    for(int i=1;i<=n;i++){
        int idx=i-1;
        if(bt[idx]==0){
            bt[idx]=1;
            ret=max(ret, solve(i, bt)+di[i]+tk[i][prev]);
            bt[idx]=0;
        }
    }

    return ret;

}
int a, b, c;
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",&di[i]);
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) tk[i][j]=0;
    for(int i=0;i<=n;i++) for(int j=0;j<=1<<18;j++) dp[i][j]=-1;
    for(int i=0;i<k;i++){
        scanf("%d %d %d",&a,&b,&c);
        tk[a][b]=c;
    }
    printf("%lld", solve());
    return 0;
}
