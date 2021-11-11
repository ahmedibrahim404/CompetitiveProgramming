#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 100000 + 3;
ll ns[N];
ll a[N];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<n;i++) {
        ll num;
        scanf("%lld",&num);
        ns[i] = (num-a[i])*(num-a[i]);
        if(i) ns[i] += ns[i-1];
    }
    int q;scanf("%d",&q);
    while(q--){
        int i, j;scanf("%d%d",&i,&j);
        i--, j--;
        ll cur = ns[j] - (i ? ns[i-1] : 0);
        printf("%.12f\n", 1.0*sqrt(cur));
    }
    return 0;
}
