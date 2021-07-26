#include <iostream>

using namespace std;
typedef long long ll;
int t;
ll n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);bool can=0;
        for(ll i=1;i<=1e4;i++){
            ll cur=i*i*i;
            if(cur >= n){
                break;
            }
            bool done=0;
            ll st=1, en=1e4;
            while(en >= st){
                ll mid=(st+en)>>1;
                if(mid*mid*mid + cur == n){
                    done=1;
                    break;
                }
                if(mid*mid*mid + cur > n){
                    en=mid-1;
                } else {
                    st=mid+1;
                }
            }
            if(done) can=1;
        }
        if(can) printf("YES\n");else printf("NO\n");
    }
    return 0;
}
