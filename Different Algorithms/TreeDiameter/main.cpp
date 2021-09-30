#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

// first => diameter passes here
// second => height
vvi ns;
pi diameter(int node=0, int par=-1){

    vi brs(2, 0);
    int sz=ns[node].size();
    int di=0;

    for(int i=0;i<sz;i++){
        int to=ns[node][i];
        if(to==par) continue;
        pi nw=diameter(to, node);

        // check
        di=max(di, nw.first);

        if(nw.second+1>brs[1]) brs[1]=nw.second+1;
        if(brs[1]>brs[0]) swap(brs[1], brs[0]);


    }

    di=max(di, brs[0]+brs[1]);
    return pi(di, brs[0]);


}

int n, m;
int main(){
    scanf("%d%d",&n,&m);
    ns=vvi(n);
    while(m--){
        int a, b;
        scanf("%d%d",&a,&b);
        a--, b--;
        ns[a].push_back(b);
        ns[b].push_back(a);
    }

    pi d=diameter();
    printf("%d\n", d.first);
    return 0;

}
