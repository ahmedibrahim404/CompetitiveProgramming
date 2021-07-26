#include <iostream>
using namespace std;
typedef pair<int, int> pi;
const int OO=1e9,MAX=2000+3;
int a, n, m;
int here[MAX];
bool is[MAX];
int dp[MAX][MAX];
//bool vis[MAX][MAX];
int solve(int i = 0, int umb = a+1)
{
    if(is[i] && umb == a+1 && !here[i]) return OO;

  if (i == a)return 0;
  int &ret = dp[i][umb];
  if (~ret)return ret;
  ret = 1e9;
  if (!is[i]) ret = solve(i+1, a+1);
  if (here[i])ret = min(ret, here[i] + solve(i+1, i));
  if (umb != a+1)ret = min(ret, here[umb] + solve(i+1, umb));
  return ret;
}


int x, y;
int main(){
    scanf("%d%d%d",&a,&n,&m);
    for(int i=0;i<MAX;i++){
        here[i]=OO;
        for(int j=0;j<MAX;j++) dp[i][j]=-1;
    }

    for(int i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        for(int j=x;j<y;j++) is[j]=1;
    }

    for(int i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        here[x]=min(here[x], y);
    }

    for(int i=0;i<MAX;i++) if(here[i]==OO) here[i]=0;
    int cost=solve(0, a+1);
    printf("%d\n", cost==OO?-1:cost);
//    build(0, a+1);
    return 0;
}
