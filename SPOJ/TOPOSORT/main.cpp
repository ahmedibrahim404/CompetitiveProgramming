#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 10000 + 3, M = 1000000;

vvi ns;
vi v;int outDeg[N];
int main(){

    int n, m;
    scanf("%d%d",&n,&m);
    ns=vvi(n);
    while(m--){
        int a, b;
        scanf("%d%d",&a,&b);
        a--, b--;
        ns[a].push_back(b);
        outDeg[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0;i<n;i++) if(!outDeg[i]) q.push(i);

    while(!q.empty()){
        int u=q.top();q.pop();
        v.push_back(u);
        for(int to: ns[u]){
            if(!--outDeg[to]) q.push(to);
        }
    }


    if(v.size() == n) for(int i=0;i<n;i++) printf("%d ", v[i] + 1);
    else printf("Sandro fails.\n");

    return 0;
}
