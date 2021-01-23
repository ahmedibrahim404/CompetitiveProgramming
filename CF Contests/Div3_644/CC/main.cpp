#include <iostream>

using namespace std;

int n, s, k;
char str[51];
int ns[51], dp[51][2500+3][2];
int solve(int idx=0, int sum=0, bool ate=0){
    if(sum >= k){

        return 0;
    }

    int &ret=dp[idx][sum][ate];
    if(~ret) return ret;
    ret=2e9;
    for(int i=0;i<n;i++){
        if(i==idx) continue;
        if(ate&&(ns[i]<=ns[idx]||str[i]==str[idx])) continue;
        int dis=i>idx?i-idx:idx-i;
        ret=min(ret, solve(i, sum+ns[i], 1)+dis);
    }

    return ret;

}


int main(){
    scanf("%d%d%d",&n,&s,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&ns[i]);
    }
    for(int i=0;i<51;i++) for(int j=0;j<2500;j++) for(int k=0;k<2;k++) dp[i][j][k]=-1;

    scanf("%s", &str);
    s--;
    int res=min(solve(s, ns[s], 1), solve(s, 0, 0));
    printf("%d\n", res>=2e9?-1:res);

    return 0;
}
