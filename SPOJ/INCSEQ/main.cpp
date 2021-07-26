#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
const int N = 100000 + 5, K = 50 + 1;const ll MOD=5'000'000;
struct bit2D {

    ll tree[N + 5][K + 5];

    void init(){
        memset(tree, 0, sizeof tree);
    }

    ll get(int i, int j){
        ll ret=0;
        for(; i ; i -= (i&(-i))){
            ret = (ret+tree[i][j])%MOD;
        }
        return ret;
    }

    void add(int i, int j, ll val){
        for(; i < N; i += (i&(-i))){
            tree[i][j] = (tree[i][j]+val)%MOD;
        }
    }


} bit2;


int main(){
    scanf("%d%d",&n,&k);
    bit2.init();
    for(int i=0;i<n;i++){
        ll no;
        scanf("%lld",&no);
        no++;
        for(int j=1;j<=k;j++){
            ll toadd = bit2.get(no-1, j-1);
            toadd %= (MOD);
            bit2.add(no, j, toadd);
        }
        bit2.add(no, 1, 1);
    }

    printf("%lld\n", (bit2.get(N, k))%MOD);
    return 0;
}
