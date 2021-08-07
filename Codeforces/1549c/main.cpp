#include<bits/stdc++.h>
using namespace std;
const int N = 200000 + 3;
int n, m;;
set<int> st[N];
int main(){
    scanf("%d%d",&n,&m);int sz[n];bool rem[n];
    for(int i=0;i<n;i++) sz[i]=0, rem[i]=0;
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        a--, b--;
        if(b != 0)st[a].insert(b), sz[a]++;
        if(a != 0)st[b].insert(a), sz[b]++;
    }

    int cnt=0;

    int q;scanf("%d",&q);
    while(q--){
        int ty;
        scanf("%d",&ty);
        if(ty == 3){
            printf("%d\n", cnt);
        } else {
            int a, b;
            scanf("%d%d",&a,&b);
            a--, b--;
            if(ty == 1){
                st[a].insert(b);
                st[b].insert(a);
                if(rem[a] && *st[a].begin() < a) rem[a]=0, cnt--;
                if(rem[b] && *st[b].begin() < a) rem[a]=0, cnt--;
            } else {
                st[a].erase( st[a].find(b) );
                st[b].erase( st[b].find(a) );
                if(!rem[a] && st[a].size() && *st[a].begin() > a) rem[a]=1, cnt++;
                if(!rem[b] && st[b].size() && *st[b].begin() > b) rem[b]=1, cnt++;
            }
        }
    }


    return 0;
}
