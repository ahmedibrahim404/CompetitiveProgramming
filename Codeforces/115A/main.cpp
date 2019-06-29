#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, a[2000+9];
vector< vector<int> >ns;
typedef pair<int, int> ii;
int BFS(int x){

    queue<ii> q;
    q.push(ii(x, 1));
    int lvl=0;

    while(!q.empty()){

        ii pr = q.front();q.pop();
        lvl=max(lvl, pr.second);

        for(int i=0;i<ns[pr.first].size();i++){
            q.push(ii(ns[pr.first][i], pr.second+1));
        }

    }

    return lvl;

}

int main(){
    scanf("%d", &n);
    ns = vector< vector<int> >(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
//        i->a
        if(a[i] != -1) ns[a[i]].push_back(i);
    }

    int mx=1;
    for(int i=1;i<=n;i++){
        if(a[i] == -1){
            mx=max(mx, BFS(i));
        }
    }

    printf("%d", mx);

    return 0;
}
