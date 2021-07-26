#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int T, n, nodes;
vvi ns;

void dfs(int no, int par){

    int c=0;
    for(int i=0;i<ns[no].size();i++){
        if(ns[no][i]==par) continue;
        dfs(ns[no][i], no);
        c++;
    }

    if(c==0) nodes++;


}
int a,b;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ns=vvi(n);
        for(int i=0;i<n-1;i++){
            scanf("%d%d",&a,&b);
            a--, b--;
            ns[a].push_back(b), ns[b].push_back(a);
        }
        nodes=ns[0].size()==1?1:0;
        dfs(0, -1);
        printf("%d\n", nodes);
    }
    return 0;
}
