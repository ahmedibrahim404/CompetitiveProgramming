#include <iostream>

using namespace std;
const int MAX=1000+5;
string s1, s2;
int dp[MAX][MAX];
int n, m;
int solve(int i, int j){

    if(i == n) return 30 * (m-j);
    if(j == m) return 15 * (n-i);

    int &ret=dp[i][j];
    if(~ret) return ret;

    if(s1[i] == s2[j]) return ret=solve(i+1, j+1);
    return ret=min( 15 + solve(i+1, j), 30 + solve(i, j+1) );
}

int main(){
    while(cin >> s1 && s1 != "#"){
        cin >> s2;
        n=s1.length();m=s2.length();
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) dp[i][j]=-1;
        cout << solve(0, 0) << "\n";
    }
    return 0;
}
