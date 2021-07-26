#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a, b;
map<ll, int> cnt;
int main(){
    while(scanf("%lld",&n)==1){
        if(!n) break;
        scanf("%lld %lld",&a,&b);
        ll took=0;
        ll cur=b;
        cnt.clear();
        while(true){
            cnt[cur]++;
            if(cnt[cur]==2)took++;
            else if(cnt[cur]==3) break;
            cur = ((((cur*cur)%n)*a)%n + b%n)%n;
        }
        printf("%lld\n", n-took);
    }

    return 0;
}
