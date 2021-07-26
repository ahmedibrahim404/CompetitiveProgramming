#include <cstdio>
#include <algorithm>
#define ll long long
#define N 510
using namespace std;

ll Ans[N],g[N][N];
int p[N],n;
bool vis[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)scanf("%I64d",&g[i][j]);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int i=n,now;i>=1;--i){
		vis[now=p[i]]=1;
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				g[j][k]=min(g[j][k],g[j][now]+g[now][k]);
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				if(vis[j]&&vis[k]) Ans[i]+=g[j][k];
	}
	for(int i=1;i<=n;++i) printf("%I64d ",Ans[i]);
	return 0;
}
