#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi ns;
int t, n;
int tim=0;
typedef long long ll;
const int MAX=200000+3;
int tms[MAX];
ll in;

bool stop=0;
void dfs(int node, int par){

    if(stop) return;
    if(tms[node] != -1){
        stop=1;
        in=(ll) tim-tms[node];
        return;
    }


    tms[node]=tim++;
    for(int to: ns[node]){
        if(to==par) continue;
        int pre=tim;
        dfs(to, node);
        tim=pre;
    }

}


/*

11
9 1
1 2
7 1
4 10
8 5
4 6
4 2
7 5
2 5
3 1
11 6

*/
int main(){
    scanf("%d",&t);
    while(t--){
            stop=0;
        scanf("%d",&n);
        ns=vvi(n);
        int a, b;
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            tms[i]=-1;
            a--, b--;
            ns[a].push_back(b);
            ns[b].push_back(a);
        }

        int leafs=0;
        for(int i=0;i<n;i++){
            if(ns[i].size()==1) leafs++;
        }


        dfs(0, -1);
        ll out=n-in;

        printf("%lld\n", 2*n*(in-1)-in*(in-1)+out+(leafs-1)*out);

    }
    return 0;
}
