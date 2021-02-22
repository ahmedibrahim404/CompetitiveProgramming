#include<bits/stdc++.h>

using namespace std;

double ans;
int n;
int a, b;
vector<vector<int>> ns;
void dfs(int node, int par, int len, double cur){
    int sz=( ns[node].size() );
    if(node != 0) sz--;
    double eh=1.0/sz;
    for(int i=0;i<ns[node].size();i++){
        int to=ns[node][i];
        if(to == par) continue;
        dfs(to, node, len+1, cur*eh);
    }

    if(!sz){
        ans += cur * 1.0 * len;
    }

}

int main(){
    ans=0;
    cin >> n;
    ns =vector<vector<int>>(n);
    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        ns[a-1].push_back(b-1);
        ns[b-1].push_back(a-1);

    }
    dfs(0, -1, 0, 1);
    cout << fixed;
    cout << setprecision(10);
    cout << ans;
    return 0;
}
