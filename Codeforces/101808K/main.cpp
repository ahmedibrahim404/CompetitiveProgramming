#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, ll> pi;
typedef vector<pi> vi;
typedef vector<vi> vvi;

const int N = 100000 + 3, LOGMAX = 18;
int n, tim=0;
vvi adj;

int dfn[N], lowestLink[N];
stack<int> stk;
bool inStack[N], visited[N];
bool cyc[N];
int t, q, head;


void tarjan(int node, int par){

    inStack[node]=1;
    stk.push(node);
    dfn[node] = lowestLink[node] = tim++;

    for(pi to: adj[node]){
        int child=to.first;
        if(child == par) continue;
        if(dfn[child]==-1) {
            tarjan(child, node);
            lowestLink[node]=min(lowestLink[node], lowestLink[child]);
        } else if(inStack[child]){
            lowestLink[node]=min(lowestLink[node], dfn[child]);
        }
    }

    if(dfn[node] == lowestLink[node]){
        int cur=-1;set<int> st;
        do {
            cur=stk.top();stk.pop();
            st.insert(cur);
        } while(cur != node);
        if(st.size() > 1){
            for(auto it=st.begin();it!=st.end();it++)cyc[*it]=1;
        }

    }


}

ll dis[N], dis2[N], totalCost;int par[N], depth[N], HEAD[N];
void dfs(int cur, int curPar){

    for(pi to: adj[cur]){
        int node=to.first, cost=to.second;
        if(node == curPar || cyc[node]) continue;
        par[node]=cur;
        dis[node]=dis[cur] + cost;
        depth[node]=depth[cur]+1;
        HEAD[node]=head;
        dfs(node, cur);
    }

}


void dfs2(int cur, int curPar){

    if(cur == head && curPar != -1){
        totalCost = dis2[cur];
        dis2[cur]=0;
        return;
    }

    for(pi to: adj[cur]){
        int node=to.first, cost=to.second;
        if(node == curPar || !cyc[node]) continue;
        dis2[node]=dis2[cur] + cost;
        dfs2(node, cur);
    }

}

int P[N][LOGMAX];

void preprocessing(int n) {

    for(int i=0;i<n;i++){
		for(int j=0;j<LOGMAX;j++)
			P[i][j] = -1;
		P[i][0] = par[i];
	}

	for (int j = 1; j<LOGMAX; j++)
		for(int i=0;i<n;i++) //DP
			if (P[i][j - 1] != -1){
				P[i][j] = P[P[i][j - 1]][j - 1];
            }
}


int LCA(int n, int p, int q) {
	if (depth[p] < depth[q])		swap(p, q);

	for(int i=LOGMAX-1;i>=0;i--)
		if (depth[p] - (1 << i) >= depth[q])
			p = P[p][i];

	if (p == q)
		return p;

	for(int i=LOGMAX-1;i>=0;i--)
		if (P[p][i] != -1 && P[p][i] != P[q][i])
			p = P[p][i], q = P[q][i];

	return par[p];
}

ll dist(int p, int q){
    int l = LCA(n, p, q);
    return dis[p] + dis[q] - 2 * dis[l];
}

ll distCycs(int p, int q){
    ll cost = abs(dis2[p] - dis2[q]);
    return min(cost, totalCost-cost);
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);adj=vvi(n);
        for(int i=0;i<n;i++){
            cyc[i]=0;dis[i]=0LL;dfn[i]=-1;
            int a, b;ll c;
            scanf("%d%d%lld",&a,&b,&c);a--, b--;
            adj[a].push_back({b, c});adj[b].push_back({a, c});
        }
        tarjan(0, -1);

        vector<int> heads;
        for(int i=0;i<n;i++)
            if(cyc[i])
                for(pi to: adj[i]) if(!cyc[to.first]) {heads.push_back(i);break;}


//        if(!heads.size()) heads.push_back(0);

        for(int i=0;i<heads.size();i++){
            head=heads[i];
            dis[head]=0;
            depth[head]=0;
            dfs(head, -1);
            par[head]=head;
        }

        for(int i=0;i<n;i++) if(cyc[i]) { head=i;dfs2(i, -1);break; }

        preprocessing(n);

        while(q--){
            int a, b;
            scanf("%d%d",&a,&b);
            a--, b--;
            if(a==b) {printf("0\n");continue;}
            if(cyc[a] && cyc[b]){
                printf("%lld\n", distCycs(a, b));
            } else if(cyc[a] || cyc[b]){
                if(cyc[a]) swap(a, b);
                printf("%lld\n", distCycs(b, HEAD[a]) + dist(HEAD[a], a));
            } else {
                if(HEAD[a] != HEAD[b]) printf("%lld\n", dist(a, HEAD[a]) + dist(b, HEAD[a]) + distCycs(HEAD[a], HEAD[b]));
                else printf("%lld\n", dist(a, b));
            }
        }

    }
    return 0;
}
