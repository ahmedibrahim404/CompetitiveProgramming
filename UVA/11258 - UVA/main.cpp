#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, n;
string str;
ll dp[200+1];
ll solve(int idx=0){

    if(idx==n) return 0;
    ll &ret=dp[idx];
    if(~ret) return ret;

    ll t=0;
    for(int i=idx;i<n;i++){
        t=t*10+(str[i]-'0');
        if(t > INT_MAX) break;
        ret=max(ret, t+solve(i+1));
    }

    return ret;

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> str;
        n=str.length();
        for(int i=0;i<n;i++) dp[i]=-1;
        cout << solve() << endl;
    }


    return 0;
}
