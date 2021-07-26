#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000+1;
ll MOD=(1<<31) - 1;
int n;
char ns[N][N];
ll dp[N][N];

int xs[] = {1, 0, -1, 0};
int ys[] = {0, 1, 0, -1};
int mx=4;

bool valid(int a, int b){
    return a >= 0 && b >= 0 && a < n && b < n && ns[a][b] != '#';
}

ll solve(int x, int y){
    if(x == n-1 && y == n-1) return 1LL;
    ll &ret=dp[x][y];
    if(~ret) return ret;
    ret=0;
    for(int i=0;i<mx;i++){
        if(valid(x+xs[i], y+ys[i])) ret = (ret + solve(x+xs[i], y+ys[i])%MOD)%MOD;
    }

    return ret;

}

int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> ns[i];
    memset(dp, -1, sizeof dp);
    ll a1 = solve(0, 0);
    mx=2;
    memset(dp, -1, sizeof dp);
    ll a2 = solve(0, 0);

    if(!a2){
        if(a1) cout << "THE GAME IS A LIE\n";
        else cout << "INCONCEIVABLE\n";
    } else cout << a2 << "\n";

    return 0;
}
