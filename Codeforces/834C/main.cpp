#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long x,y;
		scanf("%I64d %I64d",&x,&y);
		long long z=ceil(pow(x*y,1.0/3));
		if(z*z*z==x*y&&x%z==0&&y%z==0)
			printf("Yes\n");
		else
			printf("No\n");
	}
}
