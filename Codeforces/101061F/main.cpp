#include<bits/stdc++.h>
using namespace std;
const int N = 101;
int t, n;
int ns[N];int mid;
int dp[N][N*N+5];
bool solve(int idx, int diff=0){

    if(idx == n) return abs(diff-N*N) <= mid;

    int &ret=dp[idx][diff];
    if(~ret) return ret;
    bool a=0, b=0;

    if(abs(diff - N*N + ns[idx]) <= mid) a = solve(idx+1, diff+ns[idx]);
    if(abs(diff - N*N - ns[idx]) <= mid) b = solve(idx+1, diff-ns[idx]);

    return ret = a|b;

}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);int sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",&ns[i]);
            sum += ns[i];
        }
        int st=0, en=sum;
        while(en >= st){
            for(int i=0;i<n;i++) for(int j=0;j<N*N+3;j++) dp[i][j]=-1;
            mid=(st+en)/2;
            if(solve(0, N*N)) en=mid-1;
            else st=mid+1;
        }

        printf("%d\n", en+1);

    }
    return 0;
}
