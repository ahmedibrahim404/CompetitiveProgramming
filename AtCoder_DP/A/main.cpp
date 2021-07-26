#include <iostream>

using namespace std;

int n, h[100000+9], dp[100000+9];

int solve(int cur=0){
    if(cur == n-1) return 0;

    int &ret=dp[cur];
    if(ret != -1) return ret;

    ret =solve(cur+1)+abs(h[cur]-h[cur+1]);
    if(cur != n-2) ret = min(ret, solve(cur+2) + abs( h[cur]-h[cur+2] ));

    return ret;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) dp[i]=-1;
    for(int i=0;i<n;i++) scanf("%d",&h[i]);
    printf("%d\n", solve());

    return 0;
}


/*
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&h[i]);

    dp[n-1]=0;
    for(int i=n-2;i>=0;i--){
        dp[i]= dp[i+1]+abs(h[i]-h[i+1]);
        if(i != n-2) dp[i]=min(dp[i], dp[i+2]+abs(h[i]-h[i+2]));
    }

    printf("%d\n", dp[0]);
    return 0;
}
*/
