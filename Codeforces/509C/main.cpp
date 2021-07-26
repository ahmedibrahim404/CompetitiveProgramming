#include <iostream>
#include <cstring>
using namespace std;
const int MAX=300+3;
int n, bs[MAX];
string pre;int len;
int dp[MAX][MAX][2][2];
bool is=0;
int solve(int idx, int rem, bool p1, bool p2){

    if(idx>40+len) return 1e8;

    if(!rem){
        if(idx>len){
            return 0;
        } else {
            if(p1 && p2){
                return len-idx;
            } else {
                return len-idx+1;
            }
        }
    }

    int &ret=dp[idx][rem][p1][p2];
    if(~ret) return ret;
    ret=1e8;

    int no=-1;
    if(idx<len) no=pre[idx]-'0';
    int mi=min(rem, 9);


    for(int i=(!idx?1:0);i<=mi;i++){
        if((i>=no) | p1){
            ret=min(ret, 1+solve(idx+1, rem-i, p1|(i>no), p2));
        } else {
            ret=min(ret, 1+solve(idx+1, rem-i, 0, 0));
        }
    }

    return ret;

}
string a;
void build(int idx, int rem, bool p1, bool p2){
    if(idx>40+len) return;

    if(!rem){
        if(idx>len){
            return;
        } else {
            if(p1 && p2){
                for(int i=0;i<len-idx;i++) a += "0";
            } else {
                for(int i=0;i<len-idx+1;i++) a += "0";
            }
        }
        return;
    }

    int ret=dp[idx][rem][p1][p2];

    int no=-1;
    if(idx<len) no=pre[idx]-'0';
    int mi=min(rem, 9);

    for(int i=0+!idx;i<=mi;i++){
        if(i>=no || p1){
            if(1+solve(idx+1, rem-i, p1|(i>no), p2) == ret){
                a += (i+'0');
                return build(idx+1, rem-i, p1|(i>no), p2);
            }
        } else {
            if(1+solve(idx+1, rem-i, 0, 0) == ret){
                a += (i+'0');
                return build(idx+1, rem-i, 0, 0);
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++) cin >> bs[i];

    pre="0";
    for(int i=0;i<n;i++){
        memset(dp, -1, sizeof dp);
        len=pre.length();
        if(i==2) is=1; else is=0;
        solve(0, bs[i], 0, 1);
        a="";
        build(0, bs[i], 0, 1);
        pre=a;
        cout << pre << endl;
    }

    return 0;
}
