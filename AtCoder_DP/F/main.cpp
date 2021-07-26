#include<bits/stdc++.h>
using namespace std;

char s1[3000+9], s2[3000+9];
int dp[3000][3000], nex[3000][3000], len1, len2;

int solve(int a=0, int b=0){
    if(a == len1 || b == len2) return 0;

    int &ret=dp[a][b];
    if(ret != -1) return ret;

    if(s1[a] == s2[b]){
        ret=1+solve(a+1, b+1);
        nex[a][b]=1;
        return ret;
    }


    ret = solve(a+1, b);
    nex[a][b]=2;

    if(solve(a, b+1) > ret)
        ret=solve(a, b+1), nex[a][b]=3;

    return ret;
}

int main(){
    scanf("%s %s", s1, s2);
    len1=strlen(s1), len2=strlen(s2);
    memset(dp, -1, sizeof(dp));
    int s=solve();

    int x=0, y=0;
    while(s){
        if(s1[x] == s2[y]) printf("%c", s1[x]), s--;
        if(nex[x][y] == 1) x++, y++;
        else if(nex[x][y] == 2) x++;
        else if(nex[x][y] == 3) y++;
    }

    return 0;
}
