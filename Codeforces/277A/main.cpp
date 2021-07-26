#include<bits/stdc++.h>
using namespace std;
const int N = 100 +3;
int n, m;
int par[N], sz[N];

void init(){
    iota(par, par+n, 0);
    for(int i=0;i<n;i++) sz[i]=1;
}

int get(int node){
    return par[node] = par[node] == node ? node : get(par[node]);
}

void addEdge(int a, int b){
    a=get(a);b=get(b);

    if(a != b){
        par[b]=a;
        sz[a] += b;
        sz[b]=0;
    }
}


vector<int> ns[N];
int main(){
    scanf("%d%d",&n,&m);
    init();
        bool is=1;
    for(int i=0;i<n;i++){
        int no;
        scanf("%d",&no);
        while(no--){
            int l;
            scanf("%d",&l);
            l--;
            ns[l].push_back(i);
            is=0;
        }
    }

    for(int i=0;i<m;i++){
        int sz=ns[i].size();
        if(!sz) continue;
        int cur=ns[i][0];
        for(int j=1;j<sz;j++){
            addEdge(cur, ns[i][j]);
        }
    }

    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(get(i));
    }
    printf("%d\n", st.size()-1 + is);

    return 0;
}
