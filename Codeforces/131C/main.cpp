#include <iostream>

using namespace std;

typedef long long ll;

int n, m, t;
ll ans;

ll C( int n, int k ){
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    ll result = n;

    for( int i = 2; i <= k; ++i ){
        result *= (n-i+1);
        result /= i;
    }

    return result;
}

int main(){

    cin >> n >> m >> t;

    for(int i=4;i<=n && (t-i) >= 1;i++){
        ans += C(n, i) * C(m, t-i);
    }

    cout << ans << endl;
    return 0;
}
