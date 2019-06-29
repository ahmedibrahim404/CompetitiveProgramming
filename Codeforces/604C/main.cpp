#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans=1;
	string s;
	cin>>n>>s;
	for(int i=1; i<s.length(); i++)
	{
		if(s[i]!=s[i-1])
			ans++;
	}
	cout<<min(ans+2,n);
	return 0;
}
