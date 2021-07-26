#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int MAX=1e5+3;
int n, m, a, b;
int cs[MAX];
vector<vi> ns;
bool vis[MAX];
set<int> st[MAX];
void dfs(int node){
    if(vis[node]) return;
    vis[node]=1;
    int sz=ns[node].size();
    for(int i=0;i<sz;i++){
        int no=ns[node][i];
        if(cs[no] != cs[node]){
            st[cs[node]].insert(cs[no]);
//            st[cs[no]].insert(cs[node]);
        }
        if(!vis[no])dfs(no);
    }
}

int main(){

    cin >> n >> m;
    memset(vis, 0, sizeof vis);
    ns=vector<vi>(n);
    for(int i=0;i<n;i++) cin >> cs[i];
    while(m--){
        cin >> a >> b;
        a--, b--;
        ns[a].push_back(b);
        ns[b].push_back(a);
    }

    for(int i=0;i<n;i++) dfs(i);
    int oo=-1, ans=0;
    for(int i=0;i<n;i++){
        int sz=st[cs[i]].size();
        if(sz>oo || (sz==oo && cs[i]<ans))oo=sz, ans=cs[i];
    }

    cout << ans;

    return 0;
}
