#import<cstdio>
#import<cstring>
#import<algorithm>
int h[222222],minh=200001,maxh=0,n,k,hei,cost,ans;
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&hei);
		if(hei<minh) minh=hei;
		if(hei>maxh) maxh=hei;
		h[hei]++;
	}
	for(int i=maxh;i>minh;i--)
	{
		h[i]+=h[i+1];
		if(cost+h[i]>k) ans++,cost=0;
		cost+=h[i];
	}
	if(cost>0) ans++;
	printf("%d",ans);
}
