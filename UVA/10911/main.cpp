#include<bits/stdc++.h>
using namespace std;

int xs[16+1], ys[16+1];
int N;

int setBit1(int num, int idx){
    return num | (1<<idx);
}

int getBit(int num, int idx){
    // idx => 0 based
    return ((num>>idx)&1);
}

double dis(int i, int j){
    return sqrt((xs[i]-xs[j])*(xs[i]-xs[j])+(ys[i]-ys[j])*(ys[i]-ys[j]));
}

double dp[(1<<16)+1];
double solve(int mask){

    bool is=1;
    for(int i=0;i<2*N;i++){
        is &= getBit(mask, i);
    }

    if(is) return 0;


    double &ret=dp[mask];
    if(ret != 0.0) return ret;
    ret=1e9;
    for(int i=0;i<2*N;i++){
        if(!getBit(mask, i)){
            for(int j=0;j<2*N;j++){
                if(i!=j && !getBit(mask, j)){
                    int nmask=mask;
                    nmask=setBit1(nmask, i);
                    nmask=setBit1(nmask, j);
                    ret=min(ret, dis(i, j)+solve(nmask));
                }
            }
        }
    }

    return ret;

}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    int cs=1;
    while(scanf("%d",&N)){
        if(!N) break;
        memset(dp, 0, sizeof dp);
        char str[50];
        for(int i=0;i<2*N;i++){
            scanf("%s%d%d",str,&xs[i],&ys[i]);
        }

        printf("Case %d: %.2lf\n", cs++, solve(0));
    }


    return 0;
}
