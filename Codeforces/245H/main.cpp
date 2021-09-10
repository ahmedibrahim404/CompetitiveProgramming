#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
const int N=5e3+1;
string s;
int dp[N][N],dp2[N][N];
vector<int> idx[N];
bool pal(int i,int j)
{
    if(i>j) return 1;
    int &ret=dp[i][j];
    if(~ret) return ret;
    if(s[i]==s[j]) return ret=pal(i+1,j-1);
    else return ret=0;
}
int solve(int i,int j)
{
    if(i>j) return 0;
    int &ret=dp2[i][j];
    if(~ret) return ret;
    return ret=solve(i+1,j)+solve(i,j-1)-solve(i+1,j-1)+pal(i,j);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,q;
    memset(dp,-1,sizeof dp);
    memset(dp2,-1,sizeof dp2);
    cin>>s;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--;r--;
        cout<<solve(l,r)<<"\n";
    }
    return 0;
}
