#include <iostream>

using namespace std;
typedef long long ll;
ll t, x0, x1, x2, y0, y1, y2;
int main(){
    cin >> t;
    while(t--){
        ll ans=0;
        cin >> x0 >> x1 >> x2;
        cin >> y0 >> y1 >> y2;
        ll mi=min(x1, y0);
        x1 -= mi, y0 -= mi;
        mi = min(x0, y2);
        x0 -= mi, y2 -= mi;
        mi = min(x2, y1);
        x2 -= mi, y1 -= mi;
        ans += mi * 2;
        mi =min(x1, y1);
        x1 -= mi, y1-=mi;
        mi=min(x1, y2);
        ans -= mi*2;
        cout << ans << "\n";
    }
    return 0;
}
