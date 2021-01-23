#include<bits/stdc++.h>

using namespace std;
const int N=3e5+5;
typedef long long ll;

int main()
{
    int n,ans=1,ma=0;
    cin >> n;
    int m=n;
    for(int i=2;i*i<=n;i++)
    {
        int t=0;
        if(n%i==0)
        {
            ans*=i;
            while(n%i==0) n/=i,t++;
            ma=max(ma,t);
        }
    }
    ans*=n;
    if(ma) ma=ceil(log2(ma));
    int aa=ans;
    for(int i=0;i<ma;i++) aa*=aa;
    if(aa!=m) ma++;
    cout << ans << " " << ma << endl;
    return 0;
}
