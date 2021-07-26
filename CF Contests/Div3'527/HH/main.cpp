#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int>pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int MAX=200000+3;
int n;
vvi ns;
bool col[MAX];
//void bfs2(int node){
//    vector<bool> vis(n, 0);
//    queue<pair<int, int>> q;
//    q.push({node, 0});
//    int tonode=-1, mx=0;
//    while(!q.empty()){
//        pi no=q.front();q.pop();
//        int fir=no.first, sec=no.second;
//        vis[fir]=1;
//        int sz=ns[fir].size();
//        for(int i=0;i<sz;i++){
//            int to=ns[fir][i];
//            if(vis[to]) continue;
//            vis[to]=1;
//            q.push({to, sec+1});
//            if(sec+1>mx && !col[to]) mx=sec+1, tonode=to;
//        }
//    }
//
//    col[node]=1;
//    col[tonode]=1;
//
//
//}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)col[i]=0;
    ns=vvi(n);
    int a, b;
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        a--, b--;
        ns[a].push_back(b);
        ns[b].push_back(a);
    }

    int tot=0;
//    for(int i=0;i<n;i++){
//        if((ns[i].size() == 1 && !col[i])){
//            tot++;
//            bfs2(i);
//        }
//    }

    int cnt=0;
    for(int i=0;i<n;i++){
        if(ns[i].size()==1) cnt++;
    }

    printf("%d\n", (cnt+1)/2);

    return 0;
}
