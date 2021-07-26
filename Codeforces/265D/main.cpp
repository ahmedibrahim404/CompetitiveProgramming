#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, x, ans, cnt[100009];
vector<int> v[100009];
int main()
{
	IO
	for(int i = 2; i <= 100000; i++)
		if(v[i].empty())
			for(int j = i; j <= 100000; j += i)
				v[j].push_back(i);
	cin >> n;
	while(n--)
	{
		cin >> x;
		int mx = 1;
		for(auto i : v[x]){
            cout << i << " " << x << endl;
            mx = max(mx, cnt[i] + 1);
        }
		for(auto i : v[x])
			cnt[i] = max(cnt[i], mx);
		ans = max(ans, mx);
	}
	cout << ans;
	return 0;
}
