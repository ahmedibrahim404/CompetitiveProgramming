#include <bits/stdc++.h>

using namespace std;

vector<int> s[1005],e[1005];
int n,m;
int gr[1005][1005];

int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&gr[i][j]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			s[i].push_back(gr[i][j]);
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			e[i].push_back(gr[j][i]);
	for(int i=0;i<n;i++)
	{
		sort(s[i].begin(),s[i].end());
		s[i].erase(unique(s[i].begin(),s[i].end()),s[i].end());
	}
	for(int i=0;i<m;i++)
	{
		sort(e[i].begin(),e[i].end());
		e[i].erase(unique(e[i].begin(),e[i].end()),e[i].end());
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x=lower_bound(s[i].begin(),s[i].end(),gr[i][j])-s[i].begin();
			int y=lower_bound(e[j].begin(),e[j].end(),gr[i][j])-e[j].begin();
			printf("%d%c",max(x,y)+max(s[i].size()-x,e[j].size()-y)," \n"[j==m-1]);
		}
	}
}
