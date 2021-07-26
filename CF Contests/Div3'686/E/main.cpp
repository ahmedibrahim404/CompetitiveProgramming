#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<set<int>> vvi;
vvi ns;
int t, n;
typedef long long ll;
const int MAX=200000+3;

/*

11
9 1
1 2
7 1
4 10
8 5
4 6
4 2
7 5
2 5
3 1
11 6

*/
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ns=vvi(n);
        int a, b;
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            a--, b--;
            ns[a].insert(b);
            ns[b].insert(a);
        }

        vi v(n, 1);
        queue<int> q;
        for(int i=0;i<n;i++) if(ns[i].size() == 1) q.push((int)i);
        while (q.size())
        {
            int u = q.front();
            q.pop();
            int to = *ns[u].begin();
            v[to] += v[u];
            v[u] = 0;
            ns[u].clear();
            ns[to].erase(u);
            if(ns[to].size() == 1) q.push(to);
        }
        ll ans = 0;
        for(int i=0;i<n;i++){
            ans += v[i] * 1LL * (v[i] - 1) / 2;
            ans += v[i] * 1LL * (n - v[i]);
        }

        printf("%lld\n", ans);

    }
    return 0;
}
