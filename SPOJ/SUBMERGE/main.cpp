#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi ns;
int n, m;

const int N = 10000 + 7;
int tim=0;

int dfn[N], lowestLink[N];
bool isArt[N];bool root=0;
bool inStack[N];
void tarjan(int node){


    inStack[node]=1;
    dfn[node] = lowestLink[node] = tim++;

    for(int child: ns[node]){
        if(dfn[child]==-1) {
            tarjan(child);
            lowestLink[node]=min(lowestLink[node], lowestLink[child]);
            if(lowestLink[child] >= dfn[node]) {
                // node
                if(dfn[node] == 0 && !root)
                    root=1;
                else
                    isArt[node]=1;
            }

            if(lowestLink[child] > dfn[node]){
                // bridge
            }

        } else if(inStack[child]){
            lowestLink[node]=min(lowestLink[node], dfn[child]);
        }
    }

}


int main(){
    while(scanf("%d%d",&n,&m) && (n||m)){
        ns=vvi(n);ns.clear();tim=0, root=0;
        for(int i=0;i<n;i++) inStack[i]=0, dfn[i]=-1, isArt[i]=0;
        while(m--){
            int a, b;
            scanf("%d%d",&a,&b);
            a--, b--;
            ns[a].push_back(b);
            ns[b].push_back(a);
        }
        for(int i=0;i<n;i++){
            if(dfn[i] == -1)tarjan(i);
        }
        int c=0;
        for(int i=0;i<n;i++) if(isArt[i]) c++;
        printf("%d\n", c);

    }

    return 0;
}
