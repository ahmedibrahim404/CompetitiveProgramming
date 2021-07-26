#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
ll MOD=1000000007;
ll cumulative[100005];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    cumulative[0]=1;
    for(int i=1;i<=n;++i)
    {
        ll a;
        cin>>a;
        cumulative[i]=((a%MOD)*(cumulative[i-1]%MOD))%MOD;
    }
    ll sum=0;
     for(int i=1;i<=n/2+1;++i)
     {
         int j=i+n/2-1;
         sum+=(cumulative[j]%MOD)/(cumulative[i-1]%MOD);
         sum %=MOD;
     }
     cout<<sum<<endl;

    return 0;
}
