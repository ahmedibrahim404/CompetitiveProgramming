#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 100000 + 3;
int n, tim=0, c=0;
const ll MOD = 1e9+7;

ll ans=1LL, tot=0LL;
vvi adj;
int dfn[N], lowestLink[N];
stack<int> stk;
bool inStack[N]; ll cost[N];


void tarjan(int node){

    stk.push(node);
    inStack[node]=1;
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

        int cur=-1, cnt=0;ll mn=1e9;
        while(cur != node){
            cur=stk.top();stk.pop();inStack[cur]=0;
            if(mn > cost[cur]){
                mn=cost[cur], cnt=1;
            } else if(mn == cost[cur]){
                cnt++;
            }
        }

        ans *= (1LL*cnt)%MOD;
        ans %= MOD;
        tot += 1LL * mn;
    }


}


int main() {
    int m;
    scanf("%d", &n);
    adj=vvi(n);

    for(int i=0;i<n;i++){
        inStack[i]=0, dfn[i]=-1;
        scanf("%lld",&cost[i]);
    }

    scanf("%d",&m);
    while(m--){
        int a, b;
        scanf("%d%d",&a,&b);a--,b--;
        adj[a].push_back(b);
    }

    for(int i=0;i<n;i++){
        if(dfn[i] == -1)tarjan(i);
    }

    printf("%lld %lld\n", tot, ans%MOD);

    return 0;
}
