#include<bits/stdc++.h>
using namespace std;
const int MAX=100+5;
int n;
char str2[MAX*MAX];
char str[MAX][MAX];
char target[] = "ICPCASIASG";
bool dp[MAX][MAX][11];
bool vis[MAX][MAX][11];

//int mv(int x, int y){
//    return n * x + y;
//}
//
//pair<int, int> gt(int x){
//    return {x/n, x - x/n * n};
//}


bool solve(int x, int y, int idx){
    if(idx==10) return 1;
    bool &ret=dp[x][y][idx];
    if(vis[x][y][idx]) return ret;
    vis[x][y][idx]=1;
    ret=0;
    for(int i=1;i<=2;i++){
        int j=3-i;
        for(int a=-1;a<2;a+=2){
            for(int b=-1;b<2;b+=2){
                if(str[x + a * i][y + b * j] == target[idx]) ret |= solve(x + a * i, y + b * j, idx+1);
            }
        }
    }
    return ret;
}

int main(){
    scanf("%d%s",&n,str2);
    int idx=0;
    memset(vis, 0, sizeof vis);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        str[i][j]=str2[idx++];
    }
    bool can=0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        if(str[i][j]=='I') can |= solve(i, j, 1);
    }
    printf(can?"YES\n":"NO\n");
    return 0;
}
