#include<bits/stdc++.h>
using namespace std;
long long nb,ns,nc,pb,ps,pc,t,cnt[100],l,r=2e12,mid;
string s;
int main()
{
    cin>>s>>nb>>ns>>nc>>pb>>ps>>pc>>t;
    for(int i=0;i<s.length();++i)
        ++cnt[s[i]];
    for(int i=1;i<=60;++i)
    {
        mid=(l+r)/2;
        if(max(0LL,cnt['B']*mid-nb)*pb+max(0LL,cnt['S']*mid-ns)*ps+max(0LL,cnt['C']*mid-nc)*pc<=t)
            l=mid;
        else
            r=mid;
    }
    cout<<l;
}
