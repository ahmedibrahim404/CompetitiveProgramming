#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, ll> pl;
int n, L, C;
pl dp[1000+2][500+2];
bool visit[1000+2][500+2];
int ns[1000+2];


pl solve(int idx=0, int time=0){


    if(idx==n){
        pl rem(1, 0);
        if(L-time > 10) rem.second += 1LL*(L-time-10)*(L-time-10);
        else if(L-time <= 10 && L-time > 0) rem.second += -1LL*C;
        return rem;
    }

    pl&ret=dp[idx][time];
    if(ret.first != -1)return ret;
    ret.first=1e9, ret.second=1e18;
    if(time+ns[idx] <= L){
        ret=solve(idx+1, time+ns[idx]);
    }

    if(time){
    pl sec;
    sec=solve(idx+1, ns[idx]);
    sec.first += 1;
    if(L-time > 10) sec.second += 1LL*(L-time-10)*(L-time-10);
    else if(L-time <= 10 && L-time > 0) sec.second += -1LL*C;
    if(sec.first<ret.first) ret=sec;
    if(sec.first==ret.first){
        if( sec.second<ret.second ) ret=sec;
    }

    }
    return ret;


}

int main(){
    int cs=1;
    while(cin >> n && n){
        if(cs!=1) printf("\n");
        cin >> L >> C;
        for(int i=0;i<n;i++){
            scanf("%d",&ns[i]);
            for(int j=0;j<500+2;j++)dp[i][j].first=-1;
        }
        pl ans=solve();
        printf("Case %d:\nMinimum number of lectures: %d\nTotal dissatisfaction index: %d\n", cs++, ans.first, ans.second);
    }

    return 0;
}
