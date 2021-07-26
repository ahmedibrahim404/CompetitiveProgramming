#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int MAX=1e5;
int color[MAX];vvi ns;

void dfs(int node, int par, int col){

    color[node]=col;

    for(int to: ns[node]){
        if(to==par) continue;
        dfs(to, node, !col);
    }


}

int n;
int main(){
    cin >> n;
    ns=vvi(n);
    int a, b;
    for(int i=0;i<n-1;i++) {
        cin >> a >> b;
        a--, b--;
        ns[a].push_back(b);
        ns[b].push_back(a);
    }
    memset(color, -1, sizeof color);
    dfs(0, -1, 0);

    int twos=0;
    for(int i=0;i<n;i++) if(color[i]==1) twos++;
    long long res=0;
    for(int i=0;i<n;i++){
        if(color[i]==0){
            res += (long long) twos-ns[i].size();
        }
    }

    cout << res << "\n";



    return 0;
}
