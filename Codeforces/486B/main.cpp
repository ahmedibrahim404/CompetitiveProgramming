#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
int n, m, no, ns[100+3][100+3];
vpi zs, on;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) ns[i][j]=-1;
    bool st=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&no);
            if(no==0) zs.push_back({i, j}), ns[i][j]=0;
            else on.push_back({i, j});
        }
    }
    for(int i=0;i<zs.size();i++){
        int fir=zs[i].first, sec=zs[i].second;
        bool c=0;
        for(int k=0;k<m;k++) if(ns[fir][k]==1) c=1; else ns[fir][k]=0;
        for(int k=0;k<n;k++) if(ns[k][sec]==1) c=1; else ns[k][sec]=0;
        if(c) return printf("NO"), 0;
    }
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(ns[i][j]==-1) ns[i][j]=1;
    for(int i=0;i<on.size();i++){
        int fir=on[i].first, sec=on[i].second;
        bool c=0;
        for(int k=0;k<m;k++) if(ns[fir][k]==1) c=1;
        for(int k=0;k<n;k++) if(ns[k][sec]==1) c=1;
        if(!c) return printf("NO\n"), 0;
    }
    printf("YES\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) printf("%d ", ns[i][j]);
        printf("\n");
    }
    return 0;
}
