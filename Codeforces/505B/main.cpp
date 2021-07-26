#include<bits/stdc++.h>

using namespace std;

int arr[105][105][105];

int main() {
	int n,m;

	cin>>n>>m;
	int a,b,x;
	while(m--)
	{
		cin>>a>>b>>x;
		arr[a][b][x]=1;
		arr[b][a][x]=1;
	}

	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int c=1;c<=100;c++)
					if(arr[i][k][c] && arr[k][j][c])
						arr[i][j][c] = 1;
	int q;
	cin>>q;
	while(q--)
	{
		cin>>a>>b;
		int count=0;
		for(int i=1;i<=100;++i)
		{
			if(arr[a][b][i])
				count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
