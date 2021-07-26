#include<bits/stdc++.h>

using namespace std;
const int N=51;
int n, m;
int par[N], sz[N];

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
        sz[a] += sz[b];
        sz[b]=0;
    }
}



int main(){

    scanf("%d%d",&n,&m);
    init();
    for(int i=0;i<n;i++) sz[i]=1;
    while(m--){
        int a, b;
        scanf("%d%d",&a,&b);
        a--, b--;
        addEdge(a, b);
    }

    long long ans=1;
    for(int i=0;i<n;i++){
        if(par[get(i)] == i) ans *= pow(2, sz[i] - 1);
    }

    printf("%lld\n", ans);

    return 0;
}
