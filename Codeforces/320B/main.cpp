#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int from[109], to[109];
vector< vector<int> > ns;
bool vis[109];
int n, t, a, b;

bool BFS(int x, int y){

    queue<int> q;
    q.push(x);

    while(!q.empty()){

        int no=q.front();q.pop();

        if(vis[no]) continue;
        if(no == y) return true;
        vis[no]=true;
        for(int i=0;i<ns[no].size();i++){
            q.push(ns[no][i]);
        }

    }

    return false;

}

bool check(int a, int b, int c, int d){
    return (a > c && d > a) || (b > c && d > b);
}

int main(){

    scanf("%d", &n);
    ns = vector<vector<int>>(101);

    int idx=1;
    for(int i=0;i<n;i++){

        scanf("%d %d %d", &t, &a, &b);
        if(t == 1){
            from[idx]=a, to[idx]=b;

            for(int j=1;j<idx;j++){
                int c=from[j], d=to[j];
                if(check(a, b, c, d)) ns[idx].push_back(j);
                if(check(c, d, a, b)) ns[j].push_back(idx);
            }
            idx++;
        } else {
            for(int i=0;i<109;i++) vis[i]=false;
            if(BFS(a, b)) printf("YES\n");
            else printf("NO\n");
        }


    }

    return 0;
}
