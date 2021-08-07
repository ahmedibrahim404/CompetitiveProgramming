#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const int N=5e5+5,M=1e9+7;
int t,n,m,k;
vector<int> adj[N];
int st[N],en[N],par[N];

int id;
void dfs(int u,int p){
    par[u]=p;
    st[u]=id++;
    for(int i=0;i<adj[u].size();++i){
        int v=adj[u][i];
        if(v==p) continue;
        dfs(v,u);
    }
    en[u]=id-1;
}

struct node{
    int sum,lz;

    void addLazy(int v,int ss,int se){
        sum=(se-ss+1)*v;
        lz=v;
    }
};

node seg[4*N];

void build(int si=0,int ss=0,int se=n-1){
    seg[si].lz=-1;
    if(ss==se){
        seg[si].sum=0;
        return;
    }
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    build(lf,ss,md);
    build(rt,md+1,se);
    seg[si].sum=seg[lf].sum+seg[rt].sum;
}

void pushDown(int si,int ss,int se){
    if(ss==se||seg[si].lz==-1) return;
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    seg[lf].addLazy(seg[si].lz,ss,md);
    seg[rt].addLazy(seg[si].lz,md+1,se);
    seg[si].lz=-1;
}

void setRange(int qs,int qe,int qv,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return;
    if(ss>=qs&&se<=qe){
        seg[si].addLazy(qv,ss,se);
        return;
    }
    pushDown(si,ss,se);
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    setRange(qs,qe,qv,lf,ss,md);
    setRange(qs,qe,qv,rt,md+1,se);
    seg[si].sum=seg[lf].sum+seg[rt].sum;
}

int query(int qs,int qe,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return 0;
    if(ss>=qs&&se<=qe) return seg[si].sum;
    pushDown(si,ss,se);
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    return query(qs,qe,lf,ss,md)+query(qs,qe,rt,md+1,se);
}


int main(){
    cin >> n;string str;
    for(int i=0;i<n;i++){
        cin >> str;
        for(int j=0;j<n;j++){
            if(str[j] == 'Y') cout << i << " " << j << "\n";
        }
    }
    scanf("%d",&n);
    for(int i=0;i<n-1;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1);
    build();
    scanf("%d",&m);
    while(m--){
        int ty,u;
        scanf("%d%d",&ty,&u);
        --u;
        if(ty==1){
            if(u != 0&&query(st[u],en[u])!=en[u]-st[u]+1) setRange(st[par[u]],st[par[u]],0);
            setRange(st[u],en[u],1);
        }
        else if(ty==2){
            setRange(st[u],st[u],0);
        }
        else{
            printf("%d\n",query(st[u],en[u])==en[u]-st[u]+1);
        }
    }
    return 0;
}
