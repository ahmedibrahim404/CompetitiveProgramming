#include<bits/stdc++.h>
using namespace std;
string a,b;
int ans,dem;
int main()
{
	cin>>a>>b;
	for(int i=0;i<b.size();i++) if(a[i]!=b[i])dem++;
	if(dem%2==0)ans++;
	for(int i=b.size();i<a.size();i++){
		if(a[i]!=a[i-b.size()])dem++;
		if(dem%2==0) ans++;
	}
	cout<<ans;
}