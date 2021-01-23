#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1010;
int path[N][N],flag[N];
int n,m,u,v,s,t,ans;
int q[N],d1[N],d2[N];
void bfs(int S,int*dis){
	int l=0,r=1;
	for(int i=1;i<=n;i++)flag[i]=0;
	q[1]=S; dis[S]=0; flag[S]=1;
	while(l<r){
		int x=q[++l];
		for(int i=1;i<=n;i++)
			if(path[x][i]&&!flag[i]){
				dis[i]=dis[x]+1;
				flag[i]=1;
				q[++r]=i;
			}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	while(m--){
		scanf("%d%d",&u,&v);
		path[u][v]=path[v][u]=1;
	}
	bfs(s,d1);
	bfs(t,d2);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)
		if((i!=j)&&(!path[i][j])&&min(d1[i]+d2[j],d2[i]+d1[j])+1>=d1[t])
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}
