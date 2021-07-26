#include <iostream>

using namespace std;
typedef long long ll;
ll n, m, k, no;
int main(){
    scanf("%lld %lld %lld",&n,&m,&k);
    ll cur=1, cnt=0, total=0, o=0;
    bool ret=0;
    for(int i=0;i<m;i++){
        scanf("%lld", &no);
        if( (no-total) <= cur*k ){
            cnt++;
        } else {
            total += cnt;
            if(cnt!=0)o++;
            cur=((no-total)/k)+((no-total)%k!=0);
            cnt=0;
            if( (no-total) <= cur*k ){
                cnt++;
            }
        }
    }
    if(cnt) o++;
    printf("%lld", o);
    return 0;
}
