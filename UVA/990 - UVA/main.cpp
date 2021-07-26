#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const int MAX=30+1;
int t, w, n;
ll a, b;
pi ns[MAX];
int dp[MAX][1000+3];
bool vis[MAX][1000+3];
vector<int> ans;
int solve(int idx, int time){

    if(idx==n) return 0;

    int &ret=dp[idx][time];
    if(~ret) return ret;

    ret=solve(idx+1, time);

    int tm=3*ns[idx].first*w;
    if(time>tm)ret=max(ret, solve(idx+1, time-tm)+ns[idx].second);

    return ret;
}

void build(int idx, int time){

    if(idx==n) return;

    int ret=dp[idx][time];
    if(vis[idx][time]) return;
    vis[idx][time]=1;

    if(ret==solve(idx+1, time)){
        build(idx+1, time);
        return;
    }

    int tm=3*ns[idx].first*w;
    if(time>tm && ret==solve(idx+1, time-tm)+ns[idx].second){
        ans.push_back(idx);
        build(idx+1, time-tm);
    }
    return;
}

int main(){
    int T=0;
    while(cin >> t){
        if(T) cout << "\n";
        cin >> w >> n;
        memset(dp, -1, sizeof dp);
        memset(vis, 0, sizeof vis);
        ans.clear();
        T++;
        for(int i=0;i<n;i++){
            cin >> ns[i].first >> ns[i].second;
        }

        cout << solve(0, t) << "\n";
        build(0, t);
        cout << ans.size() << "\n";
        for(int i=0;i<ans.size();i++){
            cout << ns[ ans[i] ].first << " " << ns[ ans[i] ].second << "\n";

        }
    }

    return 0;
}
