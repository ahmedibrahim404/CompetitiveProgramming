#include <iostream>

using namespace std;
typedef long long ll;
int t;ll n, k ;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        if(n > k){
            ll st=1, en=1e9;
            while(en >= st){
                ll mid=(st+en)/2;
                if(k*mid >= n) en=mid-1;
                else st=mid+1;
            }
            k *= (en+1);
        }

        cout << (k+n-1)/n << "\n";

    }
    return 0;
}
