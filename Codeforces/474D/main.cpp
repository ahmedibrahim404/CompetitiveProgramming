#include <iostream>
#include <cstring>
using namespace std;
const int MAX=100000+3;
const int MOD=1e9+7;
int t, k;
int dp[MAX];

const int MB=100000;
//int solve(int idx=0){
//    if(idx > MB) return 0;
//    if(idx==MB){
//        return 1;
//    }
//    int &ret=dp[idx];
//        cout << idx << endl;
//
//    if(~ret) return ret;
//    ret=0;
//    if(MB-idx<=k) ret+=solve(idx+k)%MOD;
//    ret += solve(idx+1)%MOD;
//    return ret%MOD;
//}

int a, b;

int getidx(int idx){
    return MB-idx-1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> t >> k;
    dp[MB]=1;
    for(int i=MB-1;i>=0;i--){
        dp[i]=dp[i+1]%MOD;
        if(MB>=i+k) dp[i]+=dp[i+k]%MOD;
        dp[i]%=MOD;
    }

    for(int i=0;i<MB;i++){
        if(i)dp[ getidx(i) ] += dp[getidx(i-1)]%MOD;
        dp[getidx(i)]%=MOD;
//        cout << i << " " << dp[ getidx(i) ] << endl;
    }

    while(t--){
        cin >> a >> b;
        a--, b--;
        int ans=dp[ getidx(b) ]-( a ? dp[ getidx(a-1) ] : 0 );
        cout << (ans+MOD)%MOD << endl;

    }
    return 0;
}
