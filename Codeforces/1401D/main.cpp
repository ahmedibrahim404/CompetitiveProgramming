#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef long long ll;
const int MAX=100000+3;
const ll MOD=1e9+7;
vvi ns;
int t, n, m;
ll cnt[MAX];
map<pi, int> mp;
void dfs(int node, int par){
    pi id1 = {max(node, par), min(node, par)};
    for(auto to: ns[node]){
        if(to==par) continue;
        dfs(to, node);
        pi id2 = {max(to, node), min(to, node)};
        if(mp.find(id1) != mp.end()) {
            cnt[ mp[id1] ] += cnt[ mp[id2] ];
        }
    }
    if(mp.find(id1) != mp.end()) cnt[ mp[id1] ]++;
}



int main(){
    scanf("%d",&t);
    while(t--){
        mp.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++) cnt[i]=0LL;
        ns=vvi(n);
        for(int i=0;i<n-1;i++){
            int a, b;
            scanf("%d%d",&a,&b);
            a--, b--;
            ns[a].push_back(b);
            ns[b].push_back(a);
            mp[{max(a, b), min(a, b)}]=i;
        }
        dfs(0, -1);
        for(int i=0;i<n-1;i++){
            cnt[i] = cnt[i] * (n-cnt[i]);
        }
        scanf("%d",&m);
        vector<ll> vi;
        for(int i=0;i<m;i++){
            ll no;
            scanf("%lld",&no);
            vi.push_back(no);
        }

        sort(vi.begin(), vi.end());
        sort(cnt, cnt+n-1);

        while(m > n-1){
            ll fir=vi.back();vi.pop_back();
            ll sec=vi.back();vi.pop_back();
            vi.push_back((fir%MOD)*(sec%MOD)%MOD);
            m=vi.size();
        }

        int idx1=n-2, idx2=m-1;
        ll ans=0;
        while(idx1 >= 0 && idx2 >= 0){
            ans += ((cnt[idx1]%MOD)*(vi[idx2]%MOD))%MOD;
            ans %= MOD;
            idx1--, idx2--;
        }

        while(idx1 >= 0){
            ans += (cnt[idx1]%MOD);
            ans %= MOD;
            idx1--;
        }


        cout << ans%MOD << "\n";

    }
    return 0;
}
