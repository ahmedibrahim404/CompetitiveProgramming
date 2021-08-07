#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 10000+3;
const int LOGMAX = 15;
int n, q, a, b, c;
int P[MAX][LOGMAX], par[MAX], depth[MAX];
ll dis[MAX][LOGMAX];
vector<vector<pair<int, int>> > ns;

void dfs(int i, int p = -1, int d = 0) {
	par[i] = p, depth[i] = d;
	for(int j=0; j<ns[i].size();j++)
		if (ns[i][j].first != p){
			dis[ ns[i][j].first ][0] = ns[i][j].second;
			dfs(ns[i][j].first, i, d + 1);
		}
}

void preprocessing(int n) {
	memset(par, -1, sizeof par);
	for(int i=0;i<n;i++) if(par[i] == -1)
		dfs(i, i);

    for(int i=0;i<n;i++){
		for(int j=0;j<LOGMAX;j++)
			P[i][j] = -1;
		P[i][0] = par[i];
	}

	for (int j = 1; j<LOGMAX; j++)
		for(int i=0;i<n;i++) //DP
			if (P[i][j - 1] != -1){
				P[i][j] = P[P[i][j - 1]][j - 1], dis[i][j] = dis[i][j-1] + dis[P[i][j-1]][j-1];
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

int kthPar(int p, int k){

    if(!k) return p;

	for(int i=LOGMAX-1;i>=0;i--)
		if ((1 << i) <= k)
			p = P[p][i], k-=(1<<i);

	return p;

}

int sp(int n, int p, int q) {
	return depth[p]+depth[q]-2*depth[LCA(n, p, q)];
}

ll shortestPath(int p, int q) {
    int l = LCA(n, p, q);
    ll diss=0;

	for(int i=LOGMAX-1;i>=0;i--){
		if (depth[p] - (1 << i) >= depth[l]){
            diss += dis[p][i];
            p = P[p][i];
		}
    }

	for(int i=LOGMAX-1;i>=0;i--){

		if (depth[q] - (1 << i) >= depth[l]){
            diss += dis[q][i];
            q = P[q][i];
        }
    }

    return diss;

}



int main(){
    int t;
    scanf("%d",&t);
    //t=1;
    while(t--){
        int n;
        scanf("%d",&n);
        ns=vector<vector<pair<int, int>>>(n);
        ns.clear();
        for(int i=0;i<n-1;i++){
            int a, b, c;
            scanf("%d%d%d",&a,&b,&c);
            a--, b--;
            ns[a].push_back({b, c});
            ns[b].push_back({a, c});
        }

        preprocessing(n);
        char str[500];
        while(scanf("%s", str) && str[1] != 'O'){
            int a, b, c;
            if(str[0] == 'D'){
                scanf("%d%d",&a,&b);
                a--, b--;
                printf("%lld\n", shortestPath(a, b));
            } else {
                scanf("%d%d%d",&a,&b,&c);
                a--, b--, c--;
                int node=LCA(n, a, b);
                int cost1=sp(n, a, node);
                int cost2=sp(n, node, b);

                if(cost1 > c){
                    printf("%d\n", kthPar(a, c)+1);
                } else {
                    c-=cost1;
                    printf("%d\n", kthPar(b, cost2-c)+1);
                }
            }
        }

        printf("\n");

    }
    return 0;
}
