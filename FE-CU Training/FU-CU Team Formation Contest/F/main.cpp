#include<bits/stdc++.h>

using namespace std;

//struct edge {
//    int to, kind, cost;
//};

typedef pair<int, int> pi;
typedef pair<int, pi> ppi;
typedef vector<ppi> vi;
typedef vector<vi> vvi;
const int MAX=400+3;
typedef long long ll;


int t, n, m, ch, co, from, to;
ll chs[MAX];
map<string ,int> mp;
string str;
vvi ns;
ll dp[MAX][5];
ll solve(int idx, int how){
    if(idx==to) return 0;
    ll &ret=dp[idx][how];
    if(~ret) return ret;
    ret=1e9;
    for(int k=0;k<ns[idx].size();k++){
        ret=min(ret, solve(ns[idx][k].second.second, ns[idx][k].second.first)+ns[idx][k].first+( (ns[idx][k].second.first!=how&&how!=4)?chs[idx]:0 ));
    }
    return ret;
}



int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        mp.clear();
//        memset(vis, 0, sizeof vis);
        memset(dp, -1, sizeof dp);
        cin >> n;
        ns=vvi(n);
        for(int i=0;i<n;i++){
            cin >> str >> ch;
            mp[str]=i;
            chs[i]=ch;
        }
        int all;
        cin >> all;
        while(all--){
            ppi ed;
            string s1, s2, ty;
            cin >> s1 >> s2 >> ty >> ed.first;
            if(ty=="TRUCK") ed.second.first=1;
            else if(ty=="RAIL") ed.second.first=3;
            else if(ty=="AIR") ed.second.first=2;
            else ed.second.first=0;
            int idx1=mp[s1], idx2=mp[s2];
            ed.second.second=idx1;
            ns[idx2].push_back(ed);
            ed.second.second=idx2;
            ns[idx1].push_back(ed);

        }

        for(int i=0;i<n;i++){
            sort(ns[i].begin(), ns[i].end());
        }


        string s1, s2;
        cin >> s1 >> s2;
        from=mp[s1], to=mp[s2];
        cout << solve(from, 4) << endl;
//        build(from ,4);

    }
    return 0;
}
