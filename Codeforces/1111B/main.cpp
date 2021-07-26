#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,k,i,m,a[100005];
double ans=0;
bool cmp(int a,int b){return a>b;}
int main()
{
	scanf("%lld%lld%lld",&n,&k,&m);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		a[i]+=a[i-1];
		if(m<n-i)continue;
		ans=max(ans,(double)(a[i]+min(k*i,m-(n-i)))/(double)i);
	}
	printf("%.15f\n",ans);
	return 0;
}
