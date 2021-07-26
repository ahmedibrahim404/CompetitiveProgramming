#include <iostream>

using namespace std;
typedef long long ll;
ll n;

ll can(ll no){

    ll now=n;
    ll eat=0;
    while(now){
        eat += min(no, now);
        now -= min(no, now);

        ll re=now/10;
        now -= re;
    }

    return eat;

}

int main(){
    scanf("%lld", &n);
    ll st=1, en=n;

    ll ans=1e18;
    for(int j=0;j<60 && en >= st;j++){
        ll mid=(st+en)>>1;
        ll aa=can(mid);
        if( aa >= ((n+(n&1))/2) ) en=mid-1, ans=min(ans, mid);
        else st=mid+1;
    }

    printf("%lld", ans);

    return 0;
}
