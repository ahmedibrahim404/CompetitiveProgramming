#include<bits/stdc++.h>

using namespace std;

const int MAX=16+2;
int getBit(int num, int i){
    return (num>>i)&1;
}


int t, n;
int ns[MAX][MAX];
int dp[MAX][1<<16 + 1];
int sum[MAX][1<<16 + 1];
vector<int> vi[1<<16 + 1];

int calc(int idx,int x)
{
    int ret = 0;
    for(int i=0;i<n;++i)
        if( (1<<i) & x)
            ret+=ns[idx][i];
    return ret;
}

void init() {
    for(int i=0; i<1<<16; i++) {
        if((i&(i<<1))==0) {
            for(int j=0; j<1<<16; j++) {
                if((j&(j<<1))==0&&(j&(i<<1))==0&&(j&i)==0&&(j&(i>>1))==0) {
                    vi[i].push_back(j);
                }
            }
        }
    }
}

int solve(int idx, int pre){

    if(idx==n) return 0;

    int &ret=dp[idx][pre];
    if(~ret) return ret;

    ret=0;
    int sz=vi[pre].size();
    for(int j=0;j<sz;j++){
        int su=0;
        for(int i=0;i<n;i++) if(vi[pre][j]>>i & 1) su += ns[ idx ][ i ];
        ret=max(ret, su+ solve(idx+1, vi[pre][j]));
    }

    return ret;
}

int main(){
    init();
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) scanf("%d",&ns[i][j]);
        }

        memset(dp, -1, sizeof dp);
        int ans=solve(0, 0);

        printf("%d\n", ans);
    }
    return 0;
}
