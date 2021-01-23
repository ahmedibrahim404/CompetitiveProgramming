#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > adjList;
vector<int> inStack, lowLink, dfn;
stack<int> stk;
int ndfn;
int n, m, x, y, cnt=0;

bool tarjan(int node, int parent) {


	lowLink[node] = dfn[node] = ndfn++, inStack[node] = 1;
	stk.push(node);
    if(node==y){
        return 1;
    }
    bool wether=0;
	for(int i=0;i<adjList[node].size();i++) {
		int ch = adjList[node][i];
		if(ch==parent) continue;
		if (dfn[ch] == -1) {
			bool is=tarjan(ch, node);
			if(is) wether=1;
			lowLink[node] = min(lowLink[node], lowLink[ch]);

            if(lowLink[ch]==dfn[ch] && is){
                cnt++;
            }

		} else if (inStack[ch])
			lowLink[node] = min(lowLink[node], dfn[ch]);
	}

    return wether;

}

void scc() {
	int n = adjList.size();

	inStack.clear();	inStack.resize(n);
	lowLink.clear();	lowLink.resize(n);
	dfn.clear();		dfn.resize(n, -1);
	ndfn = 0;
    tarjan(x, -1);
}


int main() {


		cin >> n >> m;
		cin >>x >> y;
		x--, y--;
		adjList.clear();
		adjList = vector<vector<int>>(n);

		for(int i=0;i<m;i++) {
			int f, t;
			cin >> f >> t;
			f--, t--;
			adjList[f].push_back(t);
            adjList[t].push_back(f);

		}

		scc();
        cout << cnt;

	return 0;
}
