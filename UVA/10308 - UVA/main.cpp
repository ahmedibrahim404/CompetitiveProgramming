#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<pi> vi;
typedef vector<vi> vvi;
const int MAX=10000+3;
vvi ns;
int n;
pi bfs(int node){

    vector<bool> vis(MAX, 0);

    queue<pi> q;
    q.push(pi(node, 0));

    int mxdist=0, mx=0;

    while(!q.empty()){

        pi no=q.front();q.pop();
        int node=no.first;
        int sz=ns[node].size();
        vis[node]=1;
        for(int i=0;i<sz;i++){
            pi to=ns[node][i];

            if(vis[to.first]) continue;
            vis[to.first]=1;
            q.push(pi(to.first, to.second+no.second));
            if(to.second+no.second > mxdist) mxdist=to.second+no.second, mx=to.first;

        }

    }


    return {mx, mxdist};

}

int a, b, c;
string str;

void solve(){

    pi ans=bfs(0);
    pi ans2=bfs(ans.first);
    cout << ans2.second << "\n";

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    stringstream ss;
    string line;
    int st, en, wt;
    bool done=0;
    ns=vvi(MAX);

    // read input


    return 0;
}
