#include <iostream>

using namespace std;
typedef long long ll;
ll n, m, k;
string s;
int main(){
	cin >> s;
	int l = -1, r = -1;
	for(int i = 0 ; i < s.length() ;i++)
		if(l == -1 && s[i] == '[')
			l = i;
		else if(s[i] == ']')
			r = i;
	if(l == -1 || r == -1)
		return cout << -1, 0;
	n = m = -1;
	for(int i = l + 1; i < r ;i++)
		if(~n && s[i] == ':')
			m = i;
		else if(n == -1 && s[i] == ':')
			n = i;
	if(n == -1 || m == -1)
		return cout << -1, 0;
	for(int i = n + 1; i < m ; i++)
		if(s[i] == '|')
			k++;
	cout << k + 4;
	return 0;
}
