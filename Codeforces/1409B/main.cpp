#include <iostream>

using namespace std;
typedef long long ll;
int t;ll n, a, b, x, y;
int main(){
    cin >> t;
    while(t--){
        cin >> a >> b >> x >> y >> n;
        if(a > b){
            swap(a, b);
            swap(x, y);
        }
        ll pn=n, pa=a, pb=b;

        ll mi=min(b-y, n);
        b -= mi; n-= mi;

        mi=min(a-x, n);
        a -= mi; n-= mi;

        ll ans=a*b;

        b=pb;a=pa;
        n=pn;


        mi=min(a-x, n);
        a -= mi; n-= mi;
        mi=min(b-y, n);
        b -= mi; n-= mi;

        cout << min(ans, a*b) << "\n";

    }
    return 0;
}
