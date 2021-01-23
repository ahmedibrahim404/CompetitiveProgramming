#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef pair<pi, int> ppi;
typedef vector<ppi> vpi;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int MAX=2000+1;
int N, T;
vpi ns;
vvi ps;
vector<pi> vcnt;
bool vis[MAX];
bool isin(int i, int j){
    int x1=ns[i].first.first, y1=ns[i].first.second;
    int x2=ns[j].first.first, y2=ns[j].first.second;
    int d=ns[i].second/2;
    return (x1>=x2-d && x1<=x2+d) && (y1 >= y2 - d && y1 <= y2 + d);
}

int cur=0;
void dfs(int node){

    if(vis[node]) return;
    cur++;
    vis[node]=1;
    for(int i=0;i<ps[node].size();i++){
        dfs(ps[node][i]);
    }

}


int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        ns=vpi(N);
        ps=vvi(N);
        vcnt=vector<pi>(N);
        for(int i=0;i<N;i++) scanf("%d%d%d",&ns[i].first.first,&ns[i].first.second,&ns[i].second);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(isin(i, j)){
                    ps[i].push_back(j);
                }
            }
        }

        for(int i=0;i<N;i++){
            memset(vis, 0, sizeof vis);
            cur=0;
            dfs(i);
            vcnt.push_back({cur, i});
        }

        sort(vcnt.begin(), vcnt.end(), greater<pi>());
        memset(vis, 0, sizeof vis);
        int cnt=0;
        for(int i=0;i<N;i++){
            if(vis[ vcnt[i].second ])continue;
            dfs(vcnt[i].second);
            cnt++;
        }


        printf("%d\n", cnt);

    }
    return 0;
}
