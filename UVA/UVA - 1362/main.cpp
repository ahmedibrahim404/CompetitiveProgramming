#include <iostream>

using namespace std;
const int MAX=300+3, MOD=1e9;
string str;
int dp[MAX][MAX];
int N;


int solve(int st, int en){

    if(st==en) return 1;

    int &ret=dp[st][en];
    if(~ret) return ret%MOD;
    ret=0;
    if(str[st] != str[en]) return ret;
    for(int i=st+2;i<=en;i++){
        if(str[i]==str[st]){
            ret = (ret%MOD + (solve(st+1, i-1)%MOD) * (solve(i+1, en-1)%MOD))%MOD;
        }
    }

    return ret;

}


int main(){

    cin >> str;
    N=str.length();
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) dp[i][j]=-1;

    printf("%d\n", solve(0, N-1));


    return 0;
}
