#include<bits/stdc++.h>

using namespace std;
int t, n;
typedef long long ll;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ll vec[n];
        for(int i=0;i<n;i++){
            scanf("%lld",&vec[i]);
        }
        sort(vec, vec+n);
        ll needed = 0; // to max
        for(int i = n - 1; i > 0; --i) needed += vec[n - 1] - vec[i];
        ll res = 0;
        if(needed > vec[0]) res += needed - vec[0];
        else res += ((n - 1) - (vec[0] - needed) % (n - 1)) % (n - 1);
        printf("%lld\n", res);

    }
    return 0;
}
