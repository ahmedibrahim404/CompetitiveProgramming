#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    scanf("%d",&n);
    int ns[n];
    for(int i=0;i<n;i++) scanf("%d",&ns[i]);

    int mx=1;
    int dp[n];
    for(int i=0;i<n;i++) dp[i]=1;
    for(int i=n-1;i>=0;i--)
        for(int j=0;j<i;j++)
            if(ns[i] > ns[j]) dp[j] = max(dp[j], dp[i] + 1);

    mx=*max_element(dp, dp+n);
    cout << mx << "\n";




    return 0;
}
