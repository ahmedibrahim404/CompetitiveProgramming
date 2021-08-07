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

stack< pair<int, int> > component;

void tarjan(int node){


    inStack[node]=1;
    dfn[node] = lowestLink[node] = tim++;

    for(int child: ns[node]){

        if(node != child && dfn[child] < dfn[node]){
            component.push({node, child});
        }

        if(dfn[child]==-1) { // new biconnected component
            tarjan(child);
            lowestLink[node]=min(lowestLink[node], lowestLink[child]);
            if(lowestLink[child] >= dfn[node]) {
                // node 0, if first Biconnected Component ignore it
                if(dfn[node] == 0 && !root)
                    root=1;
                else
                    isArt[node]=1;


                // to print biconnected components
                // biconnected components means it has no art points ( at least to completely different pathes between any 2 nodes )
                do {

                    edge=component.top();component.pop();
                    cout << edge.first << " " << edge.second << endl;

                } while(edge.first != node || edge.second != node)

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

    }

    return 0;
}
