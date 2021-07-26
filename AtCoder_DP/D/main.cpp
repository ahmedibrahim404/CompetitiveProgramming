#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
int N, W;
vvi dp;
vi w, v;

ll solve(int cur=0, ll rest=W){

    ll &ret=dp[cur][rest];
    if(ret != -1) return ret;

    ret=0;
    if(rest >= w[cur]) ret=v[cur]+solve(cur+1, rest-w[cur]);
    ret=max(ret, solve(cur+1, rest));

    return ret;

}

int main(){
    scanf("%d %d",&N, &W);
    dp=vvi(N+2, vi(W+2));
    for(int i=0;i<=N;i++) for(int j=0;j<=W;j++) dp[i][j]=-1;
    w=vi(N), v=vi(N);
    for(int i=0;i<N;i++) scanf("%lld %lld",&w[i], &v[i]);


//    for (int i = 1; i <= N; i++) {
//        for (int j = 0; j <= W; j++) {
//            int weight = w[i - 1];
//            if(weight<=j){
//                dp[i][j] = max(v[i - 1] + dp[i - 1][j - weight],dp[i - 1][j]);
//            }else{
//                dp[i][j]=dp[i-1][j];
//            }
//        }
//    }

//    printf("%lld", dp[N][W]);
    printf("%lld", solve());

    return 0;
}
