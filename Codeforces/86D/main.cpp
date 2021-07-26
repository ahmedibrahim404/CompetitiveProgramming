#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 200005;
ll qs[N], qe[N], sorted[N], s, e, freq[1000005],a[N], sum, ans[N], x;

void add(int val){
    x = freq[val]++;
    sum += ((2LL*x+1LL)*val);
}

void remove(int val){
    x = --freq[val];
    sum -= ((2LL*x +1L)*val);
}

void mo(int idx){
    while(s > qs[idx]) add(a[--s]);
    while(e < qe[idx]) add(a[e++]);
    while(s < qs[idx]) remove(a[s++]);
    while(e > qe[idx]) remove(a[--e]);
    ans[idx] = sum;
}

int main(){
    int n, t;
    scanf("%d%d",&n,&t);
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);
    for(int i = 0; i < t; i++){
        scanf("%d%d", qs+i, qe+i);
        qs[i]--;
        sorted[i] = i;
    }
    int sq = sqrt(n);
    sort(sorted, sorted + t, [sq](int i, int j){
         return make_pair(qs[i]/sq, qe[i]) < make_pair(qs[j]/sq, qe[j]);
    });
    for(int i = 0; i < t; i++)
        mo(sorted[i]);
    for (int i = 0; i < t; i++)
        printf("%lld\n", ans[i]);
}
