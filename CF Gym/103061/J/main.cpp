#include<bits/stdc++.h>
using namespace std;
const int N = 1000000 + 3;

long long dp[N][3];
long long solve(int len, int lst){

    if(len < 0) return 0;
    if(!len) {
        return lst == 1;
    }

    long long &ret=dp[len][lst];
    if(~ret) return ret;
    ret = 0;

    if(lst == 0){
        ret += solve(len - 1, 2)%998244353;
        ret += solve(len - 2, 1)%998244353;
        ret %= 998244353;
    } else if(lst == 1){
        ret += solve(len - 1, 0)%998244353;
        ret += solve(len - 2, 1)%998244353;
        ret %= 998244353;
    } else {
        ret += solve(len - 2, 0)%998244353;
        ret += solve(len - 2, 2)%998244353;
        ret %= 998244353;
    }

    return ret%998244353;


}

int main(){
    memset(dp, -1, sizeof dp);
    int n;scanf("%d",&n);
    printf("%lld\n", solve(n, 0));
    return 0;
}
