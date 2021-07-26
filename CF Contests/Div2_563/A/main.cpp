#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int ns[10000+9];
int main(){

    scanf("%d", &n);
    n += n;
    ll total=0;

    for(int i=0;i<n;i++){
        scanf("%d", &ns[i]);
        total += ns[i];
    }

    sort(ns,ns+n);

    ll sum=0;
    for(int i=0;i<n/2;i++) sum+=ns[i];

    if(total-sum == sum) return printf("-1\n"), 0;

    for(int i=0;i<n;i++) printf("%d ", ns[i]);

    return 0;
}
