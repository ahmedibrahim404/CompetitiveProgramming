#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1<<20;

int a[N], qs[N], qe[N], qi[N],freq[N], n, q, sq, s, e,k;
ll ans[N],ansL;

void add(int val){
   ansL+=freq[val^k];
   freq[val]++;
}
void del(int val){
    freq[val]--;
    ansL-=freq[val^k];
}

void update(int idx){
    while (e < qe[idx] + 1) add(a[e++]);
    while (s > qs[idx]) add(a[--s]);
    while (s < qs[idx]) del(a[s++]);
    while (e > qe[idx] + 1) del(a[--e]);
}

int32_t main() {
    cin>>n>>q>>k;
    for (int i = 1; i <= n; ++i) cin>>a[i],a[i]^=a[i-1];
    for (int i = 0; i < q; ++i) {
        cin>>qs[i]>>qe[i];
        --qs[i];
        qi[i]=i;
    }
    sq = sqrt(n);
    sort(qi, qi + q, [](int a, int b){
        return make_pair(qs[a] / sq, qe[a]) < make_pair(qs[b] / sq, qe[b]);
    });
    for (int i = 0; i < q; ++i){
        update(qi[i]);
        ans[qi[i]] = ansL;
    }
    for (int i = 0; i < q; ++i) {
        cout<<ans[i]<<endl;
    }
}
