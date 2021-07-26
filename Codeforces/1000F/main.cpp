#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 500002, SQ = 710;
int n,q,a[N],f[N],ans[N],ones[SQ];
struct str {int l,r,i;} Q[N];

inline void add(int i){
    i = a[i];
    if(f[i] == 1) --ones[i/SQ];
    ++f[i];
    if(f[i] == 1) ++ones[i/SQ];
}

inline void remove(int i){
    i = a[i];
    if(f[i] == 1) --ones[i/SQ];
    --f[i];
    if(f[i] == 1) ++ones[i/SQ];
}

int query(){
    for(int i=0;i<SQ;i++) if(ones[i])
        for(int j=i*SQ;i<=1000000000;j++) if(f[j] == 1)
            return j;
    return 0;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        Q[i] = {l, r, i};
    }
    sort(Q+1, Q+1+q, [](str &f, str &s){
        return make_pair(f.l/SQ, f.r) < make_pair(s.l/SQ, s.r);
    });

    int currL = Q[1].l, currR = Q[1].l;
    for(int i=1;i<=q;i++){
        int L = Q[i].l, R = Q[i].r;
        while(currL < L) remove(currL++);
        while(currL > L) add(--currL);
        while(currR <= R) add(currR++);
        while(currR > R+1) remove(--currR);

        ans[Q[i].i] = query();
    }

    for(int i=1;i<=q;i++)printf("%d\n", ans[i]);
}
