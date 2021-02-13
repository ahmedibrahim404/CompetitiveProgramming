#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;

void solve(){
	int x, y;
	cin >> x >> y;
	ll res = 0;
	int sq = sqrt(max(x, y)) + 1;
	for(int c = 1; c <= sq; ++c){
		int l = 2, r = y;
		while(l <= r){
			int md = (l + r) / 2;
			if(c * (md + 1LL) <= x && md <= y) l = md + 1;
			else r = md - 1;
		}
		if((l-1) - c <= 0) break;
		res += (l-1) - c;
	}
	cout << res << '\n';
}


int main(){
    cin >> t;
//    t=100;
    while(t--){
        solve();
    }
    return 0;
}
