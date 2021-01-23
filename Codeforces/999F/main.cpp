#include <iostream>

using namespace std;
const int N=500+1, K=10+1, MAX=1e5+3;;
int n, k, ns[N*K];
int f[N], h[K], v[MAX], cnt[MAX];
int dp[N][N*K], vis[N][N*K];
int sz, lvl=1;
int solve(int cur, int tot){

    if(cur==sz ) return 0;

    int &ret=dp[cur][tot];
    if(vis[cur][tot] == lvl) return ret;
    vis[cur][tot]=lvl;
    ret=solve(cur+1, tot);
    for(int i=0;i<min(tot, k);i++){
        ret=max(ret, h[i]+solve(cur+1, tot-i-1));
    }

    return ret;
}

int no;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n*k;i++){
        scanf("%d",&no);
        cnt[no]++;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&no);
        v[ no ]++;
    }
    for(int i=0;i<k;i++) scanf("%d",&h[i]);

    int tot=0;
    for(int i=1;i<MAX;i++){
        if(!v[i]) continue;
        sz=v[i];
        tot += solve(0, cnt[i]);
        lvl++;
    }


    printf("%d\n", tot);


    return 0;
}
