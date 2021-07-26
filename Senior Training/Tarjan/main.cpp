#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int N = 100000 + 3;
int n, tim=0;
vvi adj;

int dfn[N], lowestLink[N];
stack<int> stk;
bool inStack[N], visited[N];
void tarjan(int node){


    inStack[node]=1;
    stk.push(node);
    dfn[node] = lowestLink[node] = tim++;

    for(int child: adj[node]){
        if(dfn[child]==-1) {
            tarjan(child);
            lowestLink[node]=min(lowestLink[node], lowestLink[child]);
        } else if(inStack[child]){
            lowestLink[node]=min(lowestLink[node], dfn[child]);
        }
    }

    if(dfn[node] == lowestLink[node]){

        int cur=-1;
        while(cur != node){
            cur=stk.top();stk.pop();inStack[cur]=0;
            cout << cur << " ";
        }

        cout << endl;

    }


}


int main() {
    int m;
    scanf("%d%d", &n,&m);
    adj=vvi(n);
    for(int i=0;i<n;i++) inStack[i]=0, dfn[i]=-1;
    while(m--){
        int a, b;
        scanf("%d%d",&a,&b);a--,b--;
        adj[a].push_back(b);
    }

    tarjan(0);

    return 0;
}
