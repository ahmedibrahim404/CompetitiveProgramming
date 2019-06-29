#include<bits/stdc++.h>
using namespace std;

struct wp{
	int b;
	int d;
};

wp a[100006],b[100006];
int n,v,ta,tb,pa,pb,t1,t2;
long long ans,tmp;
int cmp(wp x,wp y){
	return x.b>y.b;
}

int main()
{
	cin>>n>>v;
	for(int i=1;i<=n;i++){
		scanf(" %d %d",&t1,&t2);
		if(t1==1)
		a[++pa].b=t2,a[pa].d=i;
		else
		b[++pb].b=t2,b[pb].d=i;
	}
	sort(a+1,a+pa+1,cmp);
	sort(b+1,b+pb+1,cmp);
	for(int i=1;i<=pb;i++){
		if(v>=2) ans+=b[i].b,v-=2,tb=i;else break;
	}
	for(int i=1;i<=pa;i++){
		if(v>0) ans+=a[i].b,v-=1,ta=i;else break;
	}
	tmp=ans;
	while(tb>=1){
		if(ta>=pa) break;
		tmp-=b[tb].b;
		tmp+=a[ta+1].b+a[ta+2].b;
		if(tmp>ans){
			ans=tmp;
			if(ta+1==pa) ta++;else ta+=2;
			tb--;
		}
		else break;
	}
	cout<<ans<<endl;
	for(int i=1;i<=tb;i++) cout<<b[i].d<<" ";
	for(int i=1;i<=ta;i++) cout<<a[i].d<<" ";
	return 0;
}
