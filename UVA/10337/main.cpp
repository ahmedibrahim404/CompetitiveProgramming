#include <iostream>

using namespace std;

int T, N;
int temps[ 10 ][ 1000 ];
int dp[ 1000+9 ][ 10 ];

int getNX(int i, int j){
    return temps[ j ][ i ];
}

int solve(int idx, int level){

    if(level > 9 || idx > N || level < 0) return 1e9;
    if(idx == N) return (level==0)?0:1e9;


    int &ret = dp[idx][level];
    if(ret != -1) return ret;

    ret = min(
        solve(idx+1, level+1) + getNX(idx, level) + 60,
        solve(idx+1, level) + getNX(idx, level) + 30
      );

    ret = min(
        solve(idx+1, level-1) + getNX(idx, level) + 20,
        ret
      );

    return ret;

}

int main(){
    cin >> T;

    while(T--){

        for(int i=0;i<1000+9;i++) for(int j=0;j<10;j++) dp[i][j]=-1;

        cin >> N;
        N/=100;

        for(int i=9;i>=0;i--) for(int j=0;j<N;j++){
            cin >> temps[i][j];
            temps[i][j] *= -1;
        }

        cout << solve(0, 0) << endl;
        cout << endl;

    }



    return 0;
}
