#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > adjList, comps;vector<vector<int>> dagList;
vector<int> inStack, lowLink, dfn, comp;
stack<int> stk;
int ndfn, cntSrc, cntSnk;

void tarjan(int node) {
	lowLink[node] = dfn[node] = ndfn++, inStack[node] = 1;
	stk.push(node);

	for(int i=0;i<adjList[node].size();i++) {
		int ch = adjList[node][i];
		if (dfn[ch] == -1) {
			tarjan(ch);
			lowLink[node] = min(lowLink[node], lowLink[ch]);
		} else if (inStack[ch])
			lowLink[node] = min(lowLink[node], dfn[ch]);
	}

	if (lowLink[node] == dfn[node]) {
		comps.push_back(vector<int> ());
		int x = -1;
		while (x != node) {
			x = stk.top(), stk.pop(), inStack[x] = 0;
			comps.back().push_back(x);
			comp[x] = comps.size() - 1;
		}
	}
}

void scc() {
	int n = adjList.size();

	inStack.clear();	inStack.resize(n);
	lowLink.clear();	lowLink.resize(n);
	dfn.clear();		dfn.resize(n, -1);
	ndfn = 0;

	comp.clear(), comp.resize(n);
	comps.clear();

	for(int i=0;i<n;i++) if (dfn[i] == -1)
		tarjan(i);
}
void computeCompGraph() {
	int csz = comps.size();
    dagList = vector<vector<int>>(csz);
	dagList.clear();

	for (int i = 0; i < adjList.size(); i++)
		for (int j = 0; j < adjList[i].size(); j++) {
			int k = adjList[i][j];
            dagList[comp[i]].push_back(comp[k]);
		}

}

int main() {

	int cases;
	cin >> cases;

	while (cases--) {
		int n, m;
		cin >> n >> m;
		adjList.clear();
		adjList = vector<vector<int> > (n);

		for(int i=0;i<m;i++) {
			int f, t;
			cin >> f >> t;
			f--, t--;
			adjList[f].push_back(t);
		}

		scc();
		computeCompGraph();


        queue<int> q;
        q.push(comp[0]);
        int ans[ comps.size() ], vis[ comps.size() ];
        memset(vis, 0, sizeof vis);
        for(int i=0;i<comps.size();i++) ans[i]=0;
        while(!q.empty()){
            int cur=q.front();q.pop();
            vis[cur]++;
            if(vis[cur] > 2) continue;
            if(ans[cur] != -1) ans[cur]=vis[cur];
            for(auto to: dagList[cur]){
                if(cur == to){
                    ans[cur]=-1;
                    continue;
                }

                if(vis[to] >= 2) continue;
                q.push(to);
            }
        }


        queue<int> q2;
        for(int i=0;i<comps.size();i++) if(ans[i] == -1) q2.push(i);
        while(!q2.empty()){
            int cur=q2.front();q2.pop();
            ans[cur]=-1;
            for(auto to: dagList[cur]){
                if(cur == to)continue;
                q2.push(to);
            }
        }




        for(int i=1;i<n;i++) if(comp[i] == comp[0]) ans[ comp[i] ]=-1;


        for(int i=0;i<n;i++) printf("%d ",  ans[ comp[i] ]);
        printf("\n");



	}

	return 0;
}
