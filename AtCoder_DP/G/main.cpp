#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int n, m, x, y;
vvi ns;
vi dp;

int solve(int node){

    int &ret=dp[node];
    if(ret != -1) return ret;

    ret=0;
    int sz=ns[node].size();
    for(int i=0;i<sz;i++){
        ret=max(ret, 1+solve(ns[node][i]));
    }

    return ret;

}

int main(){
    scanf("%d %d",&n,&m);
    ns=vvi(n), dp=vi(n, -1);
    for(int i=0;i<m;i++) {
        scanf("%d %d",&x,&y);
        x--, y--;
        ns[x].push_back(y);
    }

    int mx=0;
    for(int i=0;i<n;i++){
        mx=max(solve(i), mx);
    }

    printf("%d", mx);



    return 0;
}
