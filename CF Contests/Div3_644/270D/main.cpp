#include <iostream>

using namespace std;

int n, m, ns[5000+3];
int dp[5000+3];
double non;
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> ns[i]>> non;
    }

    for(int i=n-1;i>=0;i--){
        dp[i]=1;
        for(int j=i+1;j<n;j++){
            if(ns[j] >= ns[i]) dp[i]=max(dp[i], dp[j]+1);
        }
    }

    int mx=1;
    for(int i=0;i<n;i++) mx=max(mx, dp[i]);
    printf("%d\n", n-mx);

    return 0;
}
