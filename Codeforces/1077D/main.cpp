#include<bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, k, a[N], vis[N];
vector< pair<int, int> > ans;
int main() {
	cin>>n>>k;
	for (int i = 0; i < n; i++) {
		cin>>a[i];
		vis[a[i]]++;
	}
	for (int i=0; i<N; i++) {
		for (int j = 1; j <= vis[i]; j++) {
            ans.push_back({vis[i]/j,i});
		}
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());

	for (int i=0; i<k; i++) {
		printf("%d ", ans[i].second);
	}
return 0;
}
