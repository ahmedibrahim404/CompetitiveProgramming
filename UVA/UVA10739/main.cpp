#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;string str;

ll dp[1000+3][1000+3];

ll solve(int i, int j){

    if(i>=j) return 0;
    ll&ret=dp[i][j];
    if(~ret) return ret;

    if(str[i]==str[j]) return ret=solve(i+1, j-1);

    ret=solve(i+1, j)+1;
    ret=min(ret, 1+solve(i, j-1));
    ret=min(ret, 1+solve(i+1, j-1));

    return ret;

}

int main(){
    cin >> t;
    int te=0;
    while(t--){
        cin >> str;
        for(int i=0;i<1000+1;i++) for(int j=0;j<1000+1;j++) dp[i][j]=-1;
        cout << "Case "<<++te<<": " << solve(0, str.length()-1) << endl;
    }

    return 0;
}
