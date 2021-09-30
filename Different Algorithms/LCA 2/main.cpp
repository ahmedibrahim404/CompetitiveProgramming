#include<bits/stdc++.h>
using namespace std;

/**

    some nice solution for LCA
        for lca(p, q)
            if(level[p]>level[q]) swap up for p
            else if(level[p]<level[q]) swap up for q
            else swap up for both till p=q
        but this code complexity is O(height)

        good idea is to jump 2^j nodes up

        suppose we have tree as follow
        0
        1
        2
        3
        4
        5
        6
        7
        8

        if we need to get 2^3 ancestor of 8 which is 0 we can do follow
            get the 2^2 ancestor of the ( 2^2 ancestor of node 8 )

        recurrence =>>>
        P[i][j]={
            T[i] if (j=0)
            P[ P[i][j-1] ][j-1]
        }




**/

const int MAX = 300000+3;
const int LOGMAX = 20;
int n, q, a, b, c;
int P[MAX][LOGMAX], parent[MAX], depth[MAX];
vector<vector<int> > tree;

void tree_dfs(int i, int p = -1, int d = 0) {
	parent[i] = p, depth[i] = d;
	for(int j=0; j<tree[i].size();j++)
		if (tree[i][j] != p)
			tree_dfs(tree[i][j], i, d + 1);
}

void preprocessing(int n) {
	memset(parent, -1, sizeof parent);
	for(int i=0;i<n;i++) if(parent[i] == -1)
		tree_dfs(i, i);

    for(int i=0;i<n;i++){
		for(int j=0;j<LOGMAX;j++)
			P[i][j] = -1;
		P[i][0] = parent[i];
	}

	for (int j = 1; j<LOGMAX; j++)
		for(int i=0;i<n;i++) //DP
			if (P[i][j - 1] != -1)
				P[i][j] = P[P[i][j - 1]][j - 1];
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

	return parent[p];
}

int kthPar(int p, int k){

    if(!k) return p;

	for(int i=LOGMAX-1;i>=0;i--)
		if ((1 << i) <= k)
			p = P[p][i], k-=(1<<i);

	return p;

}

int shortestPath(int n, int p, int q) {
	return depth[p]+depth[q]-2*depth[LCA(n, p, q)];
}



int main(){
    scanf("%d",&n);
    tree=vector<vector<int>>(n);
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
            a--, b--;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    preprocessing(n);

    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d",&a,&b,&c);
        a--, b--;
        int node=LCA(n, a, b);

        int cost1=shortestPath(n, a, node);
        int cost2=shortestPath(n, node, b);

        if(cost1+cost2<=c) {
            printf("%d\n", b+1);
            continue;
        }

        if(cost1 > c){
            printf("%d\n", kthPar(a, c)+1);
        } else {
            c-=cost1;
            printf("%d\n", kthPar(b, cost2-c)+1);
        }

    }

    return 0;
}
