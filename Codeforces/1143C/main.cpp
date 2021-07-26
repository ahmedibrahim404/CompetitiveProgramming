#include<bits/stdc++.h>
using namespace std;
int p[100007],c[100007],s[100007],n,can;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d%d",&p[i],&c[i]),s[i]=c[i];
	for (int i=1;i<=n;i++)if ( p[i]>0 )s[ p[i] ] = s[ p[i] ] && c[i];
	for (int i=1;i<=n;i++)if (s[i])printf("%d ",i),can=1;
	if (!can)printf("-1");
}
