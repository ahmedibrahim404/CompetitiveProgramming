#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=200+3;
int n, k;
ll d[MAX];
ll dp[MAX][30+1];
ll fr[MAX][MAX];
bool vis[MAX][30+1];
ll solve(int idx=0, int rem=k){
    ll &ret=dp[idx][rem];
    if(~ret) return ret;

    if(idx==n || !rem){
        if(idx==n && rem==0) return ret=0;
        return ret=1e18;
    }


    ret=1e18;
    for(int i=idx;i<n;i++){
        ll s=fr[idx][i];
        for(int j=i;j<n;j++){
            s+=abs(d[i]-d[j]);
            ret=min(ret, s+solve(j+1, rem-1));
        }
    }

    return ret;
}

int dd;
void build(int idx=0, int rem=k){


    if(idx==n || !rem){
        return;
    }

    ll ret=dp[idx][rem];
    if(vis[idx][rem]) return;
    vis[idx][rem]=1;

    for(int i=idx;i<n;i++){
        ll s=fr[idx][i];
        for(int j=i;j<n;j++){
            s+=abs(d[i]-d[j]);
            if(ret==s+solve(j+1, rem-1)){
                if(j==idx) cout << "Depot "<<dd++<<" at restaurant "<<i+1<<" serves restaurant "<<idx+1<< endl;
                else cout << "Depot "<<dd++<<" at restaurant "<<i+1<<" serves restaurants "<<idx+1<<" to "<<j+1<< endl;
                build(j+1, rem-1);
                return;

            }
        }
    }

}


int main(){
    int c=1;
    while(1){
        memset(dp, -1, sizeof dp);
        memset(fr, 0, sizeof fr);
        memset(vis, 0, sizeof vis);
        dd=1;
        cin >> n >> k;
        if(n==k&&n==0) break;
        for(int i=0;i<n;i++) cin >> d[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=i;k<j;k++){
                    fr[i][j]+=abs(d[j]-d[k]);
                }
                fr[j][i]=fr[i][j];
            }
        }

        cout << "Chain " << c++ << endl;
        ll cost=solve();
        build();
        cout << "Total distance sum = "<<cost << endl;
        cout << endl;
    }

    return 0;
}
