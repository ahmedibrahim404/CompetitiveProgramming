#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int T, N, M, cur, price[1000+9], weight[1000+9];
ll dp[1000+9][1000+9];

ll solve(int idx, int we){
    if(idx == N) return 0;

    ll &ret=dp[ idx ][ we ];
    if(ret != -1) return ret;

    if(we - weight[idx] >= 0) ret = price[idx]+solve(idx+1, we-weight[idx]);
    ret = max( ret, solve(idx+1, we) );

    return ret;
}

int main(){
    cin >> T;

    while(T--){
        cin >> N;
        for(int i=0;i<N;i++){
            cin >> price[i] >> weight[i];
        }

        cin >> M;
        ll ans=0;

        while(M--){
			memset(dp, -1, sizeof dp);
            cin >> cur;
            ans += solve(0, cur);
        }

        cout << ans << endl;

    }

    return 0;
}
