#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX=100000+3;
ll a[MAX];
int N;ll X;
int T;
int main(){
    cin >> T;
    while(T--){
        cin >> N >> X;
        for(int i=1;i<=N;i++){
            scanf("%lld",&a[i]);
            a[i] += a[i-1];
        }
        ll ans=0;
        for(int i=1;i<=N;i++){
            ll pre=a[i-1];
            int idx=lower_bound(a, a+N, X+a[i-1])-a;
            if(a[idx]>=X+a[i-1]) idx--;
            ans += (idx>=i?(idx-i+1):0);
        }
        cout << ans << "\n";
    }
}
