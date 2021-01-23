#include <iostream>

using namespace std;
typedef long long ll;
int t, N, a, b, c, tot;
ll dp[150][160][60];

ll solve(int idx=0, int p5=0, int p10=0){

    if(idx==N) return 0;

    ll &ret=dp[idx][p5][p10];
    if(~ret) return ret;

    ret=1e18;
    int p1=tot-idx*8-p5*5-p10*10;
    if(p1>=8)ret=min(ret, 8+solve(idx+1, p5, p10));
    if(p5>=1&&p1>=3) ret=min(ret, 4+solve(idx+1,p5-1, p10));
    if(p1>=3&&p10>=1) ret=min(ret, 4+solve(idx+1, p5+1, p10-1));
    if(p5>=2) ret=min(ret, 2+solve(idx+1, p5-2, p10));
    if(p10) ret=min(ret, 1+solve(idx+1, p5, p10-1));

    return ret;

}


int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&N,&a,&b,&c);
        tot=a+b*5+c*10;
        for(int i=0;i<N;i++)for(int k=0;k<160;k++) for(int l=0;l<60;l++) dp[i][k][l]=-1;
        printf("%lld\n", solve(0,b, c));
    }


    return 0;
}
