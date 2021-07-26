#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m;
int a, b;
vector< vector< int > > ns;
vector<int> vis;

enum status { PATH=0, CYCLE=1 };


status DFS(int node, int par, int &cnt){

    if(vis[node]) return CYCLE;

    vis[node] = true;

    for(int child: ns[node]){

        if(child != par){

            ++cnt;
            if(DFS(child, node, cnt) == CYCLE)
                return CYCLE;

        }

    }

    return PATH;

}


int main(){

    cin >> n >> m;
    int toRemove=0;
    ns = vector< vector<int> > (n+1);
    vis= vector<int>(n+1);
    while(m--){

        cin >> a >> b;
        ns[a].push_back(b);
        ns[b].push_back(a);

    }

    for(int i=1;i<=n;i++){

        if(!vis[i]) {
            int cnt=0;
            status st = DFS(i, -1, cnt);

            if(st == CYCLE)
                toRemove += (cnt % 2 == 1);

        }

    }

    if( (n - toRemove) % 2 == 1)
        toRemove++;



    cout << toRemove << endl;

    return 0;
}
