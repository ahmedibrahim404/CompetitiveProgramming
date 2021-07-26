#include<bits/stdc++.h>

using namespace std;

const int MAX=100+5;
int dp[MAX][MAX];
char s1[MAX], s2[MAX];
int n, m;

int solve(int i, int j){

    if(i == n) return m-j;
    if(j == m) return n-i;

    int &ret=dp[i][j];
    if(~ret) return ret;
    if(s1[i] == s2[j]) return ret=1+solve(i+1, j+1);
    return ret=min(1 + solve(i+1, j), 1 + solve(i, j+1));

}

void build(int i, int j){

    if(i == n){
        for(int x=j;x<m;x++) printf("%c", s2[x]);
        return;
    }

    if(j == m){
        for(int x=i;x<n;x++) printf("%c", s1[x]);
        return;
    }

    int ret=dp[i][j];

    if(s1[i] == s2[j] && 1 + solve(i+1, j+1) == ret){
        printf("%c", s1[i]);
        return build(i+1, j+1);
    }

    if(1 + solve(i+1, j) == ret){
        printf("%c", s1[i]);
        build(i+1, j);
    } else {
        printf("%c", s2[j]);
        build(i, j+1);
    }


}

int main(){
    while(scanf("%s%s", s1, s2) == 2){
        n=strlen(s1);m=strlen(s2);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) dp[i][j]=-1;
        solve(0, 0);
        build(0, 0);
        printf("\n");
    }
    return 0;
}
