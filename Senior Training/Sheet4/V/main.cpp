#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, k;
char str[100000+3];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        scanf("%s", str);
        int cnt[n] = {0};
        for(int i=0;i<n;i++){
            cnt[i] = (str[i] == '1');
            if(i) cnt[i] += cnt[i-1];
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            if(str[i] == '0') continue;
            if(i > k){
                ans += cnt[i] - cnt[i-k-1];
            } else {
                ans += cnt[i];
            }
        }

        ll a = ans * 2 - cnt[n-1];
        ll b = 1LL * n * n;
        ll g = __gcd(a, b);
        if(!a){
            printf("0/1\n");
        } else
        printf("%lld/%lld\n", a/g, b/g);
    }
    return 0;
}
