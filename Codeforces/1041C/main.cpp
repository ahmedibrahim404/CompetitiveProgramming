#include<bits/stdc++.h>
using namespace std;
int n,d,k=1,i,x,b[222000];
map<int,int> a;

int main(){
	for(cin>>n>>d>>d,i=1;i<=n;i++)cin>>x,a[x]=i;
	while(!a.empty()){
		for(auto i=a.begin();i!=a.end();){
			b[i->second]=k;
			x=i->first;
			a.erase(i);
			i=a.lower_bound(x+d+1);
		}
		k++;
	}
	cout<<k-1<<endl;
	for(i=1;i<=n;i++)cout<<b[i]<<" ";
}
