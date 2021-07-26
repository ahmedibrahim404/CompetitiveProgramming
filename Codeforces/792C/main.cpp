#include<bits/stdc++.h>
using namespace std;
typedef pair<int, string> pi;

const int MAX=1e5+3;
string str;
int dp[MAX][3], len;
bool took[MAX][3];
int solve(int cur=0, int mod=0){

    if(cur == len && mod == 0) return 0;
    else if(cur == len && mod != 0) return 1e9;

    int &ret=dp[cur][mod];
    if(ret != -1) return ret;
    ret=solve(cur+1, (mod+str[cur]-'0')%3);
    took[cur][mod]=0;

    int inc=1;
    if(cur+1 == len){
        int aat=cur;
        while(--aat){
            if(str[aat]-'0' == 0){
                inc++;
            } else break;
        }
    }
    int ret2=solve(cur+1, mod)+inc;
    if(ret2 < ret) ret=ret2, took[cur][mod]=1;

    return ret;

}

int main(){
    cin >> str;
    len=str.length();
    for(int i=0;i<MAX;i++) for(int j=0;j<3;j++) dp[i][j]=-1;
    for(int i=0;i<len/2;i++){
        char temp=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=temp;
    }

    int res=solve();
    if(res == len){
        if(str.find('0') < len) return printf("0"), 0;
        return printf("-1"), 0;
    }

    string ans="";
    int mod=0;
    for(int i=0;i<len;i++){
        if(took[i][mod]==0){
            ans += str[i];
            mod = (mod+str[i]-'0')%3;
        }
    }
    reverse(ans.begin(), ans.end());
    int idx=0, ll=ans.length();
    while(ans[idx]=='0'){idx++;}
    if(!(ans[idx])) return printf("0"), 0;
    for(int i=idx;i<ll;i++) cout << ans[i];

    return 0;
}
