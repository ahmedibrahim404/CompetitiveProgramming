#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
  ll t, n, a; cin >> t;
  while (t--) {
    scanf("%lld", &n);
    map<ll, ll> m;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
      scanf("%lld", &a);
      m[a]++;
      if(m[a] >= 2) { v.push_back(a); m[a]-=2; }
    }
    sort(v.begin(), v.end());

    long double diff=1e8;
    ll d1, d2;

    for(int i=1;i<v.size();i++){
        if( (double) (4*v[i]/v[i-1])+ (double)(4*v[i-1]/v[i]) < diff ){
            diff=(double) (4*v[i]/v[i-1])+ (double) (4*v[i-1]/v[i]), d1=v[i], d2=v[i-1];
            cout << diff << endl;
        }
    }

    cout << d1 << " " << d1 << " " << d2 << " " << d2 << endl;

  }
}
