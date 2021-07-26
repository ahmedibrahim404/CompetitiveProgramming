#include<bits/stdc++.h>

using namespace std;
const int N = 100000 + 3;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
int n;
int col[N], stTime[N], enTime[N], par[N], nodeTime[N], sz[N];
int curTime=0;
ll ans[N];
vvi ns;

struct Data {
    unordered_map<int, int> freq;
    int mx;
    ll sum;

    Data() : mx(0), sum(0) {

    }

    void add(int col) {
        int f = ++freq[col];
        if (f > mx)
            mx = f, sum = 0;
        if (f == mx)
            sum += col;
    }
};


void extend(Data &temp, int i){
    for (int j = stTime[i]; j <= enTime[i]; ++j) {
        int u = nodeTime[j];
        temp.add(col[u]);
    }
}


Data smallToLarge(int u){

    Data te;
    int mx=-1;
    for(int to: ns[u]){
        if(to == par[u]) continue;
        if(sz[to] * 2 > sz[u]) mx=to;
        else smallToLarge(to);
    }

    if(mx != -1) te=smallToLarge(mx);
    te.add(col[u]);
    for(int to: ns[u]){
        if(to == par[u] || to == mx) continue;
        extend(te, to);
    }

    ans[u]=te.sum;

    return te;



}

void dfs(int x){

    stTime[x]=curTime++;
    nodeTime[ stTime[x] ] = x;
    for(int to: ns[x]){
        if(to == par[x]) continue;
        par[to] = x;
        dfs(to);
        sz[x] += sz[to];
    }

    sz[x]++;
    enTime[x] = curTime-1;

}

int main(){
    scanf("%d",&n);ns=vvi(n);
    memset(sz, 0, sizeof sz);
    for(int i=0;i<n;i++) scanf("%d",&col[i]);
    for(int i=0;i<n-1;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        a--, b--;
        ns[a].push_back(b);
        ns[b].push_back(a);
    }
    dfs(0);

    smallToLarge(0);
    for(int i=0;i<n;i++) printf("%lld ", ans[i]);
    printf("\n");
    return 0;
}
