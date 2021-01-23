#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=16;
const ll OO=1e18;
int n;
ll dp[1<<MAX];
ll cost[1<<MAX];
ll ns[MAX][MAX];
vector<vector<int>> masks;

int getBit(int mask, int idx){
    return (mask>>idx)&1;
}

int setBit1(int mask, int idx){
    return mask|(1<<idx);
}

int setBit0(int mask, int idx){
    return mask & ~(1<<idx);
}

int flip(int mask){

    int nmask=mask;
    for(int i=0;i<n;i++){
        if(getBit(mask, i)) nmask=setBit0(nmask, i);
        else nmask=setBit1(nmask, i);
    }

    return nmask;

}


ll solve(int mask){

    int cnt=__builtin_popcount(mask);
    if(cnt==n) return 0;

    ll &ret=dp[mask];
    if(~ret) return ret;
    ret=-OO;

    for(int i=0;i<masks[mask].size();i++){
        ll c=cost[ masks[mask][i] ];
        int nmask=masks[mask][i]|mask;
        ret=max(ret, (c/2)+solve(nmask));
    }


    return ret;

}

string str, a, b;

int main(){
    scanf("%d",&n);
    masks=vector<vector<int>>(1<<n);
    memset(dp, -1, sizeof dp);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)scanf("%lld",&ns[i][j]);

    for(int i=0;i<(1<<n);i++){
        ll tot=0;

        for(int j=0;j<n;j++){
            if(!getBit(i, j)) continue;

            for(int k=0;k<n;k++){
                if(getBit(i, k)) tot+=ns[j][k];
            }
        }
        cost[i]=tot;
    }


    for(int i=0;i<(1<<n);i++){
        int mask=i;
        mask=flip(mask);
        for(int sub=mask;sub;sub=(sub-1)&mask){
            masks[i].push_back(sub);
        }
    }



    printf("%lld\n", solve(0));
    return 0;
}
