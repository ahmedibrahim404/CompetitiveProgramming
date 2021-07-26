#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 250'000 + 3, SQ = 500 + 5;
int sq, ns[N], n;


struct bit {

    int tree[N];
    void init(){
        memset(tree, 0, sizeof tree);
    }

    ll get(int i){
        ll ret=0;
        for(; i ; i -= (i&(-i))){
            ret += 1LL*tree[i];
        }
        return ret;
    }

    void add(int i, ll val){
        for(;i < N ;i += (i&(-i))){
            tree[i] += val;
        }
    }


} bit;

struct bit2D {

    int tree[SQ][N];

    void init(){
        memset(tree, 0, sizeof tree);
    }

    ll get(int i, int j){
        ll ret=0;
        for(; i ; i -= (i&(-i))){
            for(int jj = j; jj; jj -= (jj & (-jj))){
                ret += tree[i][jj];
            }
        }
        return ret;
    }

    void add(int i, int j, ll val){
        ll ret=0;
        for(; i < SQ; i += (i&(-i))){
            for(int jj = j; jj < N; jj += (jj & (-jj))){
                tree[i][jj] += val;
            }
        }
    }


} bit2;

ll calcInv(int x){

    int bl=(x+sq-1)/sq;

    ll ret=bit2.get(bl-1, N-1) - bit2.get(bl-1, ns[x]) + bit2.get(sq, ns[x]-1) - bit2.get(bl, ns[x] - 1);

    int st = (bl-1) * sq + 1;
    int en = min(n+1, st + sq);

    for(int i=st;i<en;i++){

        if(i == x) continue;
        if(i > x){
            ret += ns[i] < ns[x];
        } else {
            ret += ns[i] > ns[x];
        }

    }

    return ret;


}



int main(){

    ll ans=0;

    scanf("%d",&n);

    sq=ceil(sqrt((double)(n) + 1e-9));

    bit.init();
    bit2.init();

    for(int i=1;i<=n;i++){
        scanf("%d", &ns[i]);
        ans +=  ((i-1) - bit.get(ns[i]));
        bit.add(ns[i], 1);
        bit2.add((i+sq-1)/sq, ns[i], 1);
    }

    int q, x, y;

    scanf("%d",&q);
    while(q--){

        scanf("%d%d",&x,&y);

        ans -= calcInv(x);
        bit2.add((x+sq-1)/sq, ns[x], -1);

        ns[x]=y;

        bit2.add((x+sq-1)/sq, ns[x], 1);
        ans += calcInv(x);

        printf("%lld\n", ans);
    }


    return 0;
}
