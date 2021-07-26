#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef long long ll;

int n, vs[100000+9], a, prt[100000+9];
vvi ns;
bool st=false;
void DFS(int no, int su, int le){

    if(le & 1){

        if(no != 1){

            vs[no] -= su;
            if(vs[no] < 0){
                printf("-1\n");
                st=true;
                return;
            }

        }

    } else {

        int mi=1e9;
        for(int i=0;i<ns[no].size();i++){
            mi=min( vs[ ns[no][i] ]-su, mi );
        }

        if(mi == 1e9) vs[no] = 0;
        else vs[no]=mi;

        if(vs[no] < 0){
                printf("-1\n");
                st=true;
                return;
        }

    }

    for(int i=0;i<ns[no].size();i++){
        DFS(ns[no][i], su+vs[no], le+1);
    }

}

int main(){

    scanf("%d", &n);
    ns = vvi(n+1);
    for(int i=2;i<=n;i++){
        scanf("%d", &a);
        ns[a].push_back(i);
        prt[i]=a;
    }

    for(int i=1;i<=n;i++) scanf("%d", &vs[i]);

    DFS(1, 0, 1);
    if(st) return 0;

    ll res=0;
    for(int i=1;i<=n;i++) res += vs[i];

    printf("%lld", res);

    return 0;
}
