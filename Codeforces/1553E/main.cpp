#include <bits/stdc++.h>

using namespace std;

int cycle_count(vector<int> q, int n){
 	for(int i = 0; i < n; i++)
 		q[i]--;
 	vector<int> used(n);
 	int ans = 0;
 	for(int i = 0; i < n; i++){
 		if(used[i] == 1) continue;
 		int j = i;
 		while(used[j] == 0)
 		{
 		 	used[j] = 1;
 		 	j = q[j];
 		}
 		ans++;
 	}
 	return ans;
}

bool check(int n, int m, int k, vector<int> p){
 	vector<int> q;
 	for(int i = k; i < n; i++)
 		q.push_back(p[i]);
 	for(int i = 0; i < k; i++)
 		q.push_back(p[i]);
 	return n - cycle_count(q, n) <= m;
}

void solve()
{
 	int n, m;
 	scanf("%d %d", &n, &m);
 	vector<int> p(n);
 	for(int i = 0; i < n; i++)
 		scanf("%d", &p[i]);
 	vector<int> cnt(n);
 	for(int i = 0; i < n; i++){
 	 	int offset = i + 1 - p[i];
 	 	if(offset < 0)
 	 		offset += n;
 	 	cnt[offset]++;
 	}
 	vector<int> ans;
 	for(int i = 0; i < n; i++){
 		if(cnt[i] + 2 * m >= n && check(n, m, i, p))
 			ans.push_back(i);
    }
 	printf("%d", ans.size());
 	for(auto x : ans) printf(" %d", x);
 	puts("");

}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		solve();
	}
}
