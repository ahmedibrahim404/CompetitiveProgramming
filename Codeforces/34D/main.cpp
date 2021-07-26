#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, r1, r2, a;
vector<vector<int>> ns;
int nds[50000+9];
bool vis[50000+9];
void BFS(){

    queue<pair<int, int>> q;
    q.push(make_pair(r2, -1));

    while(!q.empty()){
        pair<int, int> no=q.front();q.pop();

//        cout << no.first << endl;
//
//        cout << no.second << " IS PARENT OF " << no.first << endl;
        vis[no.first]=true;
        nds[no.first]=no.second;
        for(int i=0;i<ns[no.first].size();i++){
            if(ns[no.first][i] != no.first && !vis[ ns[no.first][i] ]) q.push(make_pair(ns[no.first][i], no.first));
        }

    }

}

int main(){

    scanf("%d %d %d", &n, &r1, &r2);
    ns=vector<vector<int>>(n+1);
    for(int i=1;i<=n;i++){
        if(i == r1) continue;
        scanf("%d", &a);
        ns[i].push_back(a);
        ns[a].push_back(i);
    }

    BFS();

    for(int i=1;i<=n;i++){
        if(nds[i] != -1) cout << nds[i] << " ";
    }

    return 0;
}
