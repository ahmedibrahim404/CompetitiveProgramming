#include<bits/stdc++.h>
#define ll long long

using namespace std;
int n,arr[1004],ans,cnt;
int h[200004];
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=0;i<n;i++)
	cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		//cnt=0;
		for(int j=i+1;j<n;j++)
		{
			h[arr[i]+arr[j]]++;
		}
	}
	sort(h,h+200004);
	cout<<h[200003];
	return 0;
}
