#include <iostream>

using namespace std;
string str;
const int MAX=1e5+3;
int dp[MAX][3][2];int n;
bool took[MAX][3];
int sml;string stans;
int solve(int idx=0, int rem=0, bool is=0){

    if(idx==str.length()){
        if(!rem){
            return 0;
        }
        return 1e9;
    }

    int &ret=dp[idx][rem][is];
    if(~ret) return ret;
    ret=1e9;
    int no=str[idx]-'0';
    int ret1=1e9 ,ret2=1e9;
    if(!(!is && no==0)) ret1=solve(idx+1, (rem+no*10)%3, 1);
    ret2=1+solve(idx+1, rem, is);

    if(ret1<ret2){
        ret=ret1;
        took[idx][rem]=1;
    } else {
        ret=ret2;
    }

    return ret;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    sml=1e9;
    for(int i=0;i<MAX;i++) for(int j=0;j<3;j++) for(int k=0;k<2;k++) dp[i][j][k]=-1;

    cin >> str;
    n=str.length();
    int cost=solve(0, 0);

    if(cost==n){
        if(str.find('0')<n) cout << 0 << "\n";
        else cout << "-1\n";
        return 0;
    }


    int mod=0;
    string fin="";
    for(int i=0;i<n;i++){
        if(took[i][mod]){
            fin += str[i];
            mod = (mod + 10*(str[i]-'0'))%3;
        }
    }

    cout << fin << endl;


    return 0;
}
