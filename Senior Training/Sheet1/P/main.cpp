#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
const int MAX=300000+3;
vvi ns;
int par[MAX];
int get(int v){
    if(v==par[v]) return v;
    return par[v]=get(par[v]);
}


int n, k, d;
int main(){
    scanf("%d%d%d",&n,&k,&d);
    ns = vvi(n);
    queue<int> q;
    vi dis(n, 1e9);

    for(int i=0;i<n;i++) par[i]=-1;

    int no;
    for(int i=0;i<k;i++) {
        scanf("%d",&no);
        no--;
        q.push(no);
        par[no]=no;
        dis[no]=0;
    }

    int as[n], bs[n];
    for(int i=0;i<n-1;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        a--, b--;
        as[i] =a;bs[i]=b;

        ns[a].push_back(b);ns[b].push_back(a);
    }


    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int to:ns[cur]){
            if(par[to] != -1 || dis[cur] + 1 > d) continue;
            par[to] = par[cur];
            dis[to] = dis[cur] + 1;
            q.push(to);
        }
    }

    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(par[ as[i] ] != par[ bs[i] ]){
            cnt++;
        }
    }

    printf("%d\n", cnt);
    for(int i=0;i<n-1;i++){
        if(par[ as[i] ] != par[ bs[i] ]){
            printf("%d ", i+1);
        }
    }

    printf("\n");





    return 0;
}
