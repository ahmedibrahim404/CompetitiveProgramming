#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
const int MAX=100+3;
int n;
vvi ns;

pi bfs(int node){

    queue<int> q;
    q.push(node);
    int dis[MAX];
    for(int i=0;i<n;i++) dis[i]=-1;
    dis[node]=0;int mx=0, noo=node;
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int to: ns[cur]){
            if(dis[cur] + 1 > dis[to]){
                dis[to]=dis[cur]+1;
                q.push(to);
            }
            if(dis[to] > mx) mx=dis[to], noo=to;
        }
    }

    return {mx, noo};

}
int src, Case=0;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    while(cin >> n){
        if(!n) break;
        scanf("%d", &src);
        ns=vvi(n);
        int a, b;
        while(cin >> a >> b) {
            if(!a && !b) break;
            a--, b--;
            ns[a].push_back(b);

        }
        pi ans=bfs(src-1);
//		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++Case, src, ans.first, ans.second+1);
        cout << "Case "<<++Case<<": The longest path from "<<src<<" has length "<<ans.first<<", finishing at "<< ans.second + 1<< ".\n\n";
    }
    return 0;
}
