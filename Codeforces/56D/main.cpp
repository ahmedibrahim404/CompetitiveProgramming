#include<bits/stdc++.h>
using namespace std;
const int OO =1e9;
const int MAX=2000+3;
int dp[MAX][MAX];
int n, m;
string a, b;
int del=0;
int solve(int i, int j){

    if(i >= n && j >= m) return 0;
    int &ret=dp[i][j];
    if(~ret) return ret;
    ret=OO;

    if(i<n && j<m && a[i]==b[j]){
        return ret=solve(i+1, j+1);
    }

    // delete
    if(i<n){
        del++;
        ret=min(ret, 1+solve(i+1, j));
        del--;
    }

    // add
    if(j<m){
        del--;
        ret=min(ret, 1+solve(i, j+1));
        del++;
    }

    // replace i to j
    if(i<n && j<m){
        ret=min(ret, 1+solve(i+1, j+1));
    }

    return ret;

}

void build(int i, int j){

    if(i>=n && j>=m) return;
    int ret=dp[i][j];

    if(i<n && j<m && a[i]==b[j]){
        return build(i+1, j+1);
    }

    if(i<n && j<m && 1+solve(i+1, j+1) == ret){
        cout << "REPLACE " << i+1-del << " " << b[j] << endl;
        build(i+1, j+1);
        return;
    }

    // del i
    if(i<n && 1+solve(i+1, j) == ret){
        cout << "DELETE " << i+1-del << endl;
        del++;
        build(i+1, j);
        del--;
        return;
    }

    if(j<m && 1+solve(i, j+1) == ret){
        cout << "INSERT " << i+1-del << " " << b[j] <<endl;
        del--;
        build(i, j+1);
        del++;
        return;
    }


    return;


}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin >> a >> b;
    n=a.length(), m=b.length();
    del=0;
    cout << solve(0, 0) << endl;
    build(0, 0);
    return 0;
}
