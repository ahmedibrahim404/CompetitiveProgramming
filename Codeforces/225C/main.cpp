#include<bits/stdc++.h>
using namespace std;

int n,m,x,y;
char str[1000+3];
int ns[1000+3];
int dp[1000+1][1000+1][2];

int solve(int idx=0, int st=0, int ty=0){

    if(idx==m-1){
        if(idx-st+1>=x) return abs(n*ty-ns[idx]);
        return 1e8;
    }

    int&ret=dp[idx][st][ty];

    if(~ret) return ret;

    if(idx-st+1==y){
        //enough
        ret = abs(n*ty-ns[idx])+solve(idx+1, idx+1, 1-ty);
        return ret;
    }

    if(idx-st+1<x){
        //more
        ret= abs(n*ty-ns[idx])+solve(idx+1, st, ty);
        return ret;
    }


    ret=abs(n*ty-ns[idx])+solve(idx+1, st, ty);
    ret=min(ret, abs(n*ty-ns[idx])+solve(idx+1, idx+1, 1-ty));

    return ret;


}


int main(){
    scanf("%d%d%d%d",&n,&m,&x,&y);

    memset(dp, -1, sizeof(dp));

    for(int i=0;i<n;i++){
        scanf("%s", str);
        for(int j=0;j<m;j++){
            ns[j]+=(str[j]=='#');
        }
    }

    printf("%d\n", min(solve(0,0,0), solve(0,0,1)));

    return 0;
}
