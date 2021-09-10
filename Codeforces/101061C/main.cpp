#include <iostream>

using namespace std;
typedef long long ll;
const int N = 100+3;


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, m;
        scanf("%d%d",&n,&m);
        ll ns[n][n];
        ll has[n][n];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) ns[i][j]=1e9, has[i][j]=1e9;
        for(int i=0;i<n;i++) ns[i][i]=0;
        for(int i=0;i<m;i++){
            int a, b, d; ll c;
            scanf("%d%d%lld%d",&a,&b,&c,&d);a--, b--;
            if(d == 1 && ns[a][b] != 1e9){
                if(has[a][b] == 0) continue;
                ns[a][b]=min(ns[a][b], c);
                has[a][b]=min(has[a][b], c);
                ns[b][a]=min(ns[b][a], c);
                has[b][a]=min(has[b][a], c);
                continue;
            }
            if(d == 2 && has[a][b] > 0){
                ns[a][b] = ns[b][a] = c;
                has[a][b] = has[b][a] = 0;
                continue;
            }
            ns[a][b]=min(ns[a][b], c);
            ns[b][a]=min(ns[b][a], c);
            if(d == 1) has[b][a] = c, has[a][b] = c;
            else has[b][a] = has[a][b]=0;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(ns[i][k] == 1e9 || ns[k][j] == 1e9) continue;
                    if((has[i][j] > has[i][k] + has[k][j])){
                        has[i][j] = has[i][k] + has[k][j];
                        ns[i][j] = ns[i][k] + ns[k][j];
                    } else if(has[i][j] == has[i][k] + has[k][j]) ns[i][j] = min(ns[i][j], ns[i][k] + ns[k][j]);
                }
            }
        }

        int a, b;
        scanf("%d%d",&a,&b);a--, b--;
        if(ns[a][b] == 1e9) printf("-1\n");
        else {
            printf("%lld %lld\n", has[a][b], ns[a][b]);
        }



    }
    return 0;
}
