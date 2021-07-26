#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> ans;
vector<vector<int>>v(1e5 + 9);
int main()
{
	int n,x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		v[x].push_back(i);
	}
	bool valid = true;
	for (int i = 0; i <= 1e5; i++)
	{
		valid = true;
		if (v[i].size() == 0)
			continue;
		else if (
           v[i].size() == 1)
			ans.push_back({ i,0 });
		else if (v[i].size() == 2)
			ans.push_back({ i,v[i][1] - v[i][0] });
		else
		{
			for (int j = 2; j < v[i].size()&&valid; j++)
			{
				if (v[i][j] - v[i][j - 1] != v[i][j - 1] - v[i][j - 2])
					valid = false;
			}
			if (valid)
			{
				ans.push_back({ i,v[i][1] - v[i][0] });
			}
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}
