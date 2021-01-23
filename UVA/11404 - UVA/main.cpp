#include<bits/stdc++.h>

using namespace std;
const int MAX=1000+3;

int dp[MAX][MAX];
string str;
int n;
int solve(int i, int j){
    if(i==j) return 1;
    if(i>j) return 0;

    int &ret=dp[i][j];
    if(~ret) return ret;
    ret=0;
    if(str[i]==str[j]) return ret=2+solve(i+1, j-1);
    ret=max(ret, solve(i+1, j));
    ret=max(ret, solve(i, j-1));

    return ret;
}

char add;
bool vis[MAX][MAX];
string ans[MAX][MAX];
string build(int i, int j){
    if(i==j){
        return str.substr(i, 1);
    }
    if(i>j) return "";

    int ret=dp[i][j];
    string &res=ans[i][j];
    if(vis[i][j]) return res;
    vis[i][j]=1;
    res="";
    if(str[i]==str[j]){
        res += str[i]+build(i+1, j-1);
        return res;
    }

    if(solve(i+1, j) != solve(i, j-1)){
        if(solve(i+1, j)==ret) res += build(i+1, j);
        else res +=build(i, j-1);
    } else {
        res += min(build(i+1, j), build(i, j-1));
    }

    return res;
}

int main(){
    while(cin >> str){
        memset(dp, -1, sizeof dp);
        memset(vis, 0, sizeof vis);
        n=str.length();
        int cost=solve(0, n-1);
        string str= build(0, n-1);
        cout << str;
        reverse(str.begin(), str.end());
        if(cost&1)str=str.substr(1);
        cout << str << endl;

    }
    return 0;
}
