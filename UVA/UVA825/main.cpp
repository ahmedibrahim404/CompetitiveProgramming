#include<bits/stdc++.h>
using namespace std;
typedef vector<bool> vp;
typedef long long ll;
typedef vector<ll> vl;
int t, n, m, a, b;
string str;
vector<vp> ns;
vector<vl> dp;
ll solve(int x, int y){

    if(x==n-1&&y==m-1) {return 1;}
    if(x==n||y==m) return 0;
    if(ns[x][y]) return 0;

    ll &ret=dp[x][y];
    if(ret!=-1) return ret;

    ret=solve(x+1, y)+solve(x, y+1);

    return ret;

}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        ns=vector<vp>(n+1, vp(m+1, 0));
        dp=vector<vl>(n+1, vl(m+1, 0));

        for(int i=0;i<=n;i++){
            getline(cin, str);
            stringstream s(str);
            s>>a;
            while(s>>b){
                ns[a-1][b-1]=1;
            }
        }
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!i&&!j) continue;
                if(ns[i][j]) continue;
                if(j)dp[i][j]+=dp[i][j-1];
                if(i)dp[i][j]+=dp[i-1][j];
            }
        }

        printf("%lld\n", dp[n-1][m-1]);
        if(t) printf("\n");
    }
    return 0;
}
