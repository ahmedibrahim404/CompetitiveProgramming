#include<bits/stdc++.h>

using namespace std;

/**

    nodes that if visited the graph components will increase
    leaf nodes are not articulation points
    articulation points doesn't mean that exists an bridge
    but bridge indicates that there is an articulation point [
        if there is bridge (u,v)
            if removed u or v then #components will increase
            then u, v are art. points
    ]


    okay
    note: lowLink[i] means the minimum ancestor of i such i can reach it

    then for edge(u, v)
        if(lowLink[v]>=dfn[u]) (then u) is an art. point
            cuz v can't reach all nodes with dfn less than dfn[u]

        note (condition) if(lowLink[v]>dfn[u]) this detects the bridges not art. points
        but ((>=)) detects the art. points


    now there is a problem
        every time the root is considered articulation point whether it's or not
        how to solve this problem??
    Cases it's not an articulation point:[
        if root is part of 1 biconnected graph
        if root is a leaf node
    ]

    Cases it's an articulation point: [
        if root is part of more than 1 biconnected component
    ]


    if some graph has n articulation points => when splitting it to components will have (n+1) components

**/

/**

    biconnected graph =>>[[
        graph that has no articulation points
            how??
            means at least there is two paths between any two nodes
        1 3 9
        1 2 7 5 9
    ]]

**/

const int MAX=1e5+3;
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi ns;
int dfn[MAX], low[MAX];
int tim=0;

stack< pair<int, int> > component;
bool root=0;
void tarjan(int node=-1, int par=-1){
    dfn[node]=low[node]=tim++;
    int sz=ns[node].size();
    for(int i=0;i<sz;i++){
        int ch=ns[node][i];


        // to get all biconnected graphs
        if(ch!=par && dfn[ch]<dfn[node])
			component.push( make_pair(node, ch) );


        if(dfn[ch]==-1){
            tarjan(ch, node);
            low[node]=min(low[node], low[ch]);

            if(low[ch] >= dfn[node]){


                if(dfn[node]==0&&root==false){
                    root=true;
                } else {
                    cout << "NODE " << node << " IS ARC" << endl;
                }


                // to get biconnected graphs

                pair<int, int> edge;
                int cnt = 0;
				do
				{
					cnt++;
					edge = component.top();
					component.pop();
					cout<<edge.first+1<<" "<<edge.second+1<<"\n";
				}while(edge.first != node || edge.second != ch);

				if(cnt == 1)
					cout<<edge.second+1<<" "<<edge.first+1<<"\n";


            }


0
            if(low[ch] > dfn[node]){
                cout << "BRIDGE FROm " << node << " TO " << ch << endl;
            }

        } else if(ch!=par){
            low[node]=min(low[node], dfn[ch]);
        }
    }

//    if(low[node]==dfn[node]){
//        cout << "BRIDGE FROm " << par << " TO " << node << endl;
//    }

}

int n, m;
int main(){
    scanf("%d%d",&n,&m);
    ns=vvi(n);
    for(int i=0;i<n;i++) dfn[i]=-1;
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        a--, b--;
        ns[a].push_back(b);ns[b].push_back(a);
    }
    tarjan(0, -1);

//    for(int i=0;i<n;i++){
//        cout << i+1 << " " << dfn[i] << " " << low[i] << endl;
//    }

    return 0;
}
