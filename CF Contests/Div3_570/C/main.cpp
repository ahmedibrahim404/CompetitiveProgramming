#include <iostream>

using namespace std;
typedef long long ll;
ll q, k, n, a, b;
ll res;
bool can(ll no){
    res=1LL*no*a+1LL*(n-no)*b;
    if(res < k)return 1;
    return 0;
}

int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%lld %lld %lld %lld", &k, &n, &a, &b);

        ll st=0, en=n;
        ll ans=-1;
        for(int i=0;i<32;i++){
            ll mid=(st+en)>>1;
            if(can(mid)){
                st=mid+1;
                ans=max(ans, mid);
            } else {
                en=mid-1;
            }
        }

        printf("%lld\n",ans);


    }
    return 0;
}
