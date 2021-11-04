#include <bits/stdc++.h>

using namespace std;

int cntsrc[26]; // don't forget to memset it but not cnt
int* cnt = cntsrc - 'a'; // so cnt['a'] = cntsrc[0] and so on

pair<string, string> decrypt(string s)
{
	string order;
	reverse(s.begin(), s.end());
	for (auto c : s)
	{
		if (!cnt[c])
			order.push_back(c);
		cnt[c]++;
	}

	int m = order.length();
	int originalLength = 0;
	for (int i = 0; i < m; i++)
		originalLength += cnt[order[i]] / (m - i);

	reverse(order.begin(), order.end());
	return { string(s.rbegin(), s.rbegin() + originalLength), order };
}

string encrypt(pair<string, string> p)
{
	string result = p.first;

	for (auto c : p.second)
	{
		string temp;
		for (auto d : p.first)
			if (d != c)
			{
				temp.push_back(d);
				result.push_back(d);
			}
		p.first = temp;
	}

	return result;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		memset(cntsrc, 0, sizeof(cntsrc));
		string s;
		cin >> s;

		auto ans = decrypt(s);
		auto check = encrypt(ans);

		if (check == s)
			cout << ans.first << ' ' << ans.second << '\n';
		else
			cout << "-1\n";
	}

	return 0;
}
