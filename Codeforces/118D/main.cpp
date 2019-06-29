//#include<bits/stdc++.h>
//using namespace std;
//
//typedef long long ll;
//
//int n1, n2, k1, k2;
//unsigned int MOD=100000000;
//int dpe[109][109][19][19];
//ll cnt(int la, int lb, int ca, int cb){
//
//
//    if(la == 0 && lb == 0) return 1;
//    if(dpe[la][lb][ca][cb]!=-1) return dpe[la][lb][ca][cb];
//
//    ll ans=0;
//
//    if(ca + 1 <= k1 && la) ans += cnt(la-1, lb, ca+1, 0) % MOD;
//    if(cb + 1 <= k2 && lb) ans += cnt(la, lb-1, 0, cb+1) % MOD;
//
//    return dpe[la][lb][ca][cb] = ans % MOD;
//
//}
//
//int main(){
//    scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
//    memset(dpe,-1,sizeof dpe);
//    printf("%lld", cnt(n1, n2, 0, 0));
//
//    return 0;
//}

#include<stdio.h>
#define N 101
#define M 100000000
int min(int a,int b);
using namespace std;
int main()
{
	int a,g,ka,kg,D[N][N],i,j,ii,jj,s3;

	for (i=0; i<N; i++)
		for (j=0; j<N; j++) D[i][j]=0;

	scanf("%d %d %d %d",&a,&g,&ka,&kg);

	for (i=0; i<=ka; i++) D[i][0]=1;
	for (i=0; i<=kg; i++) D[0][i]=1;
	D[0][0]=2;

	for (i=1; i<=a; i++)
	{
		for (j=1; j<=g; j++)
		{
			s3=0;
			for (ii=1; ii<=min(ka,i); ii++)
			{
				for (jj=1; jj<=min(kg,j); jj++)
				{
					s3=(s3+D[i-ii][j-jj])%M;
				}
			}
			D[i][j]=s3;
		}
	}
	printf("%d",D[a][g]);
return 0;
}

int min(int a,int b)
{
	if (a>b)	 return b;
	return a;
}
