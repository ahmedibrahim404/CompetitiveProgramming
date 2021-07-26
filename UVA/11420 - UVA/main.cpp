#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX=65+2;
int n, s;
ll dp[MAX][MAX][2];

ll solve(int idx, int cnt, bool pre){

    if(idx==n) return cnt==s;
    ll &ret=dp[idx][cnt][pre];
    if(~ret) return ret;
    ret = 0LL;
    ret += solve(idx+1, cnt+pre, 1);
    ret += solve(idx+1, cnt, 0);
    return ret;

}

int main(){
    while(cin >> n >> s && n > 0){
        memset(dp, -1, sizeof dp);
        cout << solve(0, 0, 1) << endl;
    }
    return 0;
}
