#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1000000+3;
const ll MOD = 1e9+7;
int n;

ll dp[N];
ll solve(int i){
    if(i == n-1) return 1;

    ll &ret=dp[i];
    if(~ret) return ret;
    ret=1;
    if(i+1 < n) ret += solve(i+1);
    if(i+2 < n) ret += solve(i+2);
    return ret;
}

int main(){

    // 1 2

    memset(dp, -1, sizeof dp);
    scanf("%d",&n);

    int ans=0;
    for(int i=2;i<n;i++){
        ans += solve(i);
    }
    ans--;

    // 1 2 3 - 2 1 3 - 3 1 2 - 3 2 1 - 1 3 2 - 2 3 1

    cout << ans*2 *4 + 2 * 2;



//
//    vector<int> v;
//    for(int i=1;i<=n;i++) v.push_back(i);
//    do {
//        bool can=1;
//        for(int i=0;i<n-1;i++) if(v[i] % v[i+1] > 2) can=0;
//        if(!can) continue;
//        for(int i=0;i<n;i++) cout << v[i] << " ";
//        cout << "\n";
//
//    } while(next_permutation(v.begin(), v.end()));
    return 0;
}
