#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[22][10000+9], ns[21];
int n;

ll solve(int idx, int got){
    if(got == 0) return 1;
    if(idx >= 22 || got < 0) return 0;
    ll &ret = dp[idx][got];
    if(ret != -1) return ret;
    ret=solve(idx+1, got) + solve(idx, got-ns[idx]);
    return ret;
}

int main(){

    for(int i=0;i<21;i++) ns[i]=(i+1)*(i+1)*(i+1);
    for(int i=0;i<21;i++) for(int j=0;j<10000+9;j++) dp[i][j]=-1;

    while(cin >> n){
        cout << solve(0, n) << endl;;
    }

    return 0;
}
