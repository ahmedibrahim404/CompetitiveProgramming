#include <bits/stdc++.h>
using namespace std;
int x[100001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,i,l=1,r=1,d;
	cin>>n>>d;
	long long s=0;
	for(i=1;i<=n;i++) cin>>x[i];

	for(l=1;l<n-1;l++){

		while(x[l]+d>=x[r]&&r<=n){
			r++;
		}

		s+=(long long)(r-l-2)*(r-l-1)/2;
	}

	cout<<s;
}
