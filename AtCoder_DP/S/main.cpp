#include <iostream>
#include <cstring>
using namespace std;
const int MAX=10000+3;
const int MOD=1e9+7;
int dp[MAX][100][2];
int n, d;
string k;
int solve(int idx=0, int mod=0, bool is=0){

    if(idx==n)
        return (mod==0);

    int &ret=dp[idx][mod][is];
    if(~ret) return ret;
    ret=0;
    int en=k[idx]-'0';
    if(is) en=9;
    for(int i=0;i<=en;i++){
        ret += solve(idx+1, (mod+i)%d, is||(i!=en));
        ret %= MOD;
    }

    return ret%MOD;

}

int main(){
    memset(dp, -1, sizeof dp);
    cin >> k >> d;
    n=k.length();
    cout << (solve()-1+MOD) % MOD << endl;
    return 0;
}
