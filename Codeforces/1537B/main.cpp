#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t;

ll dis(int x, int y, int i, int j){
    return abs(x-i) + abs(y-j);
}

int main(){
    ll n, m, i, j;
    cin >> t;
    while(t--){
        cin >> n >> m >> i >> j;

        vector<pair<ll,int>> vi;
        vi.push_back({ dis(n, m, i, j), 1 });
        vi.push_back({ dis(1, m, i, j), 2 });
        vi.push_back({ dis(n, 1, i, j), 3 });
        vi.push_back({ dis(1, 1, i, j), 4 });

        sort(vi.begin(), vi.end(), greater<pair<ll, int>>());

        ll x1, y1, x2, y2;
        if(vi[0].second == 1) x1=n, y1=m, x2=1, y2=1;
        if(vi[0].second == 2) x1=1, y1=m, x2=n, y2=1;
        if(vi[0].second == 3) x1=n, y1=1, x2=1, y2=m;
        if(vi[0].second == 4) x1=1, y1=1, x2=n, y2=m;


        printf("%lld %lld %lld %lld\n", x1, y1, x2, y2);


    }
    return 0;
}
