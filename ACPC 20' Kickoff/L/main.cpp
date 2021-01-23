#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int MAX=100000+3;
int T, N, a, b;
bool is[MAX], vis[MAX];
vvi ns;
int par[MAX];
void bfs(){
    queue<int> q;
    q.push(0);
    par[0]=-1;
    vector<bool> vis(N);
    while(!q.empty()){
        int no=q.front();q.pop();
        if(vis[no]) continue;
        vis[no]=1;
        int sz=ns[no].size();
        for(int i=0;i<sz;i++){
            int to=ns[no][i];
            if(vis[to]) continue;
            par[to]=no;
            q.push(to);
        }
    }

}

int main(){
//    freopen("tree.in", "r", stdin);
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        ns=vvi(N);
        for(int i=0;i<N;i++) cin >> is[i], vis[i]=0;

        for(int i=0;i<N-1;i++){
            cin >> a >> b;
            a--, b--;
            ns[a].push_back(b);
            ns[b].push_back(a);
        }

        int leaf=0;
        bfs();
        for(int i=0;i<N;i++){
            if(ns[i].size()==1){
                if(!is[i]){
                    leaf++;
                    int cur=i;
                    while(cur != -1 && !vis[cur]){
                        vis[cur]=1;
                        cur=par[cur];
                    }
                }
            }
        }

        for(int i=0;i<N;i++){
            if(ns[i].size()==1){
                bool add=0;
                if(!vis[i]){
                    int cur=i;
                    while(cur != -1 && !vis[cur]){
                        if(!add && !is[cur]){
                            add=1;
                            leaf++;
                        }
                        vis[cur]=1;
                        cur=par[cur];
                    }
                }
            }
        }

        printf("%d\n", (leaf+1)/2);
    }
    return 0;
}
