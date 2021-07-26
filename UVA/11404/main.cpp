#include<bits/stdc++.h>
using namespace std;
const int MAX=1e3+1;
int n, dp[MAX][MAX];
string str;
int solve(int l=0, int r=n-1){

    if(l>r) return 0;

    int &ret=dp[l][r];
    if(~ret) return ret;

    if(str[l]==str[r]){
        return ret=(l==r?1:2)+solve(l+1, r-1);
    }
    ret=max(solve(l+1, r), solve(l, r-1));

    return ret;

}


string built[MAX][MAX];
bool visit[MAX][MAX];
string build(int l=0, int r=n-1){

    if(l>r) return "";

    string &ans=built[l][r];
    if(visit[l][r]) return ans;
    ans="";
    visit[l][r]=1;

    if(str[l]==str[r]){
        ans += str[l]+build(l+1, r-1);
        return ans;
    }

    int ret1=solve(l+1, r);
    int ret2=solve(l, r-1);

    int ret=solve(l, r);

    if(ret==ret1 && ret != ret2){

        ans += build(l+1, r);

    } else if(ret==ret2 && ret != ret1) {

        ans += build(l, r-1);

    } else {

        string a=build(l, r-1), b=build(l+1, r);
        if(a>b) ans += b;
        else ans += a;

    }


    return ans;

}


int main(){
    while(cin>>str){
        n=str.length();
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j]=-1, visit[i][j]=0;
        int cost=solve(0, n-1);
        string ans=build(0, n-1);
        cout << ans;
        reverse(ans.begin(), ans.end());
        cout<<ans.substr(cost&1);
        cout<<endl;

}
    return 0;
}
