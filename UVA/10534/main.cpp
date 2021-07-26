#include<bits/stdc++.h>
using namespace std;

int dp[10000], dp2[10000], n;
int ns[10000];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin >> ns[i];
            dp[i]=1;dp2[i]=1;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(ns[j]<ns[i]) dp[i]=max(dp[i], dp[j]+1);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(ns[j]<ns[i]) dp2[i]=max(dp2[i], dp2[j]+1);
            }
        }
        int mx=1;
        for(int i=0;i<n;i++){
            mx=max(mx, min(dp[i], dp2[i])*2-1);
        }

        cout << mx<<endl;

    }
    return 0;
}
