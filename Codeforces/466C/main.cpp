#include<bits/stdc++.h>
using namespace std;
const int MAX=5e5+3;
typedef long long ll;
int n;
ll ns[MAX];
int main(){
    scanf("%d",&n);
    map<ll, int> cnt;
    for(int i=0;i<n;i++){
        scanf("%lld",&ns[i]);
        if(i) ns[i] += ns[i-1];
        if(i!=n-1)cnt[ns[i]]++;
    }


    ll ways=0;
    for(int i=0;i<n-1;i++){
        cnt[ ns[i] ]--;
        if(ns[n-1]-ns[i]==2*ns[i]){
            ways += cnt[ ns[i]*2 ];
        }
    }

    printf("%lld",ways);

    return 0;
}
