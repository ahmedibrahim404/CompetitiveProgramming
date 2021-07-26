#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX=31;
ll dp[MAX][1<<3];

int getBit(int mask, int idx){
    return (mask>>idx)&1;
}

int setBit(int mask, int idx){
    return mask | (1<<idx);
}

int n;

ll solve(int idx=0, int mask=0){

//    cout << idx << " " << mask << "\n";

    if(idx==n) return 1;

    int cmask=mask;
    ll &ret=dp[idx][mask];
    if(~ret) return ret;
    ret=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<2;k++){
                if(i == 1 && idx == n-1) continue;
                if(j == 1 && idx == n-1) continue;
                if(k == 1 && idx == n-1) continue;

                // 0 => NO THING
                int curmask=mask, nxtmask=0;
                if(i == 1){
                    if(!getBit(curmask, 0)){
                        curmask=setBit(curmask, 0);
                        nxtmask=setBit(nxtmask, 0);
                    } else continue;
                } else if(i == 2){
                    if(!getBit(curmask, 0) && !getBit(curmask, 1)){
                        curmask=setBit(curmask, 0);
                        curmask=setBit(curmask, 1);
                    } else continue;
                }

                if(j == 1){
                    if(!getBit(curmask, 1)){
                        curmask=setBit(curmask, 1);
                        nxtmask=setBit(nxtmask, 1);
                    } else continue;
                } else if(j == 2){
                    if(!getBit(curmask, 1) && !getBit(curmask, 2)){
                        curmask=setBit(curmask, 1);
                        curmask=setBit(curmask, 2);
                    } else continue;
                }

                if(k == 1){
                    if(!getBit(curmask, 2)){
                        curmask=setBit(curmask, 2);
                        nxtmask=setBit(nxtmask, 2);
                    } else continue;
                }

                if(curmask==7){
                    if(nxtmask == 7) ret += solve(idx+2, 0);
                    else ret += solve(idx+1, nxtmask);
                }


            }
        }
    }

    return ret;


}

int main(){
    while(scanf("%d",&n) == 1 && ~n){
        memset(dp, -1, sizeof dp);
        printf("%lld\n", solve(0, 0));

    }
    return 0;
}
