#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
int n, h;
vvi dp, ns;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> h;

    dp=vvi(n+2, vi(h+2, 0));
    ns=vvi(n+2, vi(h+2, 0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=h;j++){
            cin >> ns[i][j];
        }
        dp[i][1]=ns[i][1];
    }


    for (int j = 2; j <= h; j++) {
        for (int i = 1; i <= n; i++) {
             dp[i][j] = max(max(dp[i - 1][j - 1], dp[i + 1][j - 1]), dp[i][j - 1]);
             dp[i][j] += ns[i][j];
        }
    }

     ll ans = 0;
     for (int i=1;i<=n;i++)ans = max(ans, dp[i][h]);
     printf("%lld\n", ans);
    return 0;
}
