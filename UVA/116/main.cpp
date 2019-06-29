#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
ll ns[11][101];
ll dp[11][101];

ll solve(int x, int y){

    if( x >= n || y >= m ) return 0;
    if(y == m-1) return 0;
//    cout << x << " " << y << endl;

    ll &ret=dp[x][y];
    if(ret != -1) return ret;

    int nx=x+1, ny=y+1;
    if(nx >= n) nx=0;
    ll a1=ns[nx][ny]+solve(nx, ny);

    nx=x;
    ll a2=ns[nx][ny]+solve(nx, ny);

    nx=x-1;
    if(nx < 0) nx=n-1;
    ll a3=ns[nx][ny]+solve(nx, ny);



    return ret;

}

int main(){
    while(scanf("%d %d", &n, &m) == 2){

        ll mi=2e9;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            scanf("%d", &ns[i][j]);
            if(j == 0) mi=min(mi, ns[i][j]);
        }
//        cout << "HEREX" << endl;

        ll ans=2e17;
        for(int i=0;i<n;i++){
            if(ns[i][0] == mi){
                memset(dp, -1, sizeof(dp));
                ans=min(ans, ns[i][0]+solve(i, 0));
//                cout << i << " " << ans << endl;
            }
        }

        printf("%lld\n", ans);



    }
    return 0;
}
