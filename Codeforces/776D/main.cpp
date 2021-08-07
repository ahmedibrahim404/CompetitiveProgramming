#include<bits/stdc++.h>
using namespace std;

/**
    1 & 2
    1 ^ 2
**/
const int N = 200000 + 3;
vector<vector<int>> adj;

#define Var(x) ((x)<<1)
#define Not(x) ((x)^1)

int tim=0, n;

int vis[N], stk[N], stkSz, compId[N], ncp,lw[N],dfsTime[N], curTime;

void addEdge(int a, int b){
    adj[a].push_back(b);
}


void addOR(int a, int b){
    addEdge(Not(a), b);
    addEdge(Not(b), a);
}

void addXOR(int a, int b){
    addOR(a, b);
    addOR(Not(a), Not(b));
}

void addXNOR(int a, int b){
    addOR(Not(a), b);
    addOR(a, Not(b));
}

void addImplication(int a, int b){
    addOR(Not(a), b);
}

void tarjanDFS(int u){
    vis[u]=1;
    stk[stkSz++]=u;
    lw[u]=dfsTime[u]=curTime++;
    compId[u]=-1;
    for(int v: adj[u]){
        if(vis[v]!=1){
            tarjanDFS(v); ///white
            lw[u]=min(lw[u],lw[v]);
        } else if(compId[v]==-1){ // Gray
            lw[u]=min(lw[u],lw[v]);
        }
    }

    if(lw[u]==dfsTime[u]){
        do{
            compId[stk[--stkSz]]=ncp;
        }while (stk[stkSz]!=u);

        ncp++;
    }

}


int main(){
    int m;
    scanf("%d%d",&n,&m);
    int open[n];
    for(int i=0;i<n;i++) vis[i]=0;
    adj = vector<vector<int>>(2*m);
    for(int i=0;i<n;i++){
        scanf("%d",&open[i]);
    }


    set<int> st[n];
    for(int i=0;i<m;i++){
        int k;scanf("%d",&k);
        while(k--){
            int node;
            scanf("%d",&node);
            node--;
            st[node].insert(i);
        }
    }

    for(int i=0;i<n;i++){
        auto it = st[i].begin();
        int fir=*it;
        int sec = *(++it);
        if(open[i]) addXNOR(Var(fir), Var(sec));
        else addXOR(Var(fir), Var(sec));
    }

    for(int i=0;i<2*m;i++){
        if(!vis[i]) tarjanDFS(i);
    }



    for(int i=0;i<2*m;i+=2){
        if(compId[i] == compId[i^1]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");



    return 0;
}
