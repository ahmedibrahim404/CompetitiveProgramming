#include <iostream>

using namespace std;
typedef long long ll;
int t;
ll a,b,c,n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
        ll mx=max(a, max(b, c));
        ll rem=n-((mx-a)+(mx-b)+(mx-c));
        if(rem>=0 && rem%3==0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
