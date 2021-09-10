#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 205, M = 5e4 + 9;

int n, k, t[N], f[N];
int dp[N][6000];

int main(){

    cin >> n >> k;
    for(int i = 0;i < n;i++){
        ll x;  cin >> x;

        while(x % 2 == 0){
            t[i]++; x /= 2;
        }

        while(x % 5 == 0){
            f[i]++; x /= 5;
        }

    }

    memset(dp, -1, sizeof dp);

    dp[k][0] = 0;
    int ans = 0;
    for(int i = 0;i < n;i++){
        for(int rem = 1;rem <= k;rem++){
            for(int fives = 0;fives < 6000;fives++){
                if(dp[rem][fives] != -1){
                    int twos = dp[rem][fives];
                    int &curr = dp[rem - 1][fives + f[i]];
                    curr = max(curr, t[i] + twos);
                    ans = max(ans, min(fives + f[i], curr));
                }
            }
        }
    }

    cout << ans;
}
