#include<bits/stdc++.h>
using namespace std;

int v1, v2;
int t, d;
int dp[1100+3][100+3];

int solve(int speed=0, int sec=0){
    if(sec==t-1) return speed==v2?0:-1e9;

    int &ret=dp[speed][sec];
    if(~ret) return ret;
    ret=speed+solve(speed, sec+1);
    for(int i=1;i<=d;i++){
        ret=max(ret, (speed+i)+solve(speed+i, sec+1));
        if(speed-i>0) ret=max(ret, (speed-i)+solve(speed-i, sec+1));
    }

    return ret;

}

int main(){

    scanf("%d%d%d%d",&v1,&v2,&t,&d);
    for(int i=0;i<1100+3;i++) for(int j=0;j<100+3;j++) dp[i][j]=-1;
    printf("%d\n", v1+solve(v1, 0));
    return 0;
}
