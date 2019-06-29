#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005];
int n,k,A,B;
ll dfs(int l,int r)
{
	int m=lower_bound(a,a+k,r+1)-lower_bound(a,a+k,l);
	if(m==0) return A;
	ll ans=(ll)B*(r-l+1)*m;
	if(r!=l)
	{
		int mid=(l+r)>>1;
		ll left=dfs(l,mid);
		ll right=dfs(mid+1,r);
//		cout << left << " " << right << " " << l << " " << r << endl;
		ans=min(ans,left+right);
	}
	return ans;
}
int main()
{
	scanf("%d%d%d%d",&n,&k,&A,&B);
	for(int i=0;i<k;i++) scanf("%d",&a[i]);
	sort(a,a+k);
	printf("%lld\n",dfs(1,1<<n));
	return 0;
}
