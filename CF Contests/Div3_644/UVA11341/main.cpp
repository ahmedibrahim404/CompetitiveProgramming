#include <iostream>

using namespace std;
int dp[30000+3][500+3], cnt[30000+3];
int n, d;

int l2ol(int l){
    return (l-d)+250;
}

int ol2l(int ol){
    return (ol-250)+d;
}
int mx;

int solve(int idx, int l){


    if(idx > mx) return 0;

    int &ret=dp[idx][l];
    if(~ret) return ret;
    int rl=ol2l(l);

    ret=0;
    if(idx+rl+1 <= mx) ret=max(ret, solve(idx+rl+1, (l+1)));
    if(rl != 1 && idx+rl-1 > 0 && idx+rl-1 <= mx) ret=max(ret, solve(idx+rl-1, (l-1)));
    if(idx+rl > 0 && idx+rl <= mx) ret=max(ret, solve(idx+rl, (l)));
    ret += cnt[idx];

    return ret;

}


int main(){
    int no;
    mx=0;
    for(int i=0;i<30000+3;i++) for(int j=0;j<500+3;j++) dp[i][j]=-1;
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;i++){
        scanf("%d",&no);
        mx=max(mx, no);
        cnt[no]++;
    }

    printf("%d\n", solve( d, l2ol(d) ) );

    return 0;
}
