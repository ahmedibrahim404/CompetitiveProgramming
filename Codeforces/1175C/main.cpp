#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int t,n,k,i,x,y,mini,minpos;
	long long int a[300000];
	cin>>t;
	for(;t>0;t--){
		cin>>n>>k;
		for(i=0;i<n;i++)
			cin>>a[i];
		mini=0;
		minpos=0;
		for(i=0;i<n-k;i++){
			x=a[i+k]-a[i];
			y=(a[i+k]+a[i])/2;
			if(x<mini || i==0){
				mini=x;
				minpos=y;
			}
		}
		cout<<minpos<<endl;
	}
}
