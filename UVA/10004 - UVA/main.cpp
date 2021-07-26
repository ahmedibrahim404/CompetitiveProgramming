#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int n, m, a, b;
int col[200+3];
vvi ns;
bool dfs(int node=0, int par=-1, int cur=0){


    if(col[node]!=-1){
        if(col[node]==cur) return 1;
        return 0;
    }

    col[node]=cur;

    bool is=1;

    int sz=ns[node].size();
    for(int i=0;i<sz;i++){
        int to=ns[node][i];
        if(to==par) continue;
        is &= dfs(to, node, !cur);
    }

    return is;


}

int main(){
    while(cin >> n && n){
        cin >> m;
        ns=vvi(n);
        memset(col, -1, sizeof col);
        while(m--){
            cin >> a >> b;
            ns[a].push_back(b);ns[b].push_back(a);
        }


        int res=dfs();
        if(res){
            cout << "BICOLORABLE.\n";
        } else {
            cout << "NOT BICOLORABLE.\n";
        }
    }
    return 0;
}
