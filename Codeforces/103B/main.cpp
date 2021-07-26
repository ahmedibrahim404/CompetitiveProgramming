#include<bits/stdc++.h>

using namespace std;
const int N=100+5;
int n, m;
int par[N];

void init(){
    iota(par, par+n, 0);
}

int get(int node){
    return par[node] = par[node] == node ? node : get(par[node]);
}

void addEdge(int a, int b){
    a=get(a);b=get(b);

    if(a != b){
        par[b]=a;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    init();
    int add=0;
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        a--, b--;
        if(get(a) == get(b)){
            add++;
        }
        addEdge(a, b);
    }

    bool is = (add==1);
    int cur=get(0);
    for(int i=1;i<n;i++){
        is &= (get(i) == cur);
    }


    if(is) printf("FHTAGN!\n");
    else printf("NO\n");
    return 0;
}
