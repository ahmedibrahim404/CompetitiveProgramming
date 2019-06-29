#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,l,r,a;
long long c[5];
const int mod=1e9+7;
const int maxn=2e5+5;
long long dp[maxn][3];
int main(){
	scanf("%d%d%d",&n,&l,&r);
	a=(r-l)/3;
	r-=a*3;
	c[0]=c[1]=c[2]=a;

	for (int i=l;i<=r;i++)
		c[i%3]++;
	dp[0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=2;j++){
			for (int k=0;k<3;k++){
				dp[i][j]=(dp[i][j]+dp[i-1][k]*c[((j+3)-k)%3]%mod)%mod;
			}
		}
	}
	printf("%lld",dp[n][0]);
}
