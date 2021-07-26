#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    while(cin >> n){
    if(!n) break;
    int ns[n];
    for(int i=0;i<n;i++) cin >> ns[i];

    int dp[n];
    int pre[n];
    memset(pre, -1, sizeof pre);
    for(int i=0;i<n;i++) dp[i]=1;
    for(int i=n-1;i>=0;i--)
        for(int j=0;j<i;j++){
            if(ns[i] > ns[j]) {
                if(dp[i] + 1 > dp[j]) dp[j] = dp[i] + 1, pre[j] = i;
                else if(dp[i] + 1 == dp[j]){
                    if( pre[j] != -1 && ns[ pre[j] ] > ns[i] ) pre[j] = i;
                }
            }
        }

    int mx=*max_element(dp, dp+n);
    vector<int> vi[201];int cur=0;
    for(int i=0;i<n;i++){
        if(dp[i] == mx){
            int idx=i;
            while(idx != -1){
                vi[cur].push_back(ns[idx]);
                idx=pre[idx];
            }
            cur++;
        }
    }

    sort(vi, vi+cur);
    cout << mx << " ";
    for(int i=0;i<mx;i++) cout << vi[0][i] << " ";
    cout << "\n";

    }


    return 0;
}
