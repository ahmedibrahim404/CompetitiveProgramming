#include<bits/stdc++.h>
using namespace std ;

const int N = 5e3+5 ,mod = 1e9+7 ;

int n ,k ,q ,a[N] ,ans ;
int mem[N][N] ,ways[N] ;
int solve(int i,int rem){
    if(i<1 || i>n) return 0;
    if(!rem) return 1;
    int&ret = mem[i][rem];
    if(~ret) return ret ;
    return ret = (solve(i-1,rem-1) + solve(i+1,rem-1))%mod ;
}
int main(){
    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=n;++i) scanf("%d",a+i);
    memset(mem,-1,sizeof mem);
    for(int i=1;i<=n;++i){
        for(int j=0;j<=k;++j)  ways[i] = (ways[i] + 1ll*solve(i,j)*solve(i,k-j)%mod)%mod;
        ans = (ans + 1ll*ways[i]*a[i]%mod)%mod ;
    }
    while(q--){
        int j ,val ;
        scanf("%d%d",&j,&val);
        int nw = (1ll*ways[j]*(val-a[j])%mod+mod)%mod ;
        a[j] = val ;
        ans = (ans + nw)%mod ;
        printf("%d\n",ans);
    }
    return 0;
}
