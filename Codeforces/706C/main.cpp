#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+3;
typedef long long ll;
int n, costs[MAX];
ll dp[MAX][2];
string sts[MAX][2];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<=n;i++) for(int j=0;j<2;j++) dp[i][j]=-1;
    for(int i=0;i<n;i++) cin >> costs[i];
    for(int i=0;i<n;i++) {
        cin >> sts[i][0];
        sts[i][1]=sts[i][0];
        reverse(sts[i][1].begin(), sts[i][1].end());
    }

    dp[0][0]=0, dp[0][1]=costs[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<2;j++){
            dp[i][j]=1e18;
            if(sts[i][j] >= sts[i-1][0]) dp[i][j]=min(dp[i][j], dp[i-1][0] + costs[i]*j);
            if(sts[i][j] >= sts[i-1][1]) dp[i][j]=min(dp[i][j], dp[i-1][1] + costs[i]*j);
        }
    }

    ll ans=min(dp[n-1][0], dp[n-1][1]);
    if(ans==1e18) cout << "-1" << endl;
    else cout << ans << endl;

    return 0;
}
