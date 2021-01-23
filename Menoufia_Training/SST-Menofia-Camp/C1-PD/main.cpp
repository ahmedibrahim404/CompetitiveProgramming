#include<bits/stdc++.h>
using namespace std;
const int MAX=100+3;
int ns[MAX], n, dp[MAX][5];

int solve(int i=0, int prev=0){

    if(i==n) return 0;

    int &v=dp[i][prev];

    if(v!=-1) return v;
    v=1e6;
    bool done=0;
    if(prev != 2 && (ns[i] == 2 || ns[i] == 4)) {
        v = min(v,solve(i+1, 2));
        done = true;
    }

    if(prev != 3 && (ns[i] == 3 || ns[i] == 4)) {
        v = min(v,solve(i+1, 3));
        done = true;
    }

    if(!done) v=min(v, solve(i+1, 1)+1);

    return v;

}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ns[i]);
        ns[i]++;
    }
    memset(dp, -1, sizeof(dp));
    printf("%d", solve());
    return 0;
}
