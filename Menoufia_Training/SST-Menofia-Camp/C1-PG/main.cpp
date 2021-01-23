#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
const int MAX=1000+3;
int cols[1000+3];
int dp[MAX][2];
int solve(int idx, int pre){

    if(idx == m)return 0;

    int &ret=dp[idx][pre];
    if(ret != -1) return ret;
    ret=1e8;
    int took=0;
    bool c=0;
    for(int i=idx;i<idx+x;i++){
        if(i>=m) {c=1;break;}
        if(pre) took += (n-cols[i]);
        else took += cols[i];
    }

    if(!c) ret=min(solve(idx+x, 1-pre)+took, ret);

    for(int i=idx+x;i<idx+y;i++){
        if(pre) took += n-cols[i];
        else took += (cols[i]);
        if(i>=m) break;
        ret=min(solve(i+1, 1-pre)+took, ret);
    }


    return ret;

}
char str[MAX];
int main(){
    scanf("%d%d%d%d",&n,&m,&x,&y);
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++){
        scanf("%s",str);
        for(int j=0;j<m;j++){
            cols[j]+=(str[j]=='.');
        }
    }


    int s1=solve(0, 0);
    int s2=solve(0, 1);
    printf("%d", min(s1, s2));
    return 0;
}
