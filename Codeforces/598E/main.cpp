#include <iostream>
using namespace std;
typedef long long ll;
int t, n, m, k;
ll dp[31][31][51];

ll solve(int x, int y, int rem){

    if(!rem) return 0;
    if(x*y==rem) return 0;
    if(!x||!y||x*y<rem) return 1e9;


    ll &ret=dp[x][y][rem];
    if(~ret) return ret;

    ret=1e9;

    for(int i=1;i<=x;i++){
        for(int j=0;j<=rem;j++){
            ret=min(ret, y*y+solve(i, y, j)+solve(x-i, y, rem-j));
        }
    }

    for(int i=1;i<=y;i++){
        for(int j=0;j<=rem;j++){
            ret=min(ret, x*x+solve(x, i, j)+solve(x, y-i, rem-j));
        }
    }


    return ret;
}


int main(){
    scanf("%d",&t);
    for(int i=0;i<31;i++) for(int j=0;j<31;j++) for(int k=0;k<51;k++) dp[i][j][k]=-1;
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        printf("%lld\n", solve(n, m, k));
    }
    return 0;
}
