#include <iostream>

using namespace std;

int dp[100000+9], h[100000+9], n, k;
unsigned int OO = 2e9;
int solve(int cur=0){
    if(cur == n-1) return 0;
    int &ret=dp[cur];
    if(ret!=-1) return ret;
    ret=OO;

    int last=min(cur+k, n-1);
    for(int i=cur+1;i<=last;i++){
        ret=min(ret, solve(i)+abs(h[cur]-h[i]));
    }

    return ret;

}

int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) dp[i]=-1;
    for(int i=0;i<n;i++) scanf("%d",&h[i]);
    printf("%d",solve());
    return 0;
}

/*
int main(){

    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) dp[i]=OO;
    for(int i=0;i<n;i++) scanf("%d",&h[i]);

    dp[n-1]=0;
    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            if(i-j > k) break;
            dp[j]=min(dp[j], abs(h[i]-h[j])+dp[i]);
        }
    }

    printf("%d", dp[0]);

    return 0;
}
*/
