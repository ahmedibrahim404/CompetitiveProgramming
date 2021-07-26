#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
const int MAX=200000+3;
int n, q, no;
vvi ns;
vi ans;
pi st[MAX];
void dfs(int node=0){
    st[node].first=ans.size();
    ans.push_back(node);
    for(int child: ns[node]){
        dfs(child);
    }
    st[node].second=ans.size()-1;
}

int main(){
    scanf("%d%d",&n,&q);
    ns=vvi(n);

    for(int i=1;i<n;i++){
        scanf("%d",&no);
        no--;
        ns[no].push_back(i);
    }

    dfs(0);
    int a, b;
    while(q--){
        scanf("%d%d",&a,&b);
        a--;
        int start=st[a].first, en=st[a].second;
        if(en-start+1 >= b){
            printf("%d\n", ans[start+b-1]+1);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}
