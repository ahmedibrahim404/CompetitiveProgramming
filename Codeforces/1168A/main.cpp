#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005],l,r,mid;

bool check(int x){
	int mx=0;
	for(int i=1;i<=n;i++){
		if(mx>a[i]&&mx-a[i]<=x)continue;
		if(mx<a[i]&&m-a[i]+mx<=x)continue;
		if(mx-a[i]>x)return 0;
		mx=max(mx,a[i]);
	}
	return 1;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	l=-1;r=m-1;
	while(l<r-1){
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}printf("%d\n",r);
	return 0;
}
