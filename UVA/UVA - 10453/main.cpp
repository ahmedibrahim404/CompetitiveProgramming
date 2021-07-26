#include<bits/stdc++.h>
using namespace std;
const int MAX=1000+1;
string str;
int n;
int dp[MAX][MAX];
bool vis[MAX][MAX];

int solve(int i=0, int j=n-1){

    if(i==j) return 0;
    if(i>j) return 0;

    int &ret=dp[i][j];
    if(~ret) return ret;
    ret=1e9;
    if(str[i]==str[j]) return ret=solve(i+1, j-1);

    ret=min(ret, solve(i+1, j)+1);
    ret=min(ret, solve(i, j-1)+1);

    return ret;
}

string ans;
char extra;
bool is=0;
void build(int i=0, int j=n-1){

    if(i==j){
        is=1;
        extra = str[i];
        return;
    }
    if(i>j) return;

    int ret=dp[i][j];
    if(vis[i][j]) return;
    vis[i][j]=1;
    if(str[i]==str[j]){
        ans += str[i];
        return build(i+1, j-1);
    }

    if(ret==solve(i+1, j)+1){
        ans += str[i];
        build(i+1, j);
        return;
    }

    if(ret==solve(i, j-1)+1){
        ans += str[j];
        build(i, j-1);
        return;
    }

}

int main(){
    while(cin >> str){
        ans="", is=0;
        n=str.length();
        memset(dp, -1, sizeof dp);
        memset(vis, 0, sizeof vis);
        int cost=solve();
        build();
        cout << cost << " ";
        cout << ans;
        if(is) cout << extra;
        reverse(ans.begin(), ans.end());
        cout << ans;
        cout << "\n";

    }

    return 0;
}
