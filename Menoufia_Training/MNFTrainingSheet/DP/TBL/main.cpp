#include <iostream>

using namespace std;
typedef long long ll;
const int COINS = 11;
const int MAX_COIN = 30000+1;

int coins[COINS] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
ll dp[11][MAX_COIN];

int main(){

    int a;
    cin >> a;
    for(int i=0;i<11;i++) dp[i][0]=1;


    for(int j=0;j<11;j++){
        for(int i=5;i<=30000;i+=5){
            if(j) dp[j][i] = dp[j-1][i];
            if(i-coins[j]>=0) dp[j][i] += dp[j][i-coins[j]];
        }
    }


    printf("%lld\n", dp[10][a]);

    return 0;
}
