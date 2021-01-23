#include<bits/stdc++.h>
using namespace std;
typedef pair<int, char> pp;
typedef pair<int, int> pi;
typedef vector<pp> vp;
typedef vector<vp> vvp;
const int MAX=200000+3;
int n, m;
int a, b;
char c;
vvp ns;
string no[MAX];
bool vis[MAX];
vector<int> ans;

void bfs(){

    queue<int> q;
    vector<int> par(n), dis(n);
    no[0]="";
    par[0]=-1;
    dis[0]=0;
    q.push(0);
    while(!q.empty()){
        int cur=q.front();q.pop();
        if(vis[cur]) continue;
        vis[cur]=1;
        for(int i=0;i<ns[cur].size();i++){
            int newn=ns[cur][i].first;
            if(vis[newn]){
                if(dis[newn]==dis[cur]+1){
                    if(no[cur]+ns[cur][i].second < no[newn]) no[newn]=no[cur]+ns[cur][i].second, par[newn]=cur;
                }
                continue;
            }
            dis[newn]=dis[cur]+1;
            par[newn]=cur;
            no[newn]=no[cur]+ns[cur][i].second;
            q.push( newn );
        }
    }

    int cur=n-1;
    while(cur!=-1){
        ans.push_back(cur);
        cur=par[cur];

    }


}

int main(){
    scanf("%d%d",&n,&m);
    memset(vis, 0, sizeof vis);
    ns=vvp(n);
    for(int i=0;i<m;i++){
        scanf("%d%d %c", &a,&b,&c);
        a--, b--;
        ns[a].push_back(pp(b, c));
        ns[b].push_back(pp(a, c));
    }

    bfs();

    int sz=ans.size();
    printf("%d\n", sz-1);
    for(int i=sz-1;i>=0;i--){
        printf("%d ", ans[i]+1);
    }
    printf("\n");
    string str=no[n-1];
    int len=str.length();
    for(int i=0;i<len;i++) printf("%c", str[i]);


    return 0;
}
