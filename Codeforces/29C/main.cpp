#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, a, b;
vector<vector<int>> ns;
map<int, int> mp1;
map<int, int> mp2;

bool vis[100000+9];

void DFS(int i, int from){

    if(vis[i]) return;
    vis[i]=true;
    cout << mp2[i] << " ";

    for(int k=0;k<ns[i].size();k++){
        if(ns[i][k] != from)
            DFS(ns[i][k], i);
    }

}

int main(){

    scanf("%d", &n);
    ns=vector<vector<int>>(n+1);
    int idx=0;
    for(int i=0;i<n;i++){
        scanf("%d %d", &a, &b);
        if(mp1.count(a) == 0){
            mp1.insert(make_pair(a, idx));
            mp2.insert(make_pair(idx, a));
            idx++;
        }

        if(mp1.count(b) == 0){
            mp1.insert(make_pair(b, idx));
            mp2.insert(make_pair(idx, b));
            idx++;
        }

        ns[ mp1[a] ].push_back(mp1[b]);
        ns[ mp1[b] ].push_back(mp1[a]);
    }

    for(int i=0;i<n;i++){
        if(ns[i].size() == 1){
            DFS(i, -1);
            break;
        }
    }



    return 0;
}
