#include <iostream>

using namespace std;
typedef long long ll;
const int N=300+1;
const ll INF=1e18;
ll cost[N][N], mem[N][N], n;
ll solve(int l, int k) {
	if (k <= 0)return 0;
	if (l == n + 1)return INF;
	ll& rt = mem[l][k];
	if (~rt)return rt;
	rt = solve(l + 1, k);
	for (int r = l; r <= n; r++)
		rt = min(rt, solve(r + 1, k - (r - l + 1)) + cost[l][r]);
	return rt;
}

int main() {
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cost[i][j]=INF, mem[i][j]=-1;
	int m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int l, r; ll c;
		cin >> l >> r >> c;
		for (int j = l; j <= r; j++)
			cost[j][r] = min(cost[j][r], c);
	}
	for (int l = 1; l <= n; l++)
		for (int r = n - 1; r > 0; r--)
			cost[l][r] = min(cost[l][r], cost[l][r + 1]);
	ll ans =  solve(1, k);
	if (ans == INF)
		ans = -1;
	cout << ans;
}

