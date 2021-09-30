#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > adjList;
vector<int> inStack, lowLink, dfn;
stack<int> stk;
int ndfn;
int n, m;

/**

    every bridge is not on a cycle!
    then its on a start of a SCC

    in bridges you don't need stack[
        in undirected graphs
    ]

    as whenever you visit any node and it's visited then you're its ancestor


**/


void tarjan(int node, int parent) {

	lowLink[node] = dfn[node] = ndfn++;
//	stk.push(noXde);
	for(int i=0;i<adjList[node].size();i++) {
		int ch = adjList[node][i];
		if (dfn[ch] == -1) {
            tarjan(ch, node);
			lowLink[node] = min(lowLink[node], lowLink[ch]);
            if(lowLink[ch]==dfn[ch]){
                // bridge from node t o ch
                cout << "BRIDGE " << node+1 << " TO " << ch+1 << "\n";
            }


		} else if(ch!=parent)
			lowLink[node] = min(lowLink[node], dfn[ch]);
	}

//	ndfn--;
	/**
    this as above
    if(lowLink[node]==dfn[node] && parent != -1){
        // bridge from parent to node
    }
    **/


}

void scc() {
	int n = adjList.size();

	inStack.clear();	inStack.resize(n);
	lowLink.clear();	lowLink.resize(n);
	dfn.clear();		dfn.resize(n, -1);
	ndfn = 0;
    tarjan(0, -1);
}


int main() {

		cin >> n >> m;
		adjList.clear();
		adjList = vector<vector<int>>(n);

		for(int i=0;i<m;i++) {
			int f, t;
			cin >> f >> t;
			f--, t--;
			adjList[f].push_back(t);
//            adjList[t].push_back(f);

		}

		scc();

		for(int i=0;i<n;i++) cout << i+1 << " " << lowLink[i] << " " << dfn[i] << "\n";

	return 0;
}

