#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;cin >> n;
        vector<ll> a;
        for(int i=0;i<n;i++){
            ll num;cin >> num;
            a.push_back(num);
        }
        sort(a.begin(), a.end());
        ll sum = 0;
        ll ans = a[0];
        for(int i=1;i<a.size();i++){
            ans = max(ans, a[i] + sum - a[i-1]);
            sum += -a[i];
            a[i] += sum;
        }
        cout << ans << endl;
    }
    return 0;
}
