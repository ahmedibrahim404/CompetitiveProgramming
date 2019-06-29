#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]<0) a[i] = -a[i];
	}
	sort(a,a+n);
	long long ans = 0;
	for(int i=0;i<n;i++){
		ans += upper_bound(a,a+n,2*a[i])-a-1-i;
	}
	printf("%lld",ans);
}
